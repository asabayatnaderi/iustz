#include <iostream>
#include "inventory.h"

using namespace std;

// Implementation of Inventory methods
void Inventory::addItem(Item *item)
{
    // Check if the item already exists in the inventory
    bool exists{false};
    for (auto &pair : items)
    {
        if (pair.second->getName() == item->getName())
        {
            exists = true;
            break;
        }
    }

    // If the item doesn't exist, add it to the inventory
    if (!exists)
    {
        items.push_back({nextItemNumber, item});
        nextItemNumber++;
    }

    // Increase the inventory amount of the item
    item->increaseInventoryAmount();
}

void Inventory::displayItems()
{
    cout << "Inventory contains: " << endl;
    // Display each item in the inventory along with its item number and inventory amount
    for (const auto &pair : items)
    {
        cout << "[" << pair.first << "] " << pair.second->getName() << "(" << pair.second->getInventoryAmount() << ")" << endl;
    }
}

Item *Inventory::getItem(int itemNumber)
{
    // Find and return the item with the given item number
    for (const auto &pair : items)
    {
        if (pair.first == itemNumber)
        {
            return pair.second;
        }
    }
    return nullptr;
}

void Inventory::removeItem(int itemNumber)
{
    // Find and remove the item with the given item number from the inventory
    for (auto it = items.begin(); it != items.end(); it++)
    {
        if (it->first == itemNumber)
        {
            Item *item = it->second;
            if (item->getInventoryAmount() > 1)
            {
                item->decreaseInventoryAmount();
            }
            else
            {
                items.erase(it);
                // Adjust item numbers after removal
                int newItemNumber = 1;
                for (auto &pair : items)
                {
                    pair.first = newItemNumber;
                    newItemNumber++;
                }
                nextItemNumber = newItemNumber;
            }
            break;
        }
    }
}

int Inventory::vectorSize()
{
    return items.size();
}

bool Inventory::ifExists(Item *target)
{
    // Check if the given item exists in the inventory
    for (const auto &pair : items)
    {
        if (pair.second == target)
        {
            return true;
        }
    }
    return false;
}

int Inventory::getItemNumber(Item *item)
{
    // Get the item number of the given item in the inventory
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].second == item)
        {
            return items[i].first;
            break;
        }
    }
    return -1;
}

vector<pair<int, Item *>> Inventory::getItems()
{
    return items;
}

void Inventory::setItems(vector<pair<int, Item *>> items)
{
    this->items = items;
}

int Inventory::getNextItemNumber()
{
    return nextItemNumber;
}

void Inventory::setNextItemNumber(int nextItemNumber)
{
    this->nextItemNumber = nextItemNumber;
}

void Inventory::increaseNextItemNumber()
{
    setNextItemNumber(getNextItemNumber() + 1);
}