#include <iostream>


int main()
{
    std::cout <<"Difficulty Levels\n\n";
    std::cout <<"1 - Easy\n\n";
    std::cout <<"2 - Normal\n\n";
    std::cout <<"3 - Hard\n\n";
    int choice = 0;
while (choice != 1 && choice != 2 && choice != 3) {
    std::cout << "Choice: ";
    std::cin >> choice;

    // Check if the entered choice is valid
    if (choice == 1) {
        std::cout << "You picked Easy.\n";
    } else if (choice == 2) {
        std::cout << "You picked Normal.\n";
    } else if (choice == 3) {
        std::cout << "You picked Hard.\n";
    } else {
        std::cout << "Invalid choice. Please enter a valid option.\n";
    }
}
}