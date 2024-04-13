#include "shop.h"
#include "fight.h"

using namespace std;

Inventory inventory;
extern vector<Item *> allItems;

ShopSection::ShopSection(PlayerController &player) : player(player) {}

// This function iterates through all items and removes any item with a shop quantity of zero.
void ShopSection::updateShop()
{
    for (auto it = allItems.begin(); it != allItems.end(); it++)
    {
        if ((*it)->getShopAmount() == 0)
        {
            allItems.erase(it);
        }
    }
}

// The function of buying passive items
void ShopSection::passiveItem()
{
    while (true)
    {
        cout << color::YELLOW << "[1] Firearms" << endl;
        cout << "[2] Meele Weapons" << endl;
        cout << "[3] Back" << color::RED << endl;

        int select{};
        cin >> select;
        cout << RESET << endl;

        if (select == 1)
        {
            firearm();
        }

        else if (select == 2)
        {
            meeleWeapons();
        }

        else if (select == 3)
        {
            break;
        }
    }
}

// Purchase confirmation function
short ShopSection::buyItem()
{
    cout << color::YELLOW << "Do you want to buy this item?" << endl;
    cout << "[1] Yes" << endl;
    cout << "[2] No" << color::RED << endl;
    int wantBuy{};
    cin >> wantBuy;
    cout << RESET << endl;
    return wantBuy;
}

// Firearm purchase function
void ShopSection::firearm()
{
    while (true)
    {
        int counter{1};
        short ak47Id{}, pistolId{}, shotgunId{}, uziSubmachineGunId{}, backId{};
        cout << color::YELLOW;
        for (auto it = allItems.begin(); it != allItems.end(); it++)
        {
            if ((*it)->getName() == "AK47")
            {
                cout << "[" << counter << "] "
                     << "AK47" << endl;
                ak47Id = counter;
                counter++;
            }
            else if ((*it)->getName() == "Pistol")
            {
                cout << "[" << counter << "] "
                     << "Pistol" << endl;
                pistolId = counter;
                counter++;
            }
            else if ((*it)->getName() == "Shotgun")
            {
                cout << "[" << counter << "] "
                     << "Shotgun" << endl;
                shotgunId = counter;
                counter++;
            }
            else if ((*it)->getName() == "Uzi Submachine Gun")
            {
                cout << "[" << counter << "] "
                     << "Uzi Submachine Gun" << endl;
                uziSubmachineGunId = counter;
                counter++;
            }
        }
        backId = counter;
        cout << "[" << counter << "] "
             << "back" << color::RED << endl;

        int selectedOption;
        cin >> selectedOption;
        cout << RESET << endl;

        if (selectedOption == ak47Id)
        {
            FightSection::ak47.printAttribute();
            cout << endl;
            int wantBuy{buyItem()};
            if (wantBuy == 1)
            {
                if (player.getPlayerCash() < FightSection::ak47.getPrice())
                {
                    cout << color::RED << "You don't have enough cash to buy this firearm." << RESET << endl;
                    cout << endl;
                }

                else
                {
                    player.cashDecrease(FightSection::ak47.getPrice());
                    FightSection::ak47.decreaseShopAmount();
                    inventory.addItem(&FightSection::ak47);
                    cout << color::GREEN << "Was purchased. "
                         << "(The remaining money: " << player.getPlayerCash() << "$)" << RESET << endl;
                    cout << endl;
                }
            }

            else if (wantBuy == 2)
            {
                continue;
            }
        }

        else if (selectedOption == pistolId)
        {
            FightSection::pistol.printAttribute();
            cout << endl;
            int wantBuy{buyItem()};
            if (wantBuy == 1)
            {
                if (player.getPlayerCash() < FightSection::pistol.getPrice())
                {
                    cout << color::RED << "You don't have enough cash to buy this firearm." << RESET << endl;
                    cout << endl;
                }

                else
                {
                    player.cashDecrease(FightSection::pistol.getPrice());
                    FightSection::pistol.decreaseShopAmount();
                    inventory.addItem(&FightSection::pistol);
                    cout << color::GREEN << "Was purchased. "
                         << "(The remaining money: " << player.getPlayerCash() << "$)" << RESET << endl;
                    cout << endl;
                }
            }

            else if (wantBuy == 2)
            {
                continue;
            }
        }

        else if (selectedOption == shotgunId)
        {
            FightSection::shotgun.printAttribute();
            cout << endl;
            int wantBuy{buyItem()};
            if (wantBuy == 1)
            {
                if (player.getPlayerCash() < FightSection::shotgun.getPrice())
                {
                    cout << color::RED << "You don't have enough cash to buy this firearm." << RESET << endl;
                    cout << endl;
                }

                else
                {
                    player.cashDecrease(FightSection::shotgun.getPrice());
                    FightSection::shotgun.decreaseShopAmount();
                    inventory.addItem(&FightSection::shotgun);
                    cout << color::GREEN << "Was purchased. "
                         << "(The remaining money: " << player.getPlayerCash() << "$)" << RESET << endl;
                    cout << endl;
                }
            }

            else if (wantBuy == 2)
            {
                continue;
            }
        }

        else if (selectedOption == uziSubmachineGunId)
        {
            FightSection::uziSubmachineGun.printAttribute();
            cout << endl;
            int wantBuy{buyItem()};
            if (wantBuy == 1)
            {
                if (player.getPlayerCash() < FightSection::uziSubmachineGun.getPrice())
                {
                    cout << color::RED << "You don't have enough cash to buy this firearm." << RESET << endl;
                    cout << endl;
                }

                else
                {
                    player.cashDecrease(FightSection::uziSubmachineGun.getPrice());
                    FightSection::uziSubmachineGun.decreaseShopAmount();
                    inventory.addItem(&FightSection::uziSubmachineGun);
                    cout << color::GREEN << "Was purchased. "
                         << "(The remaining money: " << player.getPlayerCash() << "$)" << RESET << endl;
                    cout << endl;
                }
            }

            else if (wantBuy == 2)
            {
                continue;
            }
        }

        else if (selectedOption == backId)
        {
            break;
        }

        updateShop();
    }
}

