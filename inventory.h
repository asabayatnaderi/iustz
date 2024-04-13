#pragma once

#include <vector>
#include <utility>
#include "item.h"
#include "passiveItem.h"
#include "throwableItem.h"
#include "consumableItem.h"

using namespace std;

class Inventory
{
private:
    // Vector to store items along with their item numbers
    vector<pair<int, Item *>> items;
    // Variable to keep track of the next available item number
    int nextItemNumber{1};

public:
    Inventory() = default;

    // Method to add an item to the inventory
    void addItem(Item *item);

    // Method to display all items in the inventory
    void displayItems();

    // Method to retrieve an item by its item number
    Item *getItem(int itemNumber);

    // Method to remove an item from the inventory by its item number
    void removeItem(int itemNumber);

    // Method to get the size of the items vector
    int vectorSize();

    // Method to check if a specific item exists in the inventory
    bool ifExists(Item *target);

    // Method to get the item number of a specific item in the inventory
    int getItemNumber(Item *item);

    // Getter methods
    vector<pair<int, Item *>> getItems();
    int getNextItemNumber();

    // Setter methods
    void setItems(vector<pair<int, Item *>> newItems);
    void setNextItemNumber(int nextItemNumber);

    // Method to increase the next available item number
    void increaseNextItemNumber();
};