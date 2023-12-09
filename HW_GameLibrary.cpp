// MNSHKV
//  player's game library were you can add, remove and view your games list

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <random>

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
    string userinput;

    while (userinput != "exit")
    {
        cout << "\nWelcome to Game Library" << endl;
        cout << "\nType 'list' if you want to view your game library" << endl;
        cout << "\nType 'add' if you want to add a game to your library" << endl;
        cout << "\nType 'remove' if you want to remove a game from your library" << endl;
        cout << "\nType 'exit' if your want to exit this program" << endl;
        cout << "\n\n$:";
        cin >> userinput;
    }
}
