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
    virtual void printAttribute() = 0;
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
    void printAttribute() override
    {
        cout << "Price: " << this->getPrice() << endl;
        cout << "Damage: " << this->getDamage() << endl;
        cout << "Weakness: " << this->getWeakness() << endl;
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
    void printAttribute() override
    {
        cout << "Price: " << this->getPrice() << endl;
        cout << "Damage: " << this->getDamage() << endl;
        cout << "Weakness: " << this->getWeakness() << endl;
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
    void printAttribute() override
    {
        cout << "Price: " << this->getPrice() << endl;
        cout << "Damage: " << this->getDamage() << endl;
        cout << "Weakness: " << this->getWeakness() << endl;
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
    int damageDecrease;
    int price;
    string name;
    string weakness;

public:
    specialWeapons(string name, int damageDecrease, int price, string weakness)
    {
        this->name = name;
        this->damageDecrease = damageDecrease;
        this->price = price;
        this->weakness = weakness;
    }
    string getName()
    {
        return this->name;
    }
    int getDamageDecrease()
    {
        return this->damageDecrease;
    }
    int getPrice()
    {
        return this->price;
    }
    string getWeakness()
    {
        return this->weakness;
    }
    virtual void printAttribute() = 0;
};

class bulletproofVest : public specialWeapons
{
private:
    int damageDecrease;
    int price;
    string name;
    string weakness;

public:
    bulletproofVest(string name, int damageDecrease, int price, string weakness) : specialWeapons(name, damageDecrease, price, weakness)
    {
        
    }
    void printAttribute() override
    {
        cout << "Price: " << this->getPrice() << endl;
        cout << "Decreased Damage: " << this->getDamageDecrease() << endl;
        cout << "Weakness: " << this->getWeakness() << endl;
    }
};

class shield : public specialWeapons
{
private:
    int damageDecrease;
    int price;
    string name;
    string weakness;

public:
    shield(string name, int damageDecrease, int price, string weakness) : specialWeapons(name, damageDecrease, price, weakness)
    {
        
    }
    void printAttribute() override
    {
        cout << "Price: " << this->getPrice() << endl;
        cout << "Decreased Damage: " << this->getDamageDecrease() << endl;
        cout << "Weakness: " << this->getWeakness() << endl;
    }
};