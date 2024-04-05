#include <iostream>
#include <conio.h>
#include "Weapons.h"

using namespace std;

#define UP_KEY 72
#define DOWN_KEY 80
#define Right_KEY 77
#define LEFT_KEY 75
#define ENTER_KEY 13

void shop()
{
    AK47 ak47("AK47", 15, 500, "bulletproofVest");
    pistol Pistol("Pistol", 10, 250, "bulletproofVest");
    knife Knife("Knife", 2, 50, "Shield");
    sword Sword("Sword", 20, 500, "Shield");
    gernade Gernade("Gernade", 50, 200, "This weapons can penetrate through everything");
    flashbang Flashbang("Flashbang", 25, 100, "This weapons can penetrate through everything");
    bulletproofVest BulletproofVest("BulletproofVest", 5, 200, "Cold Weapons");
    shield Shield("Shield", 5, 200, "Firearms");
    const string shopMenu[13] = 
    {
        "Firearms:",
        "   Pistol:",
        "   AK47:",
        "Cold Weapons:",
        "   Knife:",
        "   Sword:",
        "Throwable Weapons:",
        "   Gernade:",
        "   Flashbang:",
        "Special Weapons:",
        "   Bulletproof vest:",
        "   Shield:",
        "Back"
    };
    int character, selectedOption = 1;
    while(true)
    {
        for(int i=0; i < 13; i++)
        {
            if(i == selectedOption)
            {
                cout << color::rize(shopMenu[selectedOption], "Blue") << endl;
                switch (selectedOption)
                {
                case 1:
                    Pistol.printAttribute();
                    break;
                case 2:
                    ak47.printAttribute();
                    break;
                case 4:
                    Knife.printAttribute();
                    break;
                case 5:
                    Sword.printAttribute();
                    break;
                case 7:
                    Gernade.printAttribute();
                    break;
                case 8:
                    Flashbang.printAttribute();
                    break;
                case 10:
                    BulletproofVest.printAttribute();
                    break;
                case 11:
                    Shield.printAttribute();
                    break;
                }
            }
            else
            {
                cout << color::rize(shopMenu[i], "Red") << endl;
            }
        }
        character = _getch();
        if(character == UP_KEY)
        {
            if(selectedOption == 1)
            {
                selectedOption = 12;
            }
            else
            {
                selectedOption--;
                if(selectedOption == 3 || selectedOption == 6 || selectedOption == 9)
                {
                    selectedOption--;
                }
            }
        }
        else if(character == DOWN_KEY)
        {
            if(selectedOption == 12)
            {
                selectedOption = 1;
            }
            else
            {
                selectedOption++;
                if(selectedOption == 3 || selectedOption == 6 || selectedOption == 9)
                {
                    selectedOption++;
                }
            }
        }
        else if(character == ENTER_KEY)
        {
            if(selectedOption == 12)
            {
                break;
            }
        }
        system("cls");
    }
}

int main()
{
    shop();
}