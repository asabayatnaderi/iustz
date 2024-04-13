#pragma once

#include <string>
#include "player.h"

using namespace std;

// ZombieModel class represents the data of a zombie character
class ZombieModel : public CharacterModel
{
public:
    ZombieModel() = default;

    // Constructor to initialize ZombieModel object with provided data
    ZombieModel(const string &name, const string &gender, int hp, int stamina, int level);

    // Decrease zombie's health points
    void hpDecrease(int hp);

    // Decrease zombie's stamina
    void staminaDecrease(int stamina);
};

// ZombieView class represents the view of a zombie character
class ZombieView : public CharacterView
{
public:
    // Method to display all information of a zombie
    void showAllOfZombieInfo(ZombieModel &zombie);

    // Method to display some information of a zombie
    void showSomeOfZombieInfo(ZombieModel &zombie);
};

// ZombieController class represents the controller for zombie character operations
class ZombieController : public CharacterController
{
private:
    ZombieModel zombieModel{};
    ZombieView zombieView{};

public:
    ZombieController() = default;

    // Constructor to initialize ZombieController with zombie character data
    ZombieController(const string &name, const string &gender, int hp, int stamina, int level);

    // Decrease zombie's health points
    void decreaseHp(int hp);

    // Decrease zombie's stamina
    void decreaseStamina(int stamina);

    // Display all information of a zombie
    void displayAllOFZombieInfo();

    // Display some information of a zombie
    void displaySomeOfZombieInfo();

    // Getter methods
    int getZombieHp();
    int getZombieStamina();
    int getZombieLevel();
};

// ZombieFactory class represents a factory for creating zombie characters
class ZombieFactory
{
private:
    int hpBaseZombie{30};
    int staminaBaseZombie{0};
    short levelBaseZombie{1};
    float zombieCounter{1.0f};
    int hpBaseStrongerZombie{130};
    int staminaBaseStrongerZombie{55};
    short levelBaseStrongerZombie{1};
    short strongerzombieCounter{1};

public:
    // Generate a zombie character based on player's level
    ZombieController generateZombie(PlayerController player);
};