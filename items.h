#include <string>
#include <iostream>
#include "player.h"
#include "character.h"
#include "weapons.h"

using namespace std;

class Item{
public:
    string Name;
    int Price;
    Item( string name, int price){
        Name = name;
        Price = price;
    };
    
};


class Consumable : public Item{
public:
    Consumable(string name, int price) : Item(name, price) {}
    bool Isconsumed;

};

class Cookie : public Consumable{
public:
    Cookie( string name , int price , bool isConsumed) : Consumable(name, price)
    {
        Isconsumed = isConsumed;
    };
    string feature = "Gives 50 health";
    void consume(PlayerModel player){
        player.hpIncrease(50);    
    }

};

class Soda : public Consumable{
public:
    Soda( string name , int price , bool isConsumed) : Consumable(name, price)
    {
        Isconsumed = isConsumed;
    };
    string feature = "Gives 50 stamina";
    void consume(PlayerModel player){
        player.staminaIncrease(50);    
    }

};

class Chocolate : public Consumable{
public:
    Chocolate( string name , int price , bool isConsumed) : Consumable(name, price)
    {
        Isconsumed = isConsumed;
    };
    string feature = "Gives 25 stamina & 25 health";
    PlayerModel consume(PlayerModel player){
        player.hpIncrease(25);
        player.staminaIncrease(25);
        cout << "PlayerHP: " << player.HealthPoints << endl;
        return player; 
    }

};


