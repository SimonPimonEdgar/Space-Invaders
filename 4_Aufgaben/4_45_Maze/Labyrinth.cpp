#include "Labyrinth.h"
#include <iostream>

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    MazeCell* currentCell = start;
    bool wand = false;
    bool potion = false;
    bool spellbook = false;
    for (const char& direction : moves) {
        if (direction == 'N' && currentCell->north != nullptr) {
            currentCell = currentCell->north;
        } else if (direction == 'S' && currentCell->south != nullptr) {
            currentCell = currentCell->south;
        } else if (direction == 'E' && currentCell->east != nullptr) {
            currentCell = currentCell->east;
        } else if (direction == 'W' && currentCell->west != nullptr) {
            currentCell = currentCell->west;
        } else {
            std::cout << "Not possible!" << std::endl;
            return false;
        }

        //std::cout << direction << std::endl;
        switch (currentCell->whatsHere) {
            case Item::POTION:
                std::cout << "Found POTION" << std::endl;
                potion = true;
                break;
            case Item::SPELLBOOK:
                std::cout << "Found SPELLBOOK" << std::endl;
                spellbook = true;
                break;
            case Item::WAND:
                std::cout << "Found WAND" << std::endl;
                wand = true;
                break;
            default:
                // Do nothing for other cases
                break;
        }
    }
    if (potion && spellbook && wand) {
        return true;
    } else {
        return false;
    }
}
