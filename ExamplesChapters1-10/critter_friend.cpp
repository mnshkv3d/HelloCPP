// Friend Critter

#include <iostream>
#include <string>

using namespace std;

class Critter
{
    friend void Peek(const Critter &aCritter);
    friend ostream &operator<<(ostream &os, const Critter &aCritter);

public:
    Critter(const std::string &name = "");

private:
    std::string m_Name;
};

Critter::Critter(const std::string &name) : m_Name(name) {}

void Peek(const Critter &aCritter);
ostream &operator<<(ostream &os, const Critter &aCritter);

int main()
{
    Critter crit("Poochie");
    std::cout << "Calling Peek() access to crit's private data member m_Name: \n";
    Peek(crit);
    std::cout << "\n Sending crit object to cout with the << operator: \n";
    std::cout << crit;
    return 0;
}

void Peek (const Critter& aCritter)
{
    cout << aCritter.m_Name << endl;
}

ostream &operator<<(ostream &os, const Critter &aCritter)
{
    os << "Critter Object - ";
    os << "m_Name: " << aCritter.m_Name << endl;
    return os;
}