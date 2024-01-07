// Inventory Displayer program
// Showcase constant references

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::find;
using std::string;
using std::vector;

void display(const vector<string>& inventory);

int main()
{
    vector<string> inventory;
    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");
    display(inventory);
    return 0;
}

// vec - constant reference to string vector

void display(const vector<string>& vec)
{
    cout << "Your items:\n";

    for (vector<string>::const_iterator iter = vec.begin();
    iter != vec.end(); ++iter)
    {
        cout << *iter << endl;
    }
}
