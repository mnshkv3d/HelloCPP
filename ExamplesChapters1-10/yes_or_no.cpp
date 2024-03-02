#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

char askYesNo(string question);

int main()
{
    char answer = askYesNo("Please enter your choice");
    if (answer == 'y')
    {
        char answer1 = askYesNo("Do you with to save your game?");
    }
    else return 0;
}

char askYesNo(string question)
{
    char response;
    do
    {
        cout << question << " (y/n): ";
        cin >> response;
        cout << "Thanks for answering: " << response << "\n";

    } while (response != 'y' && response != 'n');
    return response;
}
