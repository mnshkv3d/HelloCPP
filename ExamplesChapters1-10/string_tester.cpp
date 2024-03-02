#include <iostream>
#include <string>

int main()
{
    std::string word1 = "Game";
    std::string word2 ("Over");
    std::string word3 (3, '!');
    std::string phrase = word1 + " " + word2 + word3;
    std::cout << "The phrase is: " << phrase << "\n\n";
    std::cout << "The phrase has " << phrase.size() << " characters in it. \n\n";
    std::cout << "The character at position 0 is: " << phrase[0] << "\n\n";
    std::cout << "Changing the character at position 0.\n";
    phrase[0] = 'L';
    std::cout << "New phrase is: " << phrase << "\n\n";
    for (unsigned int i =0; i< phrase.size(); ++i)
    {
        std::cout << "Character at position " << i << " is: " << phrase[i] << std::endl;
    }
    std::cout << "\nThe sequence 'Over' begins at location ";
    std::cout << phrase.find("Over") << std::endl;
    if (phrase.find("eggplant") == std::string::npos)
    {
        std::cout << " 'eggplant' is not in the phrase.\n\n";
    }
    phrase.erase(4, 5);
    std::cout << "The phrase is now: " << phrase << std::endl;
    phrase.erase(4);
    std::cout << "The phrase is now: " << phrase << std::endl;
    phrase.erase();
    std::cout << "The phrase is now: " << phrase << std::endl;
    if (phrase.empty())
    {
        std::cout << "\nThe phrase is no more.\n";
    }
}