#include <iostream>

using namespace std;

class weapons
{
private:
    int damage;
    int price;
    
    string name;

public:
    weapons(string name, int damage, int price)
    {
        this->name = name;
        this->damage = damage;
        this->price = price;
    }
    string getName()
    {
        return this->name;
    }
    int getDamage()
    {
        return this->damage;
    }
    int getPrice()
    {
        return this->price;
    }
};

class firearm : public weapons
{
private:
    int damage;
    int price;
    string name;
    string weakness;

public:
    firearm(string name, int damage, int price, string weakness) : weapons(name, damage, price)
    {
        this->weakness = weakness;
    }
    string getWeakness()
    {
        return this->weakness;
    }
};

class AK47 : public firearm
{
private:
    int damage;
    int price;
    string name;
    string weakness;

public:
    AK47(string name, int damage, int price, string weakness) : firearm(name, damage, price, weakness)
    {

    }
};

class Pistol : public firearm
{
private:
    int damage;
    int price;
    string name;
    string weakness;

public:
    Pistol(string name, int damage, int price, string weakness) : firearm(name, damage, price, weakness)
    {

    }
};

class coldWeapons : public weapons
{
private:
    int damage;
    int price;
    string name;
    string weakness;

public:
    coldWeapons(string name, int damage, int price, string weakness) : weapons(name, damage, price)
    {
        this->weakness = weakness;
    }
    string getWeakness()
    {
        return this->weakness;
    }
};

class knife : public coldWeapons
{
private:
    int damage;
    int price; 
    string name;
    string weakness;

public:
    knife(string name, int damage, int price, string weakness) : coldWeapons(name, damage, price, weakness)
    {
        
    }
};

class sword : public coldWeapons
{
private:
    int damage;
    int price;
    string name;
    string weakness;

public:
    sword(string name, int damage, int price, string weakness) : coldWeapons(name, damage, price, weakness)
    {

    }
};

class throwableWeapons : public weapons
{
private:
    int damage;
    int price;
    string name;
    string weakness;

public:
    throwableWeapons(string name, int damage, int price, string weakness) : weapons(name, damage, price)
    {
        this->weakness = weakness;
    }
    string getWeakness()
    {
        return this->weakness;
    }
};

class gernade : public throwableWeapons
{
private:
    int damage;
    int price;
    int amount;
    string name;
    string weakness;

public:
    gernade(string name, int damage, int price, string weakness) : throwableWeapons(name, damage, price, weakness)
    {

    }
};

class flashbang : public throwableWeapons
{
private:
    int damage;
    int price;
    string name;
    string weakness;

public:
    flashbang(string name, int damage, int price, string weakness) : throwableWeapons(name, damage, price, weakness)
    {

    }
};

class specialWeapons
{
private:
    int damageReduction;
    int price;
    string name;

public:
    specialWeapons(string name, int damageReduction, int price)
    {
        this->name = name;
        this->damageReduction = damageReduction;
        this->price = price;
    }
    string getName()
    {
        return this->name;
    }
    int getDamageDeduction()
    {
        return this->damageReduction;
    }
    int getPrice()
    {
        return this->price;
    }
};

class bulletproofVest : public specialWeapons
{
private:
    int damageReduction;
    int price;
    string name;

public:
    bulletproofVest(string name, int damageReduction, int price) : specialWeapons(name, damageReduction, price)
    {
        
    }
};

class shield : public specialWeapons
{
private:
    int damageReduction;
    int price;
    string name;

public:
    shield(string name, int damageReduction, int price) : specialWeapons(name, damageReduction, price)
    {
        
    }
};