// meeleWeapons purchase function
void ShopSection::meeleWeapons()
{

    while (true)
    {
        int counter{1};
        short knifeId{}, swordId{}, axeId{}, nunchakuId{}, backId{};
        cout << color::YELLOW;
        for (auto it = allItems.begin(); it != allItems.end(); it++)
        {
            if ((*it)->getName() == "Knife")
            {
                cout << "[" << counter << "] "
                     << "Knife" << endl;
                knifeId = counter;
                counter++;
            }
            else if ((*it)->getName() == "Sword")
            {
                cout << "[" << counter << "] "
                     << "Sword" << endl;
                swordId = counter;
                counter++;
            }
            else if ((*it)->getName() == "Axe")
            {
                cout << "[" << counter << "] "
                     << "Axe" << endl;
                axeId = counter;
                counter++;
            }
            else if ((*it)->getName() == "Nunchaku")
            {
                cout << "[" << counter << "] "
                     << "Nunchaku" << endl;
                nunchakuId = counter;
                counter++;
            }
        }
        backId = counter;
        cout << "[" << counter << "] "
             << "back" << color::RED << endl;

        int selectedOption;
        cin >> selectedOption;
        cout << RESET << endl;

        if (selectedOption == knifeId)
        {
            FightSection::knife.printAttribute();
            cout << endl;
            int wantBuy{buyItem()};
            if (wantBuy == 1)
            {
                if (player.getPlayerCash() < FightSection::knife.getPrice())
                {
                    cout << color::RED << "You don't have enough cash to buy this meeleWeapon." << RESET << endl;
                    cout << endl;
                }

                else
                {
                    player.cashDecrease(FightSection::knife.getPrice());
                    FightSection::knife.decreaseShopAmount();
                    inventory.addItem(&FightSection::knife);
                    cout << color::GREEN << "Was purchased. "
                         << "(The remaining money: " << player.getPlayerCash() << "$)" << RESET << endl;
                    cout << endl;
                }
            }

            else if (wantBuy == 2)
            {
                continue;
            }
        }

        else if (selectedOption == swordId)
        {
            FightSection::sword.printAttribute();
            cout << endl;
            int wantBuy{buyItem()};
            if (wantBuy == 1)
            {
                if (player.getPlayerCash() < FightSection::sword.getPrice())
                {
                    cout << color::RED << "You don't have enough cash to buy this meeleWeapon." << RESET << endl;
                    cout << endl;
                }

                else
                {
                    player.cashDecrease(FightSection::sword.getPrice());
                    FightSection::sword.decreaseShopAmount();
                    inventory.addItem(&FightSection::sword);
                    cout << color::GREEN << "Was purchased. "
                         << "(The remaining money: " << player.getPlayerCash() << "$)" << RESET << endl;
                    cout << endl;
                }
            }

            else if (wantBuy == 2)
            {
                continue;
            }
        }

        else if (selectedOption == axeId)
        {
            FightSection::axe.printAttribute();
            cout << endl;
            int wantBuy{buyItem()};
            if (wantBuy == 1)
            {
                if (player.getPlayerCash() < FightSection::axe.getPrice())
                {
                    cout << color::RED << "You don't have enough cash to buy this meeleWeapon." << RESET << endl;
                    cout << endl;
                }

                else
                {
                    player.cashDecrease(FightSection::axe.getPrice());
                    FightSection::axe.decreaseShopAmount();
                    inventory.addItem(&FightSection::axe);
                    cout << color::GREEN << "Was purchased. "
                         << "(The remaining money: " << player.getPlayerCash() << "$)" << RESET << endl;
                    cout << endl;
                }
            }

            else if (wantBuy == 2)
            {
                continue;
            }
        }

        else if (selectedOption == nunchakuId)
        {
            FightSection::nunchaku.printAttribute();
            cout << endl;
            int wantBuy{buyItem()};
            if (wantBuy == 1)
            {
                if (player.getPlayerCash() < FightSection::nunchaku.getPrice())
                {
                    cout << color::RED << "You don't have enough cash to buy this meeleWeapon." << RESET << endl;
                    cout << endl;
                }

                else
                {
                    player.cashDecrease(FightSection::nunchaku.getPrice());
                    FightSection::nunchaku.decreaseShopAmount();
                    inventory.addItem(&FightSection::nunchaku);
                    cout << color::GREEN << "Was purchased. "
                         << "(The remaining money: " << player.getPlayerCash() << "$)" << RESET << endl;
                    cout << endl;
                }
            }

            else if (wantBuy == 2)
            {
                continue;
            }
        }

        else if (selectedOption == backId)
        {
            break;
        }

        updateShop();
    }
}

