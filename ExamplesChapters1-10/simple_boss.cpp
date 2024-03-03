#include <iostream>

class Enemy
{
public:
    Enemy();
    void Attack() const;

protected:
    int m_Damage;
};

Enemy::Enemy() : m_Damage(10) {}
void Enemy::Attack() const
{
    std::cout << "Attack inflicts " << m_Damage << " damage points!\n";
}

class Boss : public Enemy
{
public:
    Boss();
    void SpecialAttack() const;

private:
    int m_DamageMultiplier;
};

Boss::Boss() : m_DamageMultiplier(3) {}

void Boss::SpecialAttack() const
{
    std::cout << "Special attack inflicts " << (m_DamageMultiplier * m_Damage) << " damage points!\n";
}

class FinalBoss : public Boss
{
public:
    FinalBoss();
    void MegaAttack() const;

private:
    int m_DamageMultiplier;
};

FinalBoss::FinalBoss() : m_DamageMultiplier(30) {}

void FinalBoss::MegaAttack() const
{
    std::cout << "Mega attack inflicts " << (m_DamageMultiplier * m_Damage) << " damage points!\n";
}

int main()
{
    std::cout << "Creating an enemy.\n";
    Enemy enemy1;
    enemy1.Attack();
    std::cout << "Creating a boss.\n";
    Boss boss1;
    boss1.Attack();
    boss1.SpecialAttack();
    FinalBoss finalboss1;
    finalboss1.MegaAttack();
    return 0;
}