#pragma once

#include <string>
#include "item.h"

using namespace std;

// Class representing a passive item, inheriting from Item
class Passive : public Item
{
private:
    int damage{};
    int staminaCost{};

public:
    // Constructor
    Passive(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount);

    // Setter methods
    void setDamage(int damage);
    void setStaminaCost(int StaminaCost);

    // Getter methods
    int getDamage();
    int getStaminaCost();

    // Method to print attributes of the passive item
    void printAttribute();
};

// Class representing a firearm, inheriting from Passive
class Firearm : public Passive
{
public:
    // Constructor
    Firearm(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount);
};

// Derived classes for specific firearms
class AK47 : public Firearm
{
public:
    // Constructor
    AK47(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount);
};

class Pistol : public Firearm
{
public:
    // Constructor
    Pistol(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount);
};

class Shotgun : public Firearm
{
public:
    // Constructor
    Shotgun(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount);
};

class UziSubmachineGun : public Firearm
{
public:
    // Constructor
    UziSubmachineGun(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount);
};

// Class representing a melee weapon, inheriting from Passive
class MeeleWeapon : public Passive
{
public:
    // Constructor
    MeeleWeapon(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount);
};

// Derived classes for specific melee weapons
class Knife : public MeeleWeapon
{
public:
    // Constructor
    Knife(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount);
};

class Sword : public MeeleWeapon
{
public:
    // Constructor
    Sword(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount);
};

class Axe : public MeeleWeapon
{
public:
    // Constructor
    Axe(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount);
};

class Nunchaku : public MeeleWeapon
{
public:
    // Constructor
    Nunchaku(const string &name, int price, int damage, int staminaCost, int shopAmount, int inventoryAmount);
};