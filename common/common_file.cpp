// wallet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <iostream>

int main(int argc, char* argv[]) {
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

    // Ваш код для обробки аргументів
    std::cout << "Filename: " << filename << std::endl;
    std::cout << "Zero: " << (zeroValue ? "true" : "false") << std::endl;

    return 0; // Повертаємо код успішного завершення програми
}
