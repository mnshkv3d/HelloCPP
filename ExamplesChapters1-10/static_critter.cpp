#include <iostream>

class Critter
{
public:
    static int s_Total; // declare static variable
    // total count of Critter objects
    Critter(int hunger = 0);
    static int GetTotal(); // prototype of static function
private:
    int m_Hunger;
};
int Critter::s_Total = 0;
Critter::Critter(int hunger) : m_Hunger(hunger)
{
    std::cout << "A critter has beeb born!" << std::endl;
    ++s_Total;
}
int Critter::GetTotal()
{
    return s_Total;
}
int main()
{
    std::cout << "The total number of critters is: " << Critter::s_Total << "\n\n";
    Critter crit1, crit2, crit3;
    std::cout << "The total number of critters is: " << Critter::s_Total << "\n\n";

    std::cout << "The total number of critters is: " << Critter::GetTotal() << "\n\n";
    return 0;
}