#include <iostream>

enum class Difficulty {
    EASY = 1,
    NORMAL,
    HARD
};

int main() {
    std::cout << "Difficulty Levels\n\n";
    std::cout << "1 - Easy\n\n";
    std::cout << "2 - Normal\n\n";
    std::cout << "3 - Hard\n\n";

    int choice = 0;
    while (choice != static_cast<int>(Difficulty::EASY) &&
           choice != static_cast<int>(Difficulty::NORMAL) &&
           choice != static_cast<int>(Difficulty::HARD)) {
        std::cout << "Choice: ";
        std::cin >> choice;

        if (choice == static_cast<int>(Difficulty::EASY)) {
            std::cout << "You picked Easy.\n";
        } else if (choice == static_cast<int>(Difficulty::NORMAL)) {
            std::cout << "You picked Normal.\n";
        } else if (choice == static_cast<int>(Difficulty::HARD)) {
            std::cout << "You picked Hard.\n";
        } else {
            std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}