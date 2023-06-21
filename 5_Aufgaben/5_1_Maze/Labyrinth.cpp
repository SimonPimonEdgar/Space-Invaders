#include "Labyrinth.h"
#include <iostream>

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    MazeCell* currentCell = start;
    // ToDo
    // Durchlaufen der als String gegebenen Sequenz - 
    //    nutzen einer for-Schleife (for (const char& direction : moves) { ...})
    //    - dabei fuer jeden Char einzeln durchgehen
    //      1) Richtung vorhanden?
    //      2) liegt hier ein Objekt
    // Merken, welche Objekte gefunden wurden.
    // Und nachher ein return true oder false zurueck geben.

    // Bsp fuer merken, ob "wand" schon gefunden wurde:
    bool wand = false;

    // Zu implementieren: Schleife, die den Richtunganweisungen in moves folgt

    // Testen, ob "wand" aktuell vorhanden
    // Umsetzen fuer andere Objekte
    switch (currentCell->whatsHere) {
        case Item::WAND:
            std::cout << "Found WAND" << std::endl;
            wand = true;
            break;
        default:
            // Do nothing for other cases
            break;
    }

    // Rueckgabe abhaengig davon, ob alle Objekte gefunden wurden
    // Hier nur fuer "wand" als Beispiel
    if (wand) {
        return true;
    } else {
        return false;
    }
}
