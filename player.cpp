#include <iostream>
#include <string>
#include "player.h"

using namespace std;

// Implementation of PlayerModel methods
PlayerModel::PlayerModel(const string &name, int age, const string &gender, int hp, int stamina, int level, int intelligence, int luck, int cash, const string &WeaponName)
    : CharacterModel(name, gender, hp, stamina, level)
{
    setAge(age);
    setIntelligence(intelligence);
    setLuck(luck);
    setCash(cash);
    setWeaponName(weaponName);
}

void PlayerModel::hpIncrease(int hp)
{
    setHp(getHp() + hp);
}

void PlayerModel::hpDecrease(int hp)
{
    setHp(getHp() - hp);
}

void PlayerModel::staminaIncrease(int stamina)
{
    setStamina(getStamina() + stamina);
}

void PlayerModel::staminaDecrease(int stamina)
{
    setStamina(getStamina() - stamina);
}

void PlayerModel::levelUp()
{
    setLevel(getLevel() + 1);
}

void PlayerModel::intelligenceIncrease()
{
    setIntelligence(getIntelligence() + 1);
}

void PlayerModel::luckIncrease()
{
    setLuck(getLuck() + 1);
}

void PlayerModel::setAge(int age)
{
    this->age = age;
}

int PlayerModel::getAge() const
{
    return age;
}

void PlayerModel::setIntelligence(int intelligence)
{
    this->intelligence = intelligence;
}

int PlayerModel::getIntelligence()
{
    return intelligence;
}

void PlayerModel::setLuck(int luck)
{
    this->luck = luck;
}

int PlayerModel::getLuck()
{
    return luck;
}

void PlayerModel::setCash(int cash)
{
    this->cash = cash;
}

int PlayerModel::getCash()
{
    return cash;
}

void PlayerModel::setWeaponName(const string &weaponName)
{
    this->weaponName = weaponName;
}

const string &PlayerModel::getWeaponName()
{
    return weaponName;
}

// Implementation of PlayerView method
void PlayerView::showPlayerInfo(PlayerModel &player)
{
    cout << "Your character is: " << endl;
    cout << "-Name: " << player.getName() << endl;
    cout << "-Age: " << player.getAge() << endl;
    cout << "-Gender: " << player.getGender() << endl;
    cout << endl;

    showCharacterInfo(player);

    cout << "-Intelligence: " << player.getIntelligence() << endl;
    cout << "-Luck: " << player.getLuck() << endl;
    cout << "-Weapon: " << player.getWeaponName() << endl;
}

// Implementation of PlayerController methods
PlayerController::PlayerController(const string &name, int age, const string &gender, int hp, int stamina, int level, int intelligence, int luck, int cash, const string& weaponName)
    : playerModel(name, age, gender, hp, stamina, level, intelligence, luck, cash, weaponName) {}

void PlayerController::decreaseHp(int hp)
{
    playerModel.hpDecrease(hp);
}

void PlayerController::increaseHp(int hp)
{
    playerModel.hpIncrease(hp);
}

void PlayerController::decreaseStamina(int stamina)
{
    playerModel.staminaDecrease(stamina);
}

void PlayerController::increaseStamina(int stamina)
{
    playerModel.staminaIncrease(stamina);
}

void PlayerController::levelUp()
{
    playerModel.levelUp();
}

void PlayerController::luckIncrease()
{
    playerModel.luckIncrease();
}

void PlayerController::intelligenceIncrease()
{
    playerModel.intelligenceIncrease();
}

void PlayerController::displayPlayerInfo()
{
    playerView.showPlayerInfo(playerModel);
}

int PlayerController::getPlayerHp()
{
    return playerModel.getHp();
}

int PlayerController::getPlayerStamina()
{
    return playerModel.getStamina();
}

int PlayerController::getPlayerLevel()
{
    return playerModel.getLevel();
}

int PlayerController::getPlayerIntelligence()
{
    return playerModel.getIntelligence();
}

int PlayerController::getPlayerLuck()
{
    return playerModel.getLuck();
}

int PlayerController::getPlayerCash()
{
    return playerModel.getCash();
}

const string& PlayerController::getPlayerWeaponName()
{
    return playerModel.getWeaponName();
}