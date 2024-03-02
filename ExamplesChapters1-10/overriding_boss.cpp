#include <iostream>

class Enemy //создание базового класса врага
{
public:
    Enemy(int damage = 10);
    void virtual Taunt() const;
    void virtual Attack() const;

private:
    int m_Damage;
};
Enemy::Enemy(int damage) : m_Damage(damage) {} //конструктор базового класса
void Enemy::Taunt() const
{
    std::cout << "The enemy says he will fight you.\n";
}
void Enemy::Attack() const
{
    std::cout << "Attack! Inflicts " << m_Damage << " damage points.\n";
}
class Boss : public Enemy //создание класса босса
{
public:
    Boss(int damage = 30);
    void virtual Taunt() const;
    void virtual Attack() const;
};
Boss::Boss(int damage) : Enemy(damage) {} //конструктор объекта босса

void Boss::Taunt() const
{
    std::cout << "The boss says he will end your pitiful existence.\n";
}
void Boss::Attack() const
{
    Enemy::Attack();
    std::cout << "And laughs heartily at you.\n";
}
int main()
{
    std::cout << "Enemy object: \n";
    Enemy anEnemy;
    anEnemy.Taunt();
    anEnemy.Attack();
    std::cout << "\n\nBoss object: \n";
    Boss aBoss;
    aBoss.Taunt();
    aBoss.Attack();
    return 0;
}