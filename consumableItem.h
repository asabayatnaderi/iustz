#pragma once

#include <string>
#include "item.h"
#include "player.h"
#include "humanEnemy.h"

using namespace std;

// Base class for consumable items
class Consumable : public Item
{
private:
    bool isconsumed{};

public:
    // Constructor
    Consumable(const string &name, int price, int shopAmount, int inventoryAmount);

    // Setter and getter for isconsumed
    void setIsconsumed(bool isconsumed);
    bool getIsconsumed();

    // Virtual method to consume the item (pure virtual, to be implemented by derived classes)
    virtual void consume(PlayerController &player) = 0;
    virtual void consume(humanEnemyController &enemy) = 0;

    // Virtual method to print attributes (pure virtual, to be implemented by derived classes)
    virtual void printAttribute() = 0;
};

// Derived class for a specific consumable item: Cookie
class Cookie : public Consumable
{
public:
    // Constructor
    Cookie(const string &name, int price, bool isConsumed, int shopAmount, int inventoryAmount);

    string feature = "Gives 30 HP"; // Feature description

    // Methods to consume the item
    void consume(PlayerController &player);
    void consume(humanEnemyController &enemy);

    // Method to print attributes
    void printAttribute();
};

// Derived class for another consumable item: Soda
class Soda : public Consumable
{
public:
    // Constructor
    Soda(const string &name, int price, bool isConsumed, int shopAmount, int inventoryAmount);

    string feature = "Gives 30 stamina"; // Feature description

    // Methods to consume the item
    void consume(PlayerController &player);
    void consume(humanEnemyController &enemy);

    // Method to print attributes
    void printAttribute();
};

// Derived class for another consumable item: Chocolate
class Chocolate : public Consumable
{
public:
    // Constructor
    Chocolate(const string &name, int price, bool isConsumed, int shopAmount, int inventoryAmount);

    string feature = "Gives 25 stamina & 25 HP"; // Feature description

    // Methods to consume the item
    void consume(PlayerController &player);
    void consume(humanEnemyController &enemy);

    // Method to print attributes
    void printAttribute();
};

// Derived class for another consumable item: Hype
class Hype : public Consumable
{
public:
    // Constructor
    Hype(const string &name, int price, bool isConsumed, int shopAmount, int inventoryAmount);

    string feature = "Gives 40 stamina"; // Feature description

    // Methods to consume the item
    void consume(PlayerController &player);
    void consume(humanEnemyController &enemy);

    // Method to print attributes
    void printAttribute();
};