// throwableItem purchase function
void ShopSection::throwableItem()
{

    while (true)
    {
        int counter{1};
        short grenadeId{}, flashbangId{}, c4Id{}, rpg7Id{}, backId{};
        cout << color::YELLOW;
        for (auto it = allItems.begin(); it != allItems.end(); it++)
        {
            if ((*it)->getName() == "Grenade")
            {
                cout << "[" << counter << "] "
                     << "Grenade" << endl;
                grenadeId = counter;
                counter++;
            }

            else if ((*it)->getName() == "Flashbang")
            {
                cout << "[" << counter << "] "
                     << "Flashbang" << endl;
                flashbangId = counter;
                counter++;
            }

            else if ((*it)->getName() == "C4")
            {
                cout << "[" << counter << "] "
                     << "C4" << endl;
                c4Id = counter;
                counter++;
            }

            else if ((*it)->getName() == "RPG7")
            {
                cout << "[" << counter << "] "
                     << "RPG7" << endl;
                rpg7Id = counter;
                counter++;
            }
        }
        backId = counter;
        cout << "[" << counter << "] "
             << "back" << color::RED << endl;

        int select;
        cin >> select;
        cout << RESET << endl;

        if (select == grenadeId)
        {
            FightSection::grenade.printAttribute();
            cout << endl;
            int wantBuy{buyItem()};
            if (wantBuy == 1)
            {
                if (player.getPlayerCash() < FightSection::grenade.getPrice())
                {
                    cout << color::RED << "You don't have enough cash to buy this throwable item." << RESET << endl;
                    cout << endl;
                }

                else
                {
                    player.cashDecrease(FightSection::grenade.getPrice());
                    FightSection::grenade.decreaseShopAmount();
                    inventory.addItem(&FightSection::grenade);
                    cout << color::GREEN << "Was purchased. "
                         << "(The remaining money: " << player.getPlayerCash() << "$)" << RESET << endl;
                    cout << endl;
                }
            }

            else if (wantBuy == 2)
            {
                continue;
            }
        }

        else if (select == flashbangId)
        {
            FightSection::flashbang.printAttribute();
            cout << endl;
            int wantBuy{buyItem()};
            if (wantBuy == 1)
            {
                if (player.getPlayerCash() < FightSection::flashbang.getPrice())
                {
                    cout << color::RED << "You don't have enough cash to buy this throwable item." << RESET << endl;
                    cout << endl;
                }

                else
                {
                    player.cashDecrease(FightSection::flashbang.getPrice());
                    FightSection::flashbang.decreaseShopAmount();
                    inventory.addItem(&FightSection::flashbang);
                    cout << color::GREEN << "Was purchased. "
                         << "(The remaining money: " << player.getPlayerCash() << "$)" << RESET << endl;
                    cout << endl;
                }
            }

            else if (wantBuy == 2)
            {
                continue;
            }
        }

        else if (select == c4Id)
        {
            FightSection::c4.printAttribute();
            cout << endl;
            int wantBuy{buyItem()};
            if (wantBuy == 1)
            {
                if (player.getPlayerCash() < FightSection::c4.getPrice())
                {
                    cout << color::RED << "You don't have enough cash to buy this throwable item." << RESET << endl;
                    cout << endl;
                }

                else
                {
                    player.cashDecrease(FightSection::c4.getPrice());
                    FightSection::c4.decreaseShopAmount();
                    inventory.addItem(&FightSection::c4);
                    cout << color::GREEN << "Was purchased. "
                         << "(The remaining money: " << player.getPlayerCash() << "$)" << RESET << endl;
                    cout << endl;
                }
            }

            else if (wantBuy == 2)
            {
                continue;
            }
        }

        else if (select == rpg7Id)
        {
            FightSection::rpg7.printAttribute();
            cout << endl;
            int wantBuy{buyItem()};
            if (wantBuy == 1)
            {
                if (player.getPlayerCash() < FightSection::rpg7.getPrice())
                {
                    cout << color::RED << "You don't have enough cash to buy this throwable item." << RESET << endl;
                    cout << endl;
                }

                else
                {
                    player.cashDecrease(FightSection::rpg7.getPrice());
                    FightSection::rpg7.decreaseShopAmount();
                    inventory.addItem(&FightSection::rpg7);
                    cout << color::GREEN << "Was purchased. "
                         << "(The remaining money: " << player.getPlayerCash() << "$)" << RESET << endl;
                    cout << endl;
                }
            }

            else if (wantBuy == 2)
            {
                continue;
            }
        }

        else if (select == backId)
        {
            break;
        }

        updateShop();
    }
}

