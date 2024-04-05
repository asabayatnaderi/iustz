#include <iostream>
#include <string>
#include "player.h"

using namespace std;

// Implementation of PlayerModel methods
PlayerModel::PlayerModel(const string &name, int age, const string &gender, int hp, int stamina, int level, int intelligence,
                         int luck, int firearmSkill, int meeleWeaponSkill, int cash, int sp, const string &WeaponName)
    : CharacterModel(name, gender, hp, stamina, level)
{
    setAge(age);
    setIntelligence(intelligence);
    setLuck(luck);
    setFirearmSkill(firearmSkill);
    setMeeleWeaponSkill(meeleWeaponSkill);
    setCash(cash);
    setSp(sp);
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

void PlayerModel::firearmSkillIncrease()
{
    setFirearmSkill(getFirearmSkill() + 1);
}

void PlayerModel::meeleWeaponSkillIncrease()
{
    setMeeleWeaponSkill(getMeeleWeaponSkill() + 1);
}

void PlayerModel::cashIncrease(int cash)
{
    setCash(getCash() + cash);
}

void PlayerModel::cashDecrease(int cash)
{
    setCash(getCash() - cash);
}

void PlayerModel::spIncrease()
{
    setSp(getSp() + 1);
}

void PlayerModel::spDecrease()
{
    setSp(getSp() - 1);
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

void PlayerModel::setFirearmSkill(int firearmSkill)
{
    this->firearmSkill = firearmSkill;
}

int PlayerModel::getFirearmSkill()
{
    return firearmSkill;
}

void PlayerModel::setMeeleWeaponSkill(int meeleWeaponSkill)
{
    this->meeleWeaponSkill = meeleWeaponSkill;
}

int PlayerModel::getMeeleWeaponSkill()
{
    return meeleWeaponSkill;
}

void PlayerModel::setCash(int cash)
{
    this->cash = cash;
}

int PlayerModel::getCash()
{
    return cash;
}

void PlayerModel::setSp(int sp)
{
    this->sp = sp;
}

int PlayerModel::getSp()
{
    return sp;
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
PlayerController::PlayerController(const string &name, int age, const string &gender, int hp, int stamina, int level, int intelligence,
                                   int luck, int firearmSkill, int meeleWeaponSkill, int cash, int xp, const string &weaponName)
    : playerModel(name, age, gender, hp, stamina, level, intelligence, luck, firearmSkill, meeleWeaponSkill, cash, xp, weaponName) {}

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

void PlayerController::firearmSkillIncrease()
{
    playerModel.firearmSkillIncrease();
}

void PlayerController::meeleWeaponSkillIncrease()
{
    playerModel.meeleWeaponSkillIncrease();
}

void PlayerController::cashIncrease(int cash)
{
    playerModel.cashIncrease(cash);
}

void PlayerController::cashDecrease(int cash)
{
    playerModel.cashDecrease(cash);
}

void PlayerController::spIncrease()
{
    playerModel.spIncrease();
}

void PlayerController::spDecrease()
{
    playerModel.spDecrease();
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

int PlayerController::getPlayerFirearmSkill()
{
    return playerModel.getFirearmSkill();
}

int PlayerController::getPlayerMeeleWeaponSkill()
{
    return playerModel.getMeeleWeaponSkill();
}

int PlayerController::getPlayerCash()
{
    return playerModel.getCash();
}

int PlayerController::getPlayerSp()
{
    return playerModel.getSp();
}

const string &PlayerController::getPlayerWeaponName()
{
    return playerModel.getWeaponName();
}

void PlayerController::setPlayerWeaponName(const string &weaponName)
{
    playerModel.setWeaponName(weaponName);
}

PlayerController getPlayerInfo()
{
    system("cls");

    cout << "Hello stranger!" << endl;
    cout << "Welcome to the world after the apocalypse!" << endl;
    cout << "After countless catastrophes, the end of days has arrived." << endl;
    cout << "Zombies have overrun the city, and only you and a few friends remain." << endl;
    cout << "Try to survive!" << endl;
    cout << "Now tell me what's your name?" << endl;

    string name{};
    getline(cin >> ws, name);
    cout << endl;

    cout << "How old are you " << name << "?" << endl;

    int age{};
    cin >> age;
    cout << endl;

    if (age <= 20)
    {
        cout << "Oh you're young, I hope you get out of here alive!" << endl;
        cout << "Now tell me your gender too." << endl;
    }

    else
    {
        cout << "Alright, Now tell me your gender " << name << "." << endl;
    }

    cout << "[1] "
         << " Female" << endl;
    cout << "[2] "
         << " Male" << endl;

    int genderChoice{};
    cin >> genderChoice;
    cout << endl;

    string gender{};
    (genderChoice == 1) ? gender = "Female" : gender = "Male";

    cout << "Oh careful, there's a zombie ahead!" << endl;
    cout << "What weapon do you want to fight that zombie?" << endl;
    cout << "[1]  AK47" << endl;
    cout << "[2]  Pistol" << endl;
    cout << "[3]  Knife" << endl;
    cout << "[4]  Sword" << endl;

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

    PlayerController player{name, age, gender, 100, 50, 1, 1, 1, 1, 1, 100, 0, weapon};
    player.setPlayerWeaponName(weapon);
    return player;
}
