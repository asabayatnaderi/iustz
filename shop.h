#pragma once

#include <iostream>
#include <windows.h>
#include <string>
#include <cstdint>
#include "player.h"
#include "consumableItem.h"
#include "passiveItem.h"
#include "throwableItem.h"
#include "inventory.h"

using namespace std;

class ShopSection
{
private:
    PlayerController player;

public:
    ShopSection() = default;
    ShopSection(PlayerController &player);

    void updateShop();

    void passiveItem();

    short buyItem();

    void firearm();

    void meeleWeapons();

    void throwableItem();

    void consumableItem();

    PlayerController startShop();
};