// classic game "Hangman"

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
    // preparing
    const int MAX_WRONG = 8; // max possible mistakes made by user
    vector<string> words;    // array of words to guess
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(words.begin(), words.end(), g);
    const string THE_WORD = words[0];   // word to guess
    int wrong = 0;                      // init var of user wrong guess
    string soFar(THE_WORD.size(), '-'); // guessed letters from the word
    string used = "";                   // guessed letters
    cout << "Welcome to Hangman. Good luck!\n";

    // main game cycle
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
        cout << "\n\nYou have " << (MAX_WRONG - wrong);
        cout << " incrorrect guesses left.\n";
        cout << "\nYou've used the following letters:\n"
             << used << endl;
        cout << "\nSo far, the word is:\n"
             << soFar << endl;
        char guess;
        cout << "\n\nEnter your guess: ";
        cin >> guess;
        guess = std::toupper(guess); // convert to upper register
        while (used.find(guess) != string::npos)
        {
            cout << "\nYou've already guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = std::toupper(guess);
        }
        used += guess;
        if (THE_WORD.find(guess) != string::npos)
        {
            cout << "That's right!" << guess << " is in the word.\n";
            // update var soFar by adding new guessed letter;
            for (int i = 0; i < THE_WORD.length(); ++i)
            {
                if (THE_WORD[i] == guess)
                {
                    soFar[i] = guess;
                }
            }
        }
        else
        {
            cout << "Sorry, " << guess << " isn't in the word.\n";
            ++wrong;
        }
    }
    // game end
    if (wrong == MAX_WRONG)
    {
        cout << "\nYou've been hanged!";
    }
    else
    {
        cout << "You guessed it!";
    }
    cout << "\nThe word was " << THE_WORD << endl;
    return 0;
}