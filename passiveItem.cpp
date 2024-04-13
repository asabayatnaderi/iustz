#include <iostream>
#include <string>
#include "passiveItem.h"
#include "constants.h"

using namespace std;

// Implementation of Passive methods
Passive::Passive(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount)
    : Item(name, price, shopAmount, inventoryAmount)
{
    this->damage = damage;
    this->staminaCost = staminaCost;
}

void Passive::printAttribute()
{
    cout << color::GREEN << "-Price: " << getPrice() << "$" << endl;
    cout << "-Damage: " << getDamage() << endl;
    cout << "-Amount: " << getShopAmount() << RESET << endl;
}

void Passive::setDamage(int damage)
{
    this->damage = damage;
}

int Passive::getDamage()
{
    return damage;
}

void Passive::setStaminaCost(int staminaCost)
{
    this->staminaCost = staminaCost;
}

int Passive::getStaminaCost()
{
    return staminaCost;
}

// Constructors for different firearm subclasses
Firearm::Firearm(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount)
    : Passive(name, price, damage, staminaCost, shopAmount, inventoryAmount) {}

// Constructors for specific firearm types inheriting from Firearm
AK47::AK47(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount)
    : Firearm(name, price, damage, staminaCost, shopAmount, inventoryAmount) {}

Pistol::Pistol(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount)
    : Firearm(name, price, damage, staminaCost, shopAmount, inventoryAmount) {}

Shotgun::Shotgun(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount)
    : Firearm(name, price, damage, staminaCost, shopAmount, inventoryAmount) {}

UziSubmachineGun::UziSubmachineGun(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount)
    : Firearm(name, price, damage, staminaCost, shopAmount, inventoryAmount) {}

// Constructors for different melee weapon subclasses
MeeleWeapon::MeeleWeapon(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount)
    : Passive(name, price, damage, staminaCost, shopAmount, inventoryAmount) {}

// Constructors for specific melee weapon types inheriting from MeeleWeapon
Knife::Knife(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount)
    : MeeleWeapon(name, price, damage, staminaCost, shopAmount, inventoryAmount) {}

Sword::Sword(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount)
    : MeeleWeapon(name, price, damage, staminaCost, shopAmount, inventoryAmount) {}

Axe::Axe(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount)
    : MeeleWeapon(name, price, damage, staminaCost, shopAmount, inventoryAmount) {}

Nunchaku::Nunchaku(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount)
    : MeeleWeapon(name, price, damage, staminaCost, shopAmount, inventoryAmount) {}