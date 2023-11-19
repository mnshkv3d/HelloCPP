#include <iostream>


int main()
{
    char again = 'y';
    while (again == 'y')
    {
        std::cout << "Do you wanna play some game? \n";
        std::cin >> again;
    }
    std::cout << "Okay, bay \n";
    
}