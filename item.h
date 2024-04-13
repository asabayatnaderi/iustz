#pragma once

#include <string>

using namespace std;

// Item class represents an item available in a shop or in the player's inventory
class Item
{
private:
    string name{};
    int price{};
    int shopAmount{};
    int inventoryAmount{};

public:
    Item() = default;

    // Constructor to initialize an Item object with provided data
    Item(const string &name, int price, int shopAmount, int inventoryAmount);

    // Methods to decrease and increase the quantity of the item in the shop
    void decreaseShopAmount();
    void increaseShopAmount();

    // Methods to decrease and increase the quantity of the item in the player's inventory
    void decreaseInventoryAmount();
    void increaseInventoryAmount();

    // Setter methods
    void setName(const string &name);
    void setPrice(int price);
    void setShopAmount(int amount);
    void setInventoryAmount(int amount);

    // Getter methods
    const string &getName();
    int getPrice();
    int getShopAmount();
    int getInventoryAmount();
};