#include <iostream>
#include <string>

int main() {
    std::string input;

    // Считывание строки с использованием getline
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);

    // Вывод введенной строки
    std::cout << "Вы ввели: " << input << std::endl;

    return 0;
}
