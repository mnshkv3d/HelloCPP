#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int randomNumber = rand();
    int die =(randomNumber % 6) + 1;
    std::cout << "You rolled a " << die << std::endl;
}