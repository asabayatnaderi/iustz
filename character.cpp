#include <iostream>
#include <string>
#include "character.h"

using namespace std;

// Implementation of ChracterModel methods
CharacterModel::CharacterModel(const string &name, const string &gender, int hp, int stamina, int level)
    : name(name), gender(gender), hp(hp), stamina(stamina), level(level) {}

void CharacterModel::setName(const string &name)
{
    this->name = name;
}

void CharacterModel::setGender(const string &gender)
{
    this->gender = gender;
}

void CharacterModel::setHp(int hp)
{
    this->hp = hp;
}

void CharacterModel::setStamina(int stamina)
{
    this->stamina = stamina;
}

void CharacterModel::setLevel(int level)
{
    this->level = level;
}

const string &CharacterModel::getName() const
{
    return name;
}

const string &CharacterModel::getGender() const
{
    return gender;
}

int CharacterModel::getHp()
{
    return hp;
}

int CharacterModel::getStamina()
{
    return stamina;
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

const string &CharacterController::getName()
{
    return characterModel.getName();
}