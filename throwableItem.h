#pragma once

#include <string>
#include "item.h"

using namespace std;

// Declaration of the Throwable class, inheriting from Item
class Throwable : public Item
{
private:
    int damage{};
    int staminaCost{};

public:
    // Constructor
    Throwable(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount);

    // Setter methods
    void setDamage(int damage);
    void setStaminaCost(int staminaCost);

    // Setter methods
    int getStaminaCost();
    int getDamage();

    // Method to print attributes of the throwable item
    void printAttribute();
};

// Derived classes for specific throwable items, inheriting from Throwable class
class Grenade : public Throwable
{
public:
    // Constructor
    Grenade(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount);
};

class Flashbang : public Throwable
{
public:
    // Constructor
    Flashbang(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount);
};

class RPG7 : public Throwable
{
public:
    // Constructor
    RPG7(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount);
};

class C4 : public Throwable
{
public:
    // Constructor
    C4(const string &nam, int pricee, int damage, int staminaCost, int shopAmount, int inventoryAmount);
};