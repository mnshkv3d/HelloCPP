#include <iostream>


int main()
{
    char again = 'y';

    do
    {
        std::cout << "Do you wanna play some game? \n";
        std::cin >> again;
    } while (again == 'y');
    std::cout << "Okay, bay \n";
    
}