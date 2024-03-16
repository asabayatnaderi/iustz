#include <iostream>

using namespace std;

class HP
{
private:
    int hp;

public:
    void hpIncrease(int newHp)
    {
        this->hp += newHp;
    }
    void hpDecrease(int newHp)
    {
        this->hp -= newHp;
    }
};

class stamina
{
private:
    int stamina;

public:
    void staminaIncrease(int newStamina)
    {
        this->stamina += newStamina;
    }
    void staminaDecrease(int newStamina)
    {
        this->stamina -= newStamina;
    }
};

class XP
{
private:
    int xp;

public:
    void xpIncrease(int newXp)
    {
        this->xp += newXp;
    }
};

class intelligence
{
private:
    int intelligence;

public:
    void intelligenceIncrease(int newIntelligence)
    {
        this->intelligence += intelligence;
    }
};

class level
{
private:
    int level;

public:
    void levelIncrease()
    {
        this->level += 1;
    }
};