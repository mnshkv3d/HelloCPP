#include <iostream>

class Critter // define new class Critter
{
public:
    int m_Hunger;
    void Greet();
};
void Critter::Greet() // define class member
{
    std::cout << "Hi! I'm critter. My hunger level is " << m_Hunger << ".\n";
}
int main()
{
    Critter crit1;
    Critter crit2;
    crit1.m_Hunger = 9;
    crit2.m_Hunger = 3;
    std::cout << "crit1's hunger level is " << crit1.m_Hunger << ".\n";
    std::cout << "crit2's hunger level is " << crit2.m_Hunger << ".\n";
    crit1.Greet();
    crit2.Greet();
    return 0;
}

