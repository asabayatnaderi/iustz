#include <string>
#include "item.h"

using namespace std;

// Implementation of Item methods
Item::Item(const string &name, int price, int shopAmount, int inventoryAmount)
{
    this->name = name;
    this->price = price;
    this->shopAmount = shopAmount;
    this->inventoryAmount = inventoryAmount;
};

void Item::decreaseShopAmount()
{
    setShopAmount(getShopAmount() - 1);
}

void Item::increaseShopAmount()
{
    setShopAmount(getShopAmount() + 1);
}

void Item::decreaseInventoryAmount()
{
    setInventoryAmount(getInventoryAmount() - 1);
}

void Item::increaseInventoryAmount()
{
    setInventoryAmount(getInventoryAmount() + 1);
}

void Item::setName(const string &name)
{
    this->name = name;
}

const string &Item::getName()
{
    return name;
}

void Item::setPrice(int price)
{
    this->price = price;
}

int Item::getPrice()
{
    return price;
}

void Item::setShopAmount(int shopAmount)
{
    this->shopAmount = shopAmount;
}

int Item::getShopAmount()
{
    return shopAmount;
}

void Item::setInventoryAmount(int inventoryAmount)
{
    this->inventoryAmount = inventoryAmount;
}

int Item::getInventoryAmount()
{
    return inventoryAmount;
}