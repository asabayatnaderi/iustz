#include <iostream>
#include <string>
#include <vector>
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

// Implementation of ZombieView method
void ZombieView::showZombieInfo(ZombieModel &zombie)
{
    cout << "Zombie character is: " << endl;
    cout << "-Name: " << zombie.getName() << endl;
    cout << "-Gender: " << zombie.getGender() << endl;

    showCharacterInfo(zombie);
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

void ZombieController::displayZombieInfo()
{
    zombieView.showZombieInfo(zombieModel);
}

int ZombieController::getZombieHp()
{
    return zombieModel.getHp();
}

int ZombieController::getZombieStamina()
{
    return zombieModel.getStamina();
}

// Implementation of ZombieFactory method
vector<ZombieController> ZombieFactory::generateZombie()
{
    zombies.emplace_back("Zombie1", "Male", 50, 20, 1);
    zombies.emplace_back("Zombie2", "Male", 60, 30, 2);
    zombies.emplace_back("Zombie3", "Female", 70, 30, 3);
    zombies.emplace_back("Zombie4", "Male", 80, 40, 4);
    zombies.emplace_back("Zombie5", "Female", 90, 40, 5);
    zombies.emplace_back("Zombie6", "Male", 100, 50, 6);
    zombies.emplace_back("Zombie7", "Female", 110, 50, 7);
    zombies.emplace_back("Zombie8", "Male", 120, 60, 8);
    zombies.emplace_back("Zombie9", "Female", 130, 70, 9);
    zombies.emplace_back("Zombie10", "Female", 140, 70, 10);

    return zombies;
}