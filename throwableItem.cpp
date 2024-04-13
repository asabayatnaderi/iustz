#include <iostream>
#include <string>
#include "throwableItem.h"
#include "constants.h"

using namespace std;

// Implementation of Throwable class
Throwable::Throwable(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount) : Item(name, price, shopAmount, inventoryAmount)
{
    this->damage = damage;
    this->staminaCost = staminaCost;
}

void Throwable::printAttribute()
{
    cout << color::GREEN << "-Price: " << getPrice() << "$" << endl;
    cout << "-Damage: " << getDamage() << endl;
    cout << "-Amount: " << getShopAmount() << RESET << endl;
}

void Throwable::setDamage(int damage)
{
    this->damage = damage;
}

void Throwable::setStaminaCost(int staminaCost)
{
    this->staminaCost = staminaCost;
}

int Throwable::getStaminaCost()
{
    return staminaCost;
}

int Throwable::getDamage()
{
    return damage;
}

// Implementation of specialized throwable items
Grenade::Grenade(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount)
    : Throwable(name, price, damage, staminaCost, shopAmount, inventoryAmount) {}

Flashbang::Flashbang(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount)
    : Throwable(name, price, damage, staminaCost, shopAmount, inventoryAmount) {}

RPG7::RPG7(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount)
    : Throwable(name, price, damage, staminaCost, shopAmount, inventoryAmount) {}

C4::C4(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount)
    : Throwable(name, price, damage, staminaCost, shopAmount, inventoryAmount) {}