#include <iostream>
#include <ctime>
#include "player.h"
#include "zombieEnemy.h"
#include "passiveItem.h"

using namespace std;

class Fight
{
private:
    PlayerController player;
    ZombieController zombie;
    int playerDamage{};
    int playerStaminaCost{};
    int zombieDamage{};
    int zombieStaminaCost{};

public:
    Fight(const PlayerController &player, const ZombieController &zombie) : player(player), zombie(zombie) {}

    void playerAttack(PlayerController &attacker, ZombieController &defender)
    {
        if (attacker.getPlayerWeaponName() == "AK47")
        {
            AK47 ak47;
            if (player.getPlayerLevel() <= 3)
            {
                ak47 = {"AK47", 1000, 10, 8};
            }

            else if (player.getPlayerLevel() <= 6)
            {
                ak47 = {"AK47", 1000, 15, 11};
            }

            else if (player.getPlayerLevel() <= 9)
            {
                ak47 = {"AK47", 1000, 20, 13};
            }

            else if (player.getPlayerLevel() <= 12)
            {
                ak47 = {"AK47", 1000, 25, 15};
            }

            playerDamage = ak47.getDamage();
            playerStaminaCost = ak47.getStaminaCost();
        }

        else if (attacker.getPlayerWeaponName() == "Pistol")
        {
            Pistol pistol;
            if (player.getPlayerLevel() <= 3)
            {
                pistol = {"Pistol", 500, 5, 4};
            }

            else if (player.getPlayerLevel() <= 6)
            {
                pistol = {"Pistol", 500, 9, 5};
            }

            else if (player.getPlayerLevel() <= 9)
            {
                pistol = {"Pistol", 500, 14, 6};
            }

            else if (player.getPlayerLevel() <= 12)
            {
                pistol = {"Pistol", 500, 19, 6};
            }

            playerDamage = pistol.getDamage();
            playerStaminaCost = pistol.getStaminaCost();
        }

        else if (attacker.getPlayerWeaponName() == "Knife")
        {
            Knife knife;
            if (player.getPlayerLevel() <= 3)
            {
                knife = {"Knife", 700, 7, 4};
            }

            else if (player.getPlayerLevel() <= 6)
            {
                knife = {"Knife", 700, 13, 6};
            }

            else if (player.getPlayerLevel() <= 9)
            {
                knife = {"Knife", 700, 18, 7};
            }

            else if (player.getPlayerLevel() <= 12)
            {
                knife = {"Knife", 700, 22, 8};
            }

            playerDamage = knife.getDamage();
            playerStaminaCost = knife.getStaminaCost();
        }

        else if (attacker.getPlayerWeaponName() == "Sword")
        {
            Sword sword;
            if (player.getPlayerLevel() <= 3)
            {
                sword = {"Sword", 800, 8, 6};
            }

            else if (player.getPlayerLevel() <= 6)
            {
                sword = {"Sword", 800, 14, 8};
            }

            else if (player.getPlayerLevel() <= 9)
            {
                sword = {"Sword", 800, 19, 10};
            }

            else if (player.getPlayerLevel() <= 12)
            {
                sword = {"Sword", 800, 22, 11};
            }

            playerDamage = sword.getDamage();
            playerStaminaCost = sword.getStaminaCost();
        }

        cout << "You try to attack " << zombie.getName() << ". (Stamina Cost: " << playerStaminaCost << "(50)"
             << ", Damage: " << playerDamage << ")" << endl;
        attacker.decreaseStamina(playerStaminaCost);
        defender.decreaseHp(playerDamage);
        cout << "Attack successful!" << endl;
    }

    void zombieAttack(PlayerController &attacker, ZombieController &defender)
    {
        srand(time(0));
        if (zombie.getZombieLevel() <= 3)
        {
            zombieDamage = (rand() % 3) + 5;
            zombieStaminaCost = (rand() % 3) + 5;
        }

        else if (zombie.getZombieLevel() <= 6)
        {
            zombieDamage = (rand() % 6) + 5;
            zombieStaminaCost = (rand() % 6) + 5;
        }

        else
        {
            zombieDamage = (rand() % 9) + 5;
            zombieStaminaCost = (rand() % 9) + 5;
        }

        zombieDamage = (rand() % 4) + 5;
        zombieStaminaCost = (rand() % 4) + 5;
        cout << "The " << zombie.getName() << " tries to attack you. (Stamina Cost: " << zombieStaminaCost << "(20)"
             << ", Damage: " << zombieDamage << ")" << endl;

        defender.decreaseStamina(zombieStaminaCost);
        attacker.decreaseHp(zombieDamage);
        cout << "Attack successful!" << endl;
    }

