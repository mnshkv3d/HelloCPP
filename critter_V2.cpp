#include <iostream>

class Critter
{
public:
    Critter(int hunger = 0, int boredom = 0);
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);
    void CritterStat();

private:
    int m_Hunger;
    int m_Boredom;
    int GetMood() const;
    void PassTime(int time = 1);
};
Critter::Critter(int hunger, int boredom) : m_Hunger(hunger), m_Boredom(boredom)
{
}
inline int Critter::GetMood() const
{
    return (m_Hunger + m_Boredom);
}
void Critter::PassTime(int time)
{
    m_Hunger += time;
    m_Boredom += time;
}
void Critter::Talk()
{
    std::cout << "I'm a critter and I feel ";
    int mood = GetMood();
    if (mood > 15)
    {
        std::cout << "mad.\n";
    }
    else if (mood > 10)
    {
        std::cout << "frustrated.\n";
    }
    else if (mood > 5)
    {
        std::cout << "ok.\n";
    }
    else
    {
        std::cout << "happy.\n";
    }
    std::cout << "\nMy current hunger level is: " << m_Hunger << std::endl;
    std::cout << "\nMy current boredom level is: " << m_Boredom << std::endl;
    PassTime();
}
void Critter::Eat(int food)
{
    std::cout << "Brrupp.\n";
    m_Hunger -= food;
    if (m_Hunger < 0)
    {
        m_Hunger = 0;
    }
    PassTime();
}
void Critter::Play(int fun)
{
    std::cout << "Weee!\n";
    m_Boredom -= fun;
    if (m_Boredom < 0)
    {
        m_Boredom = 0;
    }
    PassTime();
}

void Critter::CritterStat()
{
    std::cout << "Critter hunger level is: " << m_Hunger << " and boredom level is: " << m_Boredom << std::endl;
}
int main()
{
    Critter crit;
    crit.Talk();
    int choice;
    do
    {
        std::cout << "\nCritter Caretaker\n\n";
        std::cout << "0 - Quit\n";
        std::cout << "1 - Listen to your critter\n";
        std::cout << "2 - Feed your critter\n";
        std::cout << "3 - Play with your critter\n";
        std::cout << "4 - Display current state of your critter\n\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            std::cout << "Good bye.\n";
            break;

        case 1:
            crit.Talk();
            break;

        case 2:
            crit.Eat();
            break;

        case 3:
            crit.Play();
            break;
        case 4:
            crit.CritterStat();
            break;
        default:
            std::cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
        }

    } while (choice != 0);
}