#include <iostream>
#include <string>

int main()
{
    std::string username;
    std::string password;
    bool succes;
    std::cout << "Game Designers Network\n";
    do
    {
        std::cout << "\nUsername:";
        std::cin >> username;
        std::cout << "\nPassword:";
        std::cin >> password;
        if(username == "Maier" && password == "civ")
        {
            std::cout << "Welcome Sid Maier\n";
            succes = true;
        }
        else if (username == "Kojima" && password == "mgs")
        {
            std::cout << "Welcome Hideo\n";
            succes = true;
        }
        else if (username == "guest" || password == "guest")
        {
            std::cout << "Welcome Guest\n";
            succes = true;
        }
        else
        {
            std::cout << "Login failed\n";
            succes = false;
        }
             
        
    } while (!succes);
    


}