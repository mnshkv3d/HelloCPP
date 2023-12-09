// MNSHKV
//  player's game library were you can add, remove and view your games list

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::find;
using std::string;
using std::vector;

int main()

{
    vector<string> games;

    games.push_back("Max Payne");
    games.push_back("Hitman");
    games.push_back("Serious Sam");
    // vector<string>::iterator myIterator;
    vector<string>::const_iterator iter;
    string userinput;
    string addinput;
    string removeinput;

    cout << "\nWelcome to Game Library" << endl;
    cout << "\nType 'list' if you want to view your game library" << endl;
    cout << "\nType 'add' if you want to add a game to your library" << endl;
    cout << "\nType 'remove' if you want to remove a game from your library" << endl;
    cout << "\nType 'exit' if your want to exit this program" << endl;

    while (userinput != "exit")
    {
        cout << "\n\n$:";
        std::getline(std::cin, userinput);

        if (userinput == "list")
        {
            for (iter = games.begin(); iter != games.end(); ++iter)
            {
                cout << *iter << endl;
            }
        }
        else if (userinput == "add")
        {
            cout << "Enter the name of the game to add:";
            std::getline(std::cin, addinput);
            games.insert(games.begin(), addinput);
            cout << addinput << " is added to the game list.\n";
        }
        else if (userinput == "remove")
        {
            cout << "Enter the name of the game to remove:";
            std::getline(std::cin, removeinput);
            auto it = find(games.begin(), games.end(), removeinput);
            if (it != games.end())
            {
                std::size_t index = std::distance(games.begin(), it);
                games.erase(games.begin() + index);
                cout << removeinput << " is successfully removed from the list" << endl;
            }
            else
            {
                cout << "Game is not found in the list, or you made an incorrect input" << endl;
            }
        }
        else if (userinput != "exit")
        {
            cout << "Command not recognized. Please enter a valid command." << endl;
        }
    }

    return 0;
}
