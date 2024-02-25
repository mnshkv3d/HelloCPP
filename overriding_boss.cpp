#include <iostream>

class Enemy
{
public:
    Enemy(int damage = 10);
    void virtual Taunt() const;
    void virtual Attack() const;

private:
    int m_Damage;
};
Enemy::Enemy(int damage) : m_Damage(damage) {}
void Enemy::Taunt() const
{
    std::cout << "The enemy says he will fight you.\n";
}
void Enemy::Attack() const
{
    std::cout << "Attack! Inflicts " << m_Damage << " damage points.";
}
class Boss : public Enemy
{
    public:
    Boss(int damage = 30);
    void virtual Taunt() const;
    void virtual Attack() const;
};
Boss::Boss(int damage) : Enemy(damage) {}

void Boss::Taunt() const