#include <iostream>

class Creature // abstract class
{
  public:
    Creature(int health = 100);
    virtual void Greet() const = 0;
    virtual void DisplayHealth() const;

  protected:
    int m_Health;
};
Creature::Creature(int health) : m_Health(health)
{
}
void Creature::DisplayHealth() const
{
    std::cout << "Health: " << m_Health << std::endl;
}
class Orc : public Creature
{
  public:
    Orc(int health = 120);
    virtual void Greet() const; // override;
};
Orc::Orc(int health) : Creature(health)
{
}
void Orc::Greet() const
{
    std::cout << "The orc grunts hello.\n";
}
class OrcBoss : public Orc
{
  public:
    OrcBoss(int health = 180);
    virtual void Greet() const;
};
OrcBoss::OrcBoss(int health) : Orc(health)
{
}
void OrcBoss::Greet() const
{
    std::cout << "The orc growls hello.\n";
}
int main()
{
    Creature *pCreature = new OrcBoss();
    pCreature->Greet();
    pCreature->DisplayHealth();
    return EXIT_SUCCESS;
}
