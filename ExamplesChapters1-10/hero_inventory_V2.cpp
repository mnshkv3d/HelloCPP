// Hero's Inventory 2.0
// standart library, vector function
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

int main()
{
    vector<string> inventory;
    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");
    cout << "You have " << inventory.size() << " items.\n";
    cout << "Your items:\n";

    for (unsigned int i = 0; i < inventory.size(); i++)
    {
        cout << inventory[i] << std::endl;
    }
    
}