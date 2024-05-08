/*  This is a recreation of Joseph Weizenbaum's 1966 ELIZA. The code was
    written from scratch originally using only the description in the
    Weizenbaum's paper on page 36 of the January 1966 edition of
    Communications of the ACM as a guide.

    If given the same S-expression-like script from the appendix of that
    paper, and given the same prompt text, the conversation it generates
    is identical to the conversation shown in the paper.

    I made this for my amusement and hereby place it in the public domain
    or, if you prefer, I release it under either CC0 1.0 Universal or the
    MIT License.
    
    Anthony Hay, 2021, Devon, UK


    Update: In April 2021 Jeff Shrager obtained a listing of ELIZA from
    Weizenbaum's MIT archive. In May 2021 he got permission from
    Weizenbaum's estate to open source the code under CC0 1.0. Seeing
    his original code clarified some behavior that was not fully
    documented in the CACM paper. (Although the listing was not dated
    and appears to differ from the functionality described in the CACM
    paper.) I made changes to this code to reflect what I learned. These
    changes are documented in the code.
    Anthony Hay, 2022, Devon, UK

    Update: In April 2022 Jeff Shrager located the source code to SLIP,
    including the HASH function. I made hash used in this code use the
    same algorithm.

    Note: In the code below there are occasional references to
    Joseph Weizenbaum's 1966 CACM article. A reference like
    [page X (Y)] refers to paragraph Y on page X of that publication.
*/

/* 
    CHANGE LOG:
    It was originally a single cpp file including the main which has now been adapted into a selfcontained 
    header file and the main moved to an external file.
    
*/


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <ctime>
#include <cassert>
#include <vector>
#include <memory>
#include <map>
#include <algorithm>
#include <deque>
#include <cctype>
#include <thread>
#include <array>
#include <cstdint>

#include "eliza.h"

int main(int argc, const char * argv[])
{
    try {
        bool showscript, nobanner, notty, help, traceauto = false;
        std::string script_filename;
        if (!parse_cmdline(argc, argv, showscript, nobanner, notty, help, script_filename) || help) {
            (help ? std::cout : std::cerr)
                << "Usage: ELIZA [options] [<filename>]\n"
                << "\n"
                << "  " << pad(as_option("nobanner"))   << "don't display startup banner\n"
                << "  " << pad(as_option("notty"))      << "don't print like it's 1966 (at 15 characters per second)\n"
                << "  " << pad(as_option("showscript")) << "print Weizenbaum's 1966 DOCTOR script\n"
                << "  " << pad("")                      << "e.g. ELIZA " << as_option("showscript") << " > script.txt\n"
                << "  " << pad("<filename>")            << "use named script file instead of built-in DOCTOR script\n"
                << "  " << pad("")                      << "e.g. ELIZA script.txt\n"
                << "\n"
                << "In a conversation with ELIZA, these inputs have special meaning:\n"
                << "  <blank line>    quit\n"
                << "  *               display trace of most recent exchange\n"
                << "  *traceoff       turn off tracing\n"
                << "  *traceon        turn on tracing; enter '*' after any excahnge to see trace\n"
                << "  *traceauto      turn on tracing; trace shown after every exchange\n"
                << "  *tracepre       show input sentence prior to applying transformation\n"
                << "                  (watch the operation of Turing machines)\n";
            return help ? EXIT_SUCCESS : EXIT_FAILURE;
        }

        if (showscript) {
            // just output Weizenbaum's DOCTOR script
            std::cout << elizascript::CACM_1966_01_DOCTOR_script;
            return EXIT_SUCCESS;
        }

        if (!nobanner) {
            std::cout <<
                "-----------------------------------------------------------------\n"
                "      ELIZA -- A Computer Program for the Study of Natural\n"
                "         Language Communication Between Man and Machine\n"
                "DOCTOR script by Joseph Weizenbaum, 1966  (CC0 1.0) Public Domain\n"
                "ELIZA implementation by Anthony Hay, 2022 (CC0 1.0) Public Domain\n"
                "-----------------------------------------------------------------\n"
                    << "ELIZA " << as_option("help") << " for usage.\n"
                    << "Enter a blank line to quit.\n";
        }

        //unpublished_script_tests::unpublished_script_tests();
        RUN_TESTS(); // run all the tests defined with DEF_TEST_FUNC

        elizascript::script s;
        if (script_filename.empty()) {
            // use default 'internal' 1966 CACM published script
            std::cout << (nobanner ? "\n\n"
                : "Using Weizenbaum's 1966 DOCTOR script (built-in).\n\n\n");
            std::stringstream ss(elizascript::CACM_1966_01_DOCTOR_script);
            elizascript::read<std::stringstream>(ss, s);
        }
        else {
            // use the named script file
            std::ifstream script_file(script_filename);
            if (!script_file.is_open()) {
                std::cerr << argv[0] << ": failed to open script file '"
                          << script_filename << "'\n";
                return EXIT_FAILURE;
            }
            if (nobanner)
                std::cout << "\n\n";
            else
                std::cout << "Using script file '" << script_filename << "'\n\n\n";
            elizascript::read<std::ifstream>(script_file, s);
        }

        elizalogic::null_tracer notrace;
        elizalogic::string_tracer trace;
        elizalogic::pre_tracer pretrace;

        elizalogic::eliza eliza(s.rules, s.mem_rule);
        eliza.set_tracer(&trace);

        auto print = [&](const std::string & s) {
            if (notty)
                std::cout << s << std::endl;
            else
                writeln(s);
        };

        print(join(s.hello_message));
        for (;;) {
            std::cout << std::endl;
            std::string userinput;
            std::getline(std::cin, userinput);

            if (userinput.empty())
                break;
            else if (userinput == "*") {
                std::cout << trace.text();
                continue;
            }
            else if (to_upper(userinput) == "*TRACEON") {
                eliza.set_tracer(&trace);
                traceauto = false;
                std::cout << "tracing enabled; enter '*' after any excahnge to see trace\n";
                continue;
            }
            else if (to_upper(userinput) == "*TRACEAUTO") {
                eliza.set_tracer(&trace);
                traceauto = true;
                std::cout << "tracing enabled\n";
                continue;
            }
            else if (to_upper(userinput) == "*TRACEOFF") {
                eliza.set_tracer(&notrace);
                trace.clear();
                traceauto = false;
                std::cout << "tracing disabled\n";
                continue;
            }
            else if (to_upper(userinput) == "*TRACEPRE") {
                eliza.set_tracer(&pretrace);
                trace.clear();
                traceauto = false;
                std::cout << "tracing PRE enabled\n";
                continue;
            }

            print(eliza.response(userinput));

            if (traceauto)
                std::cout << trace.text();
        }
    }
    catch (const std::exception & e) {
        std::cerr << "exception: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "exception" << std::endl;
        return EXIT_FAILURE;
    }
}

// (The goal was to make only a minimum viable accurate simulation
// of the original 1966 ELIZA rather than a polished product.)
