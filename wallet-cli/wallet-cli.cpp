#include <iostream>
#include <cstdlib>
#include "../common/include/Core.h"
#include "include/CommandHandler.h"

using namespace std;
using namespace NosoCore;

void mainMenu()
{
    string input;

    cout << "wallet-cli: ";

    while (true)
    {
        // Читання введеного рядка
        getline(std::cin, input);

        // Перевірка умови виходу
        if (input == "exit")
        {
            cout << "wallet-cli has completed its work." << endl;
            exit(1);
            break;
        }

        // Обробка введеної команди
        CommandHandler::processCommand(input);
    }
}




void headMainApp()
{
    cout << "Launching cli-wallet..." << endl;
    bool isValidFileStructure = checkStructureCore();

    if (!isValidFileStructure)
    {
        cout << "Project structure is broken, fix the errors" << endl;
        exit(1);
    }

    mainMenu();
}

int main(int argc, char *argv[])
{
    headMainApp();

    return 0;
}
