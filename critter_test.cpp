#include <iostream>

class Critter
{
    public:
    int GetHunger() const { return m_Hunger;}
    private:
    int m_Hunger;
};

int main()
{
Critter crit;
std::cout << crit.GetHunger() << std::endl;
return 0;
}