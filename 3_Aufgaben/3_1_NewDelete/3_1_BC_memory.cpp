#include <iostream>
#include <ctime>

int main() {
    // Fuer den Vergleich: wir erzeugen den Point NUM-mal hintereinander.
    int NUM = 10000000;
    std::clock_t start = std::clock();
    for (int i = 0;i<NUM;++i){
        // TODO: Einfaches erzeugen einer Variablen des Typ points.
    }
    std::clock_t dt = std::clock() - start;    
    std::cout << "Stack Time " << float(dt)/CLOCKS_PER_SEC << " sec\n";

    start = std::clock(); 
    // TODO: Analog zu oben sollen sie eine Schleife aufsetzen und darin
    // explizit fuer einen Point Speicher reservieren (und dann wieder freigeben).
    dt = std::clock() - start;
    std::cout << "Heap Time " << float(dt)/CLOCKS_PER_SEC << " sec\n"; 
}