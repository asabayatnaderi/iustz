#include <iostream>
#include <conio.h>
#include <windows.h>
#include "shop.h"



using namespace std;

void shop(PlayerController &player)
{
    AK47 ak47("AK47", 10, 1000, 5);
    Pistol pistol("pistol", 5, 500, 2);
    Shotgun shotgun("Shotgun", 15, 1500, 7);
    UziSubmachineGun uziSubmachineGun("UziSubmachineGun", 10, 1000, 5);
    Knife knife("Knife", 2, 250, 1);
    Sword sword("Sword", 10, 1000, 5);
    Axe axe("Axe", 15, 1500, 7);
    Nunchaku nunchaku("Nunchaku", 10, 1000, 5);
    Grenade grenade("Grenade", 30, 3000, 5);
    Flashbang flashbang("Flashbang", 25, 2500, 2);
    C4 c4("C4", 45, 4500, 5);
    RPG7 rpg7("RPG7", 60, 6000, 10);
    Cookie cookie("Cookie", 600, false);
    Soda soda("Soda", 200, false);
    Chocolate chocolate("Chocolate", 600, false);
    Hype hype("Hype", 200, false);
    BulletproofVest bulletproofvest("BulletproofVest", 1000, 5);
    Shield shield("Shield", 1000, 5);
    const string greetings[3] = 
    {
        "Hello and welcome stanger to the best shop in the history of mankind!\n",
        "We present many items and great weapons in order for you to survive in this crazy and fascinating!\n",
        "Come on and choose your desired weapons.\n"
    };
    for (int i=0; i < 3; i++)
    {
        cout << greetings[i];
    }
    const string shopMenu[24] = 
    {
        "Firearms: ",
        "   [1] AK47",
        "   [2] Pistol",
        "   [3] Shotgun",
        "   [4] UziSubmachineGun",
        "Meele Weapons: ",
        "   [5] Knife",
        "   [6] Sword",
        "   [7] Axe",
        "   [8] Nunchaku",
        "Throable Weapons:",
        "   [9] Grenade",
        "   [10] Flashbang",
        "   [11] C4",
        "   [12] RPG7",
        "Items: ",
        "   [13] Cookie",
        "   [14] Soda",
        "   [15] Chocolate",
        "   [16] Hype",
        "Special Weaponary: ",
        "   [17] Bullet Proof Vest",
        "   [18] Shield",
        "   [19] EXIT"
    };
    int selectedOption, character;
    while(true) {
        for(int i=0; i < 24; i++) {
            cout << shopMenu[i] << endl;
        }
        cout << "Choose the item you want to buy.(Enter the number behind an item to choose it)" << endl;
        cout << "If you want to leave just Enter number 19" << endl;
        cin >> selectedOption;
        if (selectedOption == 1) {
            while (true) {
                system("cls");
                ak47.printAttribute();
                if(player.getPlayerCash() < ak47.getPrice())
                {
                    cout << "You don't have enough cash to buy this firearm." << endl;
                }
                else
                {
                    cout << "Are you sure if you want to buy this? If yes click ENTER." << endl;;
                    character = _getch();
                    if(character == ENTER_KEY)
                    {

                    }
                }
                cout << "Click ESC to get back to the shop menu." << endl;
                character = _getch();
                if (character == ESC)
                {
                    break;
                }
            }
        }
        else if (selectedOption == 2) {
            while (true) {
                system("cls");
                pistol.printAttribute();
                if(player.getPlayerCash() < pistol.getPrice())
                {
                    cout << "You don't have enough cash to buy this firearm." << endl;
                }
                else
                {
                    cout << "Are you sure if you want to buy this? If yes click ENTER." << endl;;
                    character = _getch();
                    if(character == ENTER_KEY)
                    {

                    }
                }
                cout << "Click ESC to get back to the shop menu." << endl;
                character = _getch();
                if (character == ESC)
                {
                    break;
                }
            }
        }
        else if (selectedOption == 3) {
            while (true) {
                system("cls");
                shotgun.printAttribute();
                if(player.getPlayerCash() < shotgun.getPrice())
                {
                    cout << "You don't have enough cash to buy this firearm." << endl;
                }
                else
                {
                    cout << "Are you sure if you want to buy this? If yes click ENTER." << endl;;
                    character = _getch();
                    if(character == ENTER_KEY)
                    {

                    }
                }
                cout << "Click ESC to get back to the shop menu." << endl;
                character = _getch();
                if (character == ESC)
                {
                    break;
                }
            }
        }
        else if (selectedOption == 4) {
            while (true) {
                system("cls");
                uziSubmachineGun.printAttribute();
                if(player.getPlayerCash() < uziSubmachineGun.getPrice())
                {
                    cout << "You don't have enough cash to buy this firearm." << endl;
                }
                else
                {
                    cout << "Are you sure if you want to buy this? If yes click ENTER." << endl;;
                    character = _getch();
                    if(character == ENTER_KEY)
                    {

                    }
                }
                cout << "Click ESC to get back to the shop menu." << endl;
                character = _getch();
                if (character == ESC)
                {
                    break;
                }
            }
        }
        else if (selectedOption == 5) {
            while (true) {
                system("cls");
                knife.printAttribute();
                if(player.getPlayerCash() < knife.getPrice())
                {
                    cout << "You don't have enough cash to buy this meele weapon." << endl;
                }
                else
                {
                    cout << "Are you sure if you want to buy this? If yes click ENTER." << endl;;
                    character = _getch();
                    if(character == ENTER_KEY)
                    {

                    }
                }
                cout << "Click ESC to get back to the shop menu." << endl;
                character = _getch();
                if (character == ESC)
                {
                    break;
                }
            }
        }
        else if (selectedOption == 6) {
            while (true) {
                system("cls");
                sword.printAttribute();
                if(player.getPlayerCash() < sword.getPrice())
                {
                    cout << "You don't have enough cash to buy this meele weapon." << endl;
                }
                else
                {
                    cout << "Are you sure if you want to buy this? If yes click ENTER." << endl;;
                    character = _getch();
                    if(character == ENTER_KEY)
                    {

                    }
                }
                cout << "Click ESC to get back to the shop menu." << endl;
                character = _getch();
                if (character == ESC)
                {
                    break;
                }
            }
        }
        else if (selectedOption == 7) {
            while (true) {
                system("cls");
                axe.printAttribute();
                if(player.getPlayerCash() < axe.getPrice())
                {
                    cout << "You don't have enough cash to buy this meele weapon." << endl;
                }
                else
                {
                    cout << "Are you sure if you want to buy this? If yes click ENTER." << endl;;
                    character = _getch();
                    if(character == ENTER_KEY)
                    {

                    }
                }
                cout << "Click ESC to get back to the shop menu." << endl;
                character = _getch();
                if (character == ESC)
                {
                    break;
                }
            }
        }
        else if (selectedOption == 8) {
            while (true) {
                system("cls");
                nunchaku.printAttribute();
                if(player.getPlayerCash() < nunchaku.getPrice())
                {
                    cout << "You don't have enough cash to buy this meele weapon." << endl;
                }
                else
                {
                    cout << "Are you sure if you want to buy this? If yes click ENTER." << endl;;
                    character = _getch();
                    if(character == ENTER_KEY)
                    {

                    }
                }
                cout << "Click ESC to get back to the shop menu." << endl;
                character = _getch();
                if (character == ESC)
                {
                    break;
                }
            }
        }
        else if (selectedOption == 9) {
            while (true) {
                system("cls");
                grenade.printAttribute();
                if(player.getPlayerCash() < grenade.getPrice())
                {
                    cout << "You don't have enough cash to buy this throwable weapon." << endl;
                }
                else
                {
                    cout << "Are you sure if you want to buy this? If yes click ENTER." << endl;;
                    character = _getch();
                    if(character == ENTER_KEY)
                    {

                    }
                }
                cout << "Click ESC to get back to the shop menu." << endl;
                character = _getch();
                if (character == ESC)
                {
                    break;
                }
            }
        }
        else if (selectedOption == 10) {
            while (true) {
                system("cls");
                flashbang.printAttribute();
                if(player.getPlayerCash() < flashbang.getPrice())
                {
                    cout << "You don't have enough cash to buy this throwable weapon." << endl;
                }
                else
                {
                    cout << "Are you sure if you want to buy this? If yes click ENTER." << endl;;
                    character = _getch();
                    if(character == ENTER_KEY)
                    {

                    }
                }
                cout << "Click ESC to get back to the shop menu." << endl;
                character = _getch();
                if (character == ESC)
                {
                    break;
                }
            }
        }
        else if (selectedOption == 11) {
            while (true) {
                system("cls");
                c4.printAttribute();
                if(player.getPlayerCash() < c4.getPrice())
                {
                    cout << "You don't have enough cash to buy this throwable weapon." << endl;
                }
                else
                {
                    cout << "Are you sure if you want to buy this? If yes click ENTER." << endl;;
                    character = _getch();
                    if(character == ENTER_KEY)
                    {

                    }
                }
                cout << "Click ESC to get back to the shop menu." << endl;
                character = _getch();
                if (character == ESC)
                {
                    break;
                }
            }
        }
        else if (selectedOption == 12) {
            while (true) {
                system("cls");
                rpg7.printAttribute();
                if(player.getPlayerCash() < rpg7.getPrice())
                {
                    cout << "You don't have enough cash to buy this throwable weapon." << endl;
                }
                else
                {
                    cout << "Are you sure if you want to buy this? If yes click ENTER." << endl;;
                    character = _getch();
                    if(character == ENTER_KEY)
                    {

                    }
                }
                cout << "Click ESC to get back to the shop menu." << endl;
                character = _getch();
                if (character == ESC)
                {
                    break;
                }
            }
        }
        else if (selectedOption == 13) {
            while (true) {
                system("cls");
                cookie.printAttribute();
                if(player.getPlayerCash() < cookie.getPrice())
                {
                    cout << "You don't have enough cash to buy this item." << endl;
                }
                else
                {
                    cout << "Are you sure if you want to buy this? If yes click ENTER." << endl;;
                    character = _getch();
                    if(character == ENTER_KEY)
                    {

                    }
                }
                cout << "Click ESC to get back to the shop menu." << endl;
                character = _getch();
                if (character == ESC)
                {
                    break;
                }
            }
        }
        else if (selectedOption == 14) {
            while (true) {
                system("cls");
                soda.printAttribute();
                if(player.getPlayerCash() < soda.getPrice())
                {
                    cout << "You don't have enough cash to buy this item." << endl;
                }
                else
                {
                    cout << "Are you sure if you want to buy this? If yes click ENTER." << endl;;
                    character = _getch();
                    if(character == ENTER_KEY)
                    {

                    }
                }
                cout << "Click ESC to get back to the shop menu." << endl;
                character = _getch();
                if (character == ESC)
                {
                    break;
                }
            }
        }
        else if (selectedOption == 15) {
            while (true) {
                system("cls");
                chocolate.printAttribute();
                if(player.getPlayerCash() < chocolate.getPrice())
                {
                    cout << "You don't have enough cash to buy this item." << endl;
                }
                else
                {
                    cout << "Are you sure if you want to buy this? If yes click ENTER." << endl;;
                    character = _getch();
                    if(character == ENTER_KEY)
                    {

                    }
                }
                cout << "Click ESC to get back to the shop menu." << endl;
                character = _getch();
                if (character == ESC)
                {
                    break;
                }
            }
        }
        else if (selectedOption == 16) {
            while (true) {
                system("cls");
                hype.printAttribute();
                if(player.getPlayerCash() < hype.getPrice())
                {
                    cout << "You don't have enough cash to buy this item." << endl;
                }
                else
                {
                    cout << "Are you sure if you want to buy this? If yes click ENTER." << endl;;
                    character = _getch();
                    if(character == ENTER_KEY)
                    {

                    }
                }
                cout << "Click ESC to get back to the shop menu." << endl;
                character = _getch();
                if (character == ESC)
                {
                    break;
                }
            }
        }
        else if (selectedOption == 17) {
            while (true) {
                system("cls");
                bulletproofvest.printAttribute();
                if(player.getPlayerCash() < bulletproofvest.getPrice())
                {
                    cout << "You don't have enough cash to buy this special weaponary." << endl;
                }
                else
                {
                    cout << "Are you sure if you want to buy this? If yes click ENTER." << endl;;
                    character = _getch();
                    if(character == ENTER_KEY)
                    {

                    }
                }
                cout << "Click ESC to get back to the shop menu." << endl;
                character = _getch();
                if (character == ESC)
                {
                    break;
                }
            }
        }
        else if (selectedOption == 18) {
            while (true) {
                system("cls");
                shield.printAttribute();
                if(player.getPlayerCash() < shield.getPrice())
                {
                    cout << "You don't have enough cash to buy this special weaponary." << endl;
                }
                else
                {
                    cout << "Are you sure if you want to buy this? If yes click ENTER." << endl;;
                    character = _getch();
                    if(character == ENTER_KEY)
                    {

                    }
                }
                cout << "Click ESC to get back to the shop menu." << endl;
                character = _getch();
                if (character == ESC)
                {
                    break;
                }
            }
        }
        else if (selectedOption == 19) {
            cout << "Are you sure you want to exit the shop? If yes please click ENTER";
            character = _getch();
            if(character == ENTER_KEY)
            {
                break;
            }
        }
        else {
            cout << "You picked the wrong number, try again.";
        }
        system("cls");
    }
}