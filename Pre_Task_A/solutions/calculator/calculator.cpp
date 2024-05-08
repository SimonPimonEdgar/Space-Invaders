#include <stdlib.h>
#include <iostream>

int main(int argc, const char* argv[])
{
    if (argc < 3)
    {
        std::cout << "Zu wenige Parameter" << std::endl;
        return 1;
    }

        // argc enthält die Anzahl der Elemente in argv
        // argv enthält als erstes Element den Pfad der ausgeführten Datei

        // operation enthält die Operation als einzelnes Zeichen
    char operation = argv[1][0];

    int numOperands = argc - 2;

        // operands ist ein Array mit den Operanden als ganze Zahlen
    int operands[numOperands];
    for (int i = 0; i < numOperands; ++i)
        operands[i] = atoi(argv[i + 2]);

    int value = operands[0];
    for (int i = 1; i < numOperands; ++i)
    {
        switch (operation)
        {
            case '+':
                value += operands[i];
                break;
            case '-':
                value -= operands[i];
                break;
            case '*':
                value *= operands[i];
                break;
            case '/':
                value /= operands[i];
                break;
        }
    }

    std::cout << value << std::endl;
    return 0;
}