    PlayerController startFight()
    {
        cout << "A zombie approaches! Prepare for battle!" << endl;
        while (player.getPlayerHp() > 0 && zombie.getZombieHp() > 0 && player.getPlayerStamina() > 0 && zombie.getZombieStamina() > 0)
        {
            cout << "It's your turn body. Choose your action: " << endl;
            cout << "[1] Attack" << endl;
            cout << "[2] Character" << endl;
            cout << "[3] Inventrory" << endl;

            int actionChoice{};
            cin >> actionChoice;

            cout << endl;

            if (actionChoice == 1)
            {
                playerAttack(player, zombie);

                cout << endl;

                zombieAttack(player, zombie);

                if (player.getPlayerHp() <= 0 || player.getPlayerStamina() <= 0)
                {
                    cout << endl;
                    cout << "You have been defeated by the zombie." << endl;
                    cout << endl;
                    break;
                }

                if (zombie.getZombieHp() <= 0 || zombie.getZombieStamina() <= 0)
                {
                    cout << endl;
                    cout << "Congratulations! You defeated the zombie." << endl;
                    cout << endl;
                    player.spIncrease();
                    player.levelUp();
                    if (player.getPlayerLevel() <= 5)
                    {
                        player.cashIncrease(200);
                    }
                    else if (player.getPlayerLevel() <= 10)
                    {
                        player.cashIncrease(500);
                    }
                    else
                    {
                        player.cashIncrease(1000);
                    }
                    break;
                }

                cout << endl;

                cout << "your character is: " << endl;
                cout << "-HP: " << player.getPlayerHp() << endl;
                cout << "-Stamina: " << player.getPlayerStamina() << endl;
                cout << "-Level: " << player.getPlayerLevel() << endl;

                cout << endl;

                cout << zombie.getName() << " character is: " << endl;
                cout << "-HP: " << zombie.getZombieHp() << endl;
                cout << "-Stamina: " << zombie.getZombieStamina() << endl;
                cout << "-Level: " << zombie.getZombieLevel() << endl;

                cout << endl;
            }

            else if (actionChoice == 2)
            {
                player.displayPlayerInfo();
                cout << endl;
                cout << "What you wanna do?(your SP: " << player.getPlayerSp() << ")" << endl;
                cout << "[1] Intelligence" << endl;
                cout << "[2] Luck" << endl;
                cout << "[3] Firearm skill" << endl;
                cout << "[4] Meele weapon skill" << endl;
                cout << "[5] Change weapon" << endl;
                cout << "[6] exit" << endl;

                int choice{};
                cin >> choice;

                cout << endl;

                if (choice == 1)
                {
                    if (player.getPlayerSp() >= 0)
                    {
                        player.intelligenceIncrease();
                        player.spDecrease();
                        cout << "Intelligence upgraded!" << endl;
                    }

                    else
                    {
                        cout << "your skill points is not enough for upgrading!" << endl;
                    }
                }

                else if (choice == 2)
                {
                    if (player.getPlayerSp() >= 0)
                    {
                        player.spDecrease();
                        player.luckIncrease();
                        cout << "Luck upgraded!" << endl;
                    }

                    else
                    {
                        cout << "your skill points is not enough for upgrading!" << endl;
                    }
                }

                else if (choice == 3)
                {
                    if (player.getPlayerSp() > 0)
                    {
                        player.spDecrease();
                        player.firearmSkillIncrease();
                        cout << "Firearm skill upgraded!" << endl;
                    }

                    else
                    {
                        cout << "your skill points is not enough for upgrading!" << endl;
                    }
                }

                else if (choice == 4)
                {
                    if (player.getPlayerSp() > 0)
                    {
                        player.spDecrease();
                        player.meeleWeaponSkillIncrease();
                        cout << "Meele weapon skill upgraded!" << endl;
                    }

                    else
                    {
                        cout << "your skill points is not enough for upgrading!" << endl;
                    }
                }

                else if (choice == 5)
                {
                    cout << "which weapon do you want?" << endl;
                    cout << "[1] AK47" << endl;
                    cout << "[2] Pistol" << endl;
                    cout << "[3] Knife" << endl;
                    cout << "[4] Sword" << endl;

                    int weaponChoice{};
                    cin >> weaponChoice;
                    cout << endl;

                    string weapon{};

                    switch (weaponChoice)
                    {
                    case 1:
                        weapon = "AK47";
                        break;
                    case 2:
                        weapon = "Pistol";
                        break;
                    case 3:
                        weapon = "Knife";
                        break;
                    case 4:
                        weapon = "Sword";
                        break;
                    }

                    player.setPlayerWeaponName(weapon);
                    cout << "Your weapon changed successfuly!" << endl;
                }

                else if (choice == 6)
                {
                    continue;
                }
            }

            else if (actionChoice == 3)
            {
                // inventory
            }

            cout << endl;
        }
        return player;
    }
};