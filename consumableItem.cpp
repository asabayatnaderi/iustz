#include <iostream>
#include <string>
#include "consumableItem.h"
#include "constants.h"

using namespace std;

// Implementation of Consumable methods
Consumable::Consumable(const string &name, int price, int shopAmount, int inventoryAmount) : Item(name, price, shopAmount, inventoryAmount) {}

void Consumable::setIsconsumed(bool isconsumed)
{
    this->isconsumed = isconsumed;
}

bool Consumable::getIsconsumed()
{
    return isconsumed;
}

// Implementation of Cookie methods
Cookie::Cookie(const string &name, int price, bool isConsumed, int shopAmount, int inventoryAmount)
    : Consumable(name, price, shopAmount, inventoryAmount)
{
    setIsconsumed(isConsumed);
}

void Cookie::consume(PlayerController &player)
{
    player.increaseHp(30);
}

void Cookie::consume(humanEnemyController &enemy)
{
    enemy.increaseHp(30);
}

void Cookie::printAttribute()
{
    cout << color::GREEN << "-Price: " << getPrice() << "$" << endl;
    cout << "-Feature: " << feature << endl;
    cout << "-Amount: " << getShopAmount() << RESET << endl;
}

// Implementation of Soda methods
Soda::Soda(const string &name, int price, bool isConsumed, int shopAmount, int inventoryAmount)
    : Consumable(name, price, shopAmount, inventoryAmount)
{
    setIsconsumed(isConsumed);
}

void Soda::consume(PlayerController &player)
{
    player.increaseStamina(30);
}

void Soda::consume(humanEnemyController &enemy)
{
    enemy.increaseStamina(30);
}

void Soda::printAttribute()
{
    cout << color::GREEN << "-Price: " << getPrice() << "$" << endl;
    cout << "-Feature: " << feature << endl;
    cout << "-Amount: " << getShopAmount() << RESET << endl;
}

// Implementation of Chocolate methods
Chocolate::Chocolate(const string &name, int price, bool isConsumed, int shopAmount, int inventoryAmount)
    : Consumable(name, price, shopAmount, inventoryAmount)
{
    setIsconsumed(isConsumed);
};

void Chocolate::consume(PlayerController &player)
{
    player.increaseHp(25);
    player.increaseStamina(25);
}

void Chocolate::consume(humanEnemyController &enemy)
{
    enemy.increaseHp(25);
    enemy.increaseStamina(25);
}

void Chocolate::printAttribute()
{
    cout << color::GREEN << "-Price: " << getPrice() << "$" << endl;
    cout << "-Feature: " << feature << endl;
    cout << "-Amount: " << getShopAmount() << RESET << endl;
}

// Implementation of Hype methods
Hype::Hype(const string &name, int price, bool isConsumed, int shopAmount, int inventoryAmount)
    : Consumable(name, price, shopAmount, inventoryAmount)
{
    setIsconsumed(isConsumed);
};

void Hype::consume(PlayerController &player)
{
    player.increaseStamina(40);
}

void Hype::consume(humanEnemyController &enemy)
{
    enemy.increaseStamina(40);
}

void Hype::printAttribute()
{
    cout << color::GREEN << "-Price: " << getPrice() << "$" << endl;
    cout << "-Feature: " << feature << endl;
    cout << "-Amount: " << getShopAmount() << RESET << endl;
}