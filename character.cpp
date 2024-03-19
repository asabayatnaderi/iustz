#include <iostream>
#include <string>
#include "character.h"

using namespace std;

// Implementation of ChracterModel methods
CharacterModel::CharacterModel(const string &name, const string &gender, int hp, int stamina, int level)
{
    setName(name);
    setGender(gender);
    setHp(hp);
    setStamina(stamina);
    setLevel(level);
}

void CharacterModel::setName(const string &name)
{
    this->name = name;
}

const string &CharacterModel::getName() const
{
    return name;
}

void CharacterModel::setGender(const string &gender)
{
    this->gender = gender;
}

const string &CharacterModel::getGender() const
{
    return gender;
}

void CharacterModel::setHp(int hp)
{
    this->hp = hp;
}

int CharacterModel::getHp()
{
    return hp;
}

void CharacterModel::setStamina(int stamina)
{
    this->stamina = stamina;
}

int CharacterModel::getStamina()
{
    return stamina;
}

void CharacterModel::setLevel(int level)
{
    this->level = level;
}

int CharacterModel::getLevel() const
{
    return level;
}

// Implementation of ChracterView method
void CharacterView::showCharacterInfo(CharacterModel &character)
{
    cout << "-HP: " << character.getHp() << endl;
    cout << "-Stamina: " << character.getStamina() << endl;
    cout << "-Level: " << character.getLevel() << endl;
}

// Implementation of ChracterController methods
CharacterController::CharacterController(const string &name, const string &gender, int hp, int stamina, int level)
    : characterModel(name, gender, hp, stamina, level) {}

void CharacterController::displayCharacterInfo()
{
    characterView.showCharacterInfo(characterModel);
}