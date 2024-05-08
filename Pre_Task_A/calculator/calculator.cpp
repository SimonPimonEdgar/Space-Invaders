#include <stdlib.h>
#include <iostream>

int main(int argc, const char* argv[])
{
        // argc enthält die Anzahl der Elemente in argv
        // argv enthält als erstes Element den Pfad der ausgeführten Datei

        // operation enthält die Operation als einzelnes Zeichen
    char operation = argv[1][0];

    int numOperands = argc - 2;

    // operands ist ein Array mit den Operanden als ganze Zahlen
    int operands[numOperands];
    for (int i = 0; i < numOperands; ++i)
        operands[i] = atoi(argv[i + 2]);

        // ToDo: Implement the simple calculator program ...
}