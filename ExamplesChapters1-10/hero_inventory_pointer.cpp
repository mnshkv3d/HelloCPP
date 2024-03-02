// Hero’s Inventory 3.0
#include <iostream>
#include <string>
#include <vector>

std::string* ptrToElement(std::vector<std::string>* const pVec, int i);

int main()
{
    std::vector<std::string> inventory;
    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");
    std::cout << "Sending object pointed to by returned pointer to cout:\n";
    std::cout << *(ptrToElement(&inventory, 0)) << "\n\n";
    std::cout << "Assinging the returned pointer to another pointer\n";
    std::string* pStr = ptrToElement(&inventory, 1);
    std::cout << "Sending the object pointed by the new pointer to cout:\n";
    std::cout << *pStr << "\n\n";
}

std::string* ptrToElement(std::vector<std::string>* const pVec, int i)
{
    return &((*pVec)[i]);
}