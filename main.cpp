#include <iostream>
#include <string>
#include <windows.h>
#include "shop.h"
#include "fight.h"
#include "constants.h"
#include "randomNumber.h"

using namespace std;

int main()
{
    // Get player information
    PlayerController player = getPlayerInfo();

    // Create instances of ZombieFactory and HumanEnemyFactory
    ZombieFactory zombieFactory;
    HumanEnemyFactory humanFactory;
    // Counter to keep track of days survived
    short dayCounter{1};

    // Main game loop
    while (player.getPlayerStamina() >= 0 && player.getPlayerHp() >= 0)
    {
        // Random number for deciding fight type
        short fightRandomNumber{generateRandomNumber()};

        // Random number for deciding section type
        short sectionRandomNumber{generateRandomNumber()};

        // 70% chance for a fight encounter
        if (sectionRandomNumber < 70)
        {
            // 50% chance for encountering a zombie
            if (fightRandomNumber < 50)
            {
                // Generate a zombie and start a fight
                ZombieController zombie;
                zombie = zombieFactory.generateZombie(player);
                FightSection fight{player, zombie};
                cout << color::RED << "Hey, a zombie is approaching..." << RESET << endl;
                Sleep(3000);
                system("cls");
                cout << color::RED << "Day" << dayCounter << ": Fight with " << zombie.getName() << RESET << endl;
                cout << endl;
                cout << color::YELLOW << "Prepare for battle!" << RESET << endl;
                cout << endl;
                player = fight.startFightZombie();
            }

            else
            {
                // Generate a human enemy and start a fight
                humanEnemyController humanEnemy;
                humanEnemy = humanFactory.generateHumanEnemy(player);
                FightSection fight{player, humanEnemy};
                cout << color::RED << "Hey, a Human Enemy is approaching..." << RESET << endl;
                Sleep(3000);
                system("cls");
                cout << color::RED << "Day" << dayCounter << ": Fight with Human Enemy" << RESET << endl;
                cout << endl;
                cout << color::YELLOW << "Prepare for battle!" << RESET << endl;
                cout << endl;

                player = fight.startFightHumanEnemy();
            }
        }

        // Visit the shop section
        else
        {
            cout << color::GREEN << "Hey, you're heading to the store." << RESET << endl;
            Sleep(3000);
            system("cls");
            cout << color::GREEN << "Day" << dayCounter << ": Shop" << RESET << endl;
            cout << endl;
            ShopSection shopsection(player);
            player = shopsection.startShop();
        }

        // Check player's status after the encounter or shop visit
        if (player.getPlayerStamina() < 0 || player.getPlayerHp() < 0)
        {
            break;
        }
        dayCounter++;
    }

    return 0;
}