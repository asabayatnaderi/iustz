#include <iostream>
#include <string>
#include <ctime>
#include "zombieEnemy.h"

using namespace std;

// Implementation of ZombieModel methods
ZombieModel::ZombieModel(const string &name, const string &gender, int hp, int stamina, int level)
    : CharacterModel(name, gender, hp, stamina, level) {}

void ZombieModel::hpDecrease(int hp)
{
    setHp(getHp() - hp);
}

void ZombieModel::staminaDecrease(int stamina)
{
    setStamina(getStamina() - stamina);
}

// Implementation of ZombieView methods
void ZombieView::showAllOfZombieInfo(ZombieModel &zombie)
{
    cout << "Zombie character is: " << endl;
    cout << "-Name: " << zombie.getName() << endl;
    cout << "-Gender: " << zombie.getGender() << endl;
    showCharacterInfo(zombie);
}

void ZombieView::showSomeOfZombieInfo(ZombieModel &zombie)
{
    showCharacterInfo(zombie);
    cout << endl;
}

// Implementation of ZombieController methods
ZombieController::ZombieController(const string &name, const string &gender, int hp, int stamina, int level)
    : CharacterController(name, gender, hp, stamina, level),
      zombieModel(name, gender, hp, stamina, level) {}

void ZombieController::decreaseHp(int hp)
{
    zombieModel.hpDecrease(hp);
}

void ZombieController::decreaseStamina(int stamina)
{
    zombieModel.staminaDecrease(stamina);
}

void ZombieController::displayAllOFZombieInfo()
{
    zombieView.showAllOfZombieInfo(zombieModel);
}

void ZombieController::displaySomeOfZombieInfo()
{
    zombieView.showSomeOfZombieInfo(zombieModel);
}

int ZombieController::getZombieHp()
{
    return zombieModel.getHp();
}

int ZombieController::getZombieStamina()
{
    return zombieModel.getStamina();
}

int ZombieController::getZombieLevel()
{
    return zombieModel.getLevel();
}

// Implementation of ZombieFactory method
ZombieController ZombieFactory::generateZombie(PlayerController player)
{
    srand(time(0));
    int numForGender = rand() % 2;
    string gender = (numForGender == 0) ? "Male" : "Female";

    bool isStrongZombie = rand() % 2;
    string name{};
    int hp{}, stamina{}, level{};

    if (player.getPlayerLevel() > 3 && isStrongZombie)
    {
        name = "Stronger Zombie";
        hp = static_cast<int>(hpBaseStrongerZombie + strongerzombieCounter * 20);
        stamina = static_cast<int>(staminaBaseStrongerZombie + strongerzombieCounter * 20);
        level = levelBaseStrongerZombie++;
        strongerzombieCounter++;
    }

    else
    {
        name = "Zombie";
        hp = static_cast<int>(hpBaseZombie + zombieCounter * 20);
        stamina = static_cast<int>(staminaBaseZombie + zombieCounter * 20);
        level = levelBaseZombie++;
        zombieCounter += 0.5;
    }

    return ZombieController(name, gender, hp, stamina, level);
}