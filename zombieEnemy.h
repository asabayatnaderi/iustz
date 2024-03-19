#ifndef ZOMBIEENEMY_H
#define ZOMBIEENEMY_H

#include <string>
#include <vector>
#include "character.h"

using namespace std;

class ZombieModel : public CharacterModel
{
public:
    ZombieModel() = default;

    ZombieModel(const string &name, const string &gender, int hp, int stamina, int level);

    void hpDecrease(int hp);

    void staminaDecrease(int stamina);
};

class ZombieView : public CharacterView
{
public:
    void showZombieInfo(ZombieModel &zombie);
};

class ZombieController : public CharacterController
{
private:
    ZombieModel zombieModel{};
    ZombieView zombieView{};

public:
    ZombieController(const string &name, const string &gender, int hp, int stamina, int level);

    void decreaseHp(int hp);

    void decreaseStamina(int stamina);

    void displayZombieInfo();

    int getZombieHp();

    int getZombieStamina();

    int getZombieLvel();
};

class ZombieFactory
{
private:
    vector<ZombieController> zombies{};

public:
    vector<ZombieController> generateZombie();
};

#endif