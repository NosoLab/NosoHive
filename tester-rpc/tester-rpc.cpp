#include <iostream>
#include <iomanip>
//#include "mini/ini.h"

using namespace std;

/*
   std::string filename = "default_filename.pkw";
    bool zeroValue = false;

    // Перевірка, чи передано достатньо аргументів
    if (argc >= 2) {
        // Обробляємо аргументи
        for (int i = 1; i < argc; i += 2) {
            if (std::string(argv[i]) == "-file" && i + 1 < argc) {
                // Обробляємо аргумент -file, наступний елемент у масиві - ім'я файлу
                filename = argv[i + 1];
            }
            else if (std::string(argv[i]) == "-zero" && i + 1 < argc) {
                // Обробляємо аргумент -zero, наступний елемент у масиві - true або false
                std::string zeroArg = argv[i + 1];
                zeroValue = (zeroArg == "true");
            }
            else {
                // Невідомий аргумент
                std::cerr << "Unknown argument: " << argv[i] << std::endl;
                return 1; // Повертаємо код помилки
            }
        }
    }

*/

/*
* tester-rpc -url 10.22.22.22:8080 -method getmainnetinfo
* tester-rpc -url 10.22.22.22:8080 -method getblockorders -param 94490

При відкриті як апку показати заголовок
показати вибраний сервер
покзати дії, змінити сервер
вибрати команду
*/


int main(int argc, char* argv[]) {
  std::string defaultServer = "127.0.0:8080";

    std::cout << "RPC-TESTER" << std::endl;
    std::cout << std::setfill('-') << std::setw(40) << "-" << std::setfill(' ') << "\n";

    std::cout << "Select RPC Server -> " << defaultServer << " (Other)" << std::endl;

    
    std::cout << "\n";
    std::cout << "Enter a command or method with a parameter to test, for help use help\n";

        std::string choice;
        std::cout << "test-rpc:";
        std::cin >> choice;



      if (choice == "help") {
        std::cout << "Help option selected.\n";
       } 


 return 0;
    }
    /*
    while (true) {
        std::cout << "1. Change RPC Server\n";
        std::cout << "2. Select a method for testing\n";
        std::cout << "3. Exit\n";
        
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "You selected Option 1\n";
                break;
            case 2:
                std::cout << "You selected Option 2\n";
                break;
            case 3:
                std::cout << "Exiting the application\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
*/
   // return 0;

    // Ваш код для обробки аргументів
  //  std::cout << "Filename: " << filename << std::endl;
   // std::cout << "Zero: " << (zeroValue ? "true" : "false") << std::endl;






  //  return 1; // Повертаємо код успішного завершення програми