// consumableItem purchase function
void ShopSection::consumableItem()
{
    while (true)
    {
        int counter{1};
        short cookieId{}, sodaId{}, chocolateId{}, hypeId{}, backId{};
        cout << color::YELLOW;
        for (auto it = allItems.begin(); it != allItems.end(); it++)
        {
            if ((*it)->getName() == "Cookie")
            {
                cout << "[" << counter << "] "
                     << "Cookie" << endl;
                cookieId = counter;
                counter++;
            }

            else if ((*it)->getName() == "Soda")
            {
                cout << "[" << counter << "] "
                     << "Soda" << endl;
                sodaId = counter;
                counter++;
            }

            else if ((*it)->getName() == "Chocolate")
            {
                cout << "[" << counter << "] "
                     << "Chocolate" << endl;
                chocolateId = counter;
                counter++;
            }

            else if ((*it)->getName() == "Hype")
            {
                cout << "[" << counter << "] "
                     << "Hype" << endl;
                hypeId = counter;
                counter++;
            }
        }
        backId = counter;
        cout << "[" << counter << "] "
             << "back" << color::RED << endl;

        int select;
        cin >> select;
        cout << RESET << endl;

        if (select == cookieId)
        {
            FightSection::cookie.printAttribute();
            cout << endl;
            int wantBuy{buyItem()};
            if (wantBuy == 1)
            {
                if (player.getPlayerCash() < FightSection::cookie.getPrice())
                {
                    cout << color::RED << "You don't have enough cash to buy this consumable item." << RESET << endl;
                    cout << endl;
                }

                else
                {
                    player.cashDecrease(FightSection::cookie.getPrice());
                    FightSection::cookie.decreaseShopAmount();
                    inventory.addItem(&FightSection::cookie);
                    cout << color::GREEN << "Was purchased. "
                         << "(The remaining money: " << player.getPlayerCash() << "$)" << RESET << endl;
                    cout << endl;
                }
            }

            else if (wantBuy == 2)
            {
                continue;
            }
        }

        else if (select == sodaId)
        {
            FightSection::soda.printAttribute();
            cout << endl;
            int wantBuy{buyItem()};
            if (wantBuy == 1)
            {
                if (player.getPlayerCash() < FightSection::soda.getPrice())
                {
                    cout << color::RED << "You don't have enough cash to buy this consumable item." << RESET << endl;
                    cout << endl;
                }

                else
                {
                    player.cashDecrease(FightSection::soda.getPrice());
                    FightSection::soda.decreaseShopAmount();
                    inventory.addItem(&FightSection::soda);
                    cout << color::GREEN << "Was purchased. "
                         << "(The remaining money: " << player.getPlayerCash() << "$)" << RESET << endl;
                    cout << endl;
                }
            }

            else if (wantBuy == 2)
            {
                continue;
            }
        }

        else if (select == chocolateId)
        {
            FightSection::chocolate.printAttribute();
            cout << endl;
            int wantBuy{buyItem()};
            if (wantBuy == 1)
            {
                if (player.getPlayerCash() < FightSection::chocolate.getPrice())
                {
                    cout << color::RED << "You don't have enough cash to buy this consumable item." << RESET << endl;
                    cout << endl;
                }

                else
                {
                    player.cashDecrease(FightSection::chocolate.getPrice());
                    FightSection::chocolate.decreaseShopAmount();
                    inventory.addItem(&FightSection::chocolate);
                    cout << color::GREEN << "Was purchased. "
                         << "(The remaining money: " << player.getPlayerCash() << "$)" << RESET << endl;
                    cout << endl;
                }
            }

            else if (wantBuy == 2)
            {
                continue;
            }
        }

        else if (select == hypeId)
        {
            FightSection::hype.printAttribute();
            cout << endl;
            int wantBuy{buyItem()};
            if (wantBuy == 1)
            {
                if (player.getPlayerCash() < FightSection::hype.getPrice())
                {
                    cout << color::RED << "You don't have enough cash to buy this consumable item." << RESET << endl;
                    cout << endl;
                }

                else
                {
                    player.cashDecrease(FightSection::hype.getPrice());
                    FightSection::hype.decreaseShopAmount();
                    inventory.addItem(&FightSection::hype);
                    cout << color::GREEN << "Was purchased. "
                         << "(The remaining money: " << player.getPlayerCash() << "$)" << RESET << endl;
                    cout << endl;
                }
            }

            else if (wantBuy == 2)
            {
                continue;
            }
        }

        else if (select == backId)
        {
            break;
        }

        updateShop();
    }
}

// Purchase function from the store
PlayerController ShopSection::startShop()
{
    story shopkeeperStory;
    shopkeeperStory.printShopkeeperStory();
    cout << UNDERLINED << BOLD << color::LIGHTBLUE << "(your money: " << player.getPlayerCash() << "$)" << RESET << endl;
    cout << endl;
    while (true)
    {
        cout << color::YELLOW << "[1] Passive Items" << endl;
        cout << "[2] Throable Items" << endl;
        cout << "[3] Consumable Items" << endl;
        cout << "[4] Exit" << color::RED << endl;

        int select{};
        cin >> select;
        cout << RESET << endl;

        if (select == 1)
        {
            passiveItem();
        }

        else if (select == 2)
        {
            throwableItem();
        }

        else if (select == 3)
        {
            consumableItem();
        }

        if (select == 4)
        {
            break;
        }
    }

    return player;
}