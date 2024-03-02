#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int secretNumber = rand() % 100 + 1;
    int tries = 0;
    char guess;
    std::cout << "\tWelcome to Guess My Number V2\n\n";
    do
    {
        std::cout << "My guess is:" << secretNumber << std::endl;
        std::cin >> guess;
        ++tries;
        if (guess == 'n')
        {
            secretNumber = rand() % 100 + 1;
        }
      
        else
        {
            std::cout << "\nThat's it! You got it in " << tries << " guesses!\n";
        }
    } while (guess != 'y');
    return 0;
}