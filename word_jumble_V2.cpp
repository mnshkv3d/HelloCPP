#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

int main()
{
    enum fields
    {
        WORD,
        HINT,
        NUM_FIELDS
    };
    const int NUM_WORDS = 5;
    const std::string WORDS[NUM_WORDS][NUM_FIELDS] = {
        {"wall", "Do you ferl you're banging your head against something?"},
        {"glasses", "These might help you see the answer."},
        {"labored", "Going slowly, is it?"},
        {"persistent", "Keep at it."},
        {"jumble", "It's what the game is all about."}};
    std::cout << "\t\t\tWelcome to the Word Jumble!\n\n";
    std::cout << "Unscrumble the letters to make the word.\n";
    std::cout << "Enter 'hint' for a hint.\n";
    std::cout << "Enter 'quit' to quit the game.\n\n";
    std::string guess;
    std::string theWord;
    std::srand(static_cast<unsigned int>(time(0)));
    int score = 0;

    while (guess != "quit")
    {

        int choice = (std::rand() % NUM_WORDS);
        std::string theWord = WORDS[choice][WORD]; // word to guess
        std::string theHint = WORDS[choice][HINT]; // hint for the word
        std::string jumble = theWord;
        int length = jumble.size();
        for (int i = 0; i < length; ++i)
        {
            int index1 = (std::rand() % length);
            int index2 = (std::rand() % length);
            char temp = jumble[index1];
            jumble[index1] = jumble[index2];
            jumble[index2] = temp;
        }

        std::cout << "The jumble is " << jumble;
        std::cout << "\n\nYour guess: ";
        std::cin >> guess;
        while (guess != theWord && guess != "quit")
        {
            if (guess == "hint")
            {
                std::cout << theHint;
            }
            else
            {
                std::cout << "Sorry, that's not it.\n\n";
                score -= jumble.size();
                std::cout << "Your current score is: " << score << std::endl;
            }
            std::cout << "\n\nYour guess: ";
            std::cin >> guess;
        }
        if (guess == theWord)
        {
            std::cout << "\nThat's it! You guessed it!\n\n\n";
            score += jumble.size();
            std::cout << "Your current score is: " << score << std::endl;
        }
    }
    if (guess == "quit")
    {
        std::cout << "Thanks for playing.\n";
        std::cout << "Your total score is: " << score << std::endl;
    }
}