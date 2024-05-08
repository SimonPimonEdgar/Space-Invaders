#include "eliza.h"

int main(int argc, const char * argv[])
{
    elizascript::script s;

    std::stringstream ss(elizascript::CACM_1966_01_DOCTOR_script);
    elizascript::read<std::stringstream>(ss, s);

    //elizalogic::null_tracer notrace;
    //elizalogic::string_tracer trace;
    //elizalogic::pre_tracer pretrace;

    elizalogic::eliza eliza(s.rules, s.mem_rule);
    //eliza.set_tracer(&trace);

    writeln(join(s.hello_message));
    std::cout << std::endl;
    std::string userinput;
    std::getline(std::cin, userinput);
    writeln(eliza.response(userinput));

    std::cout << std::endl;
    std::getline(std::cin, userinput);
    writeln(eliza.response(userinput));
}

