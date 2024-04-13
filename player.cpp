#include <iostream>
#include <string>
#include "player.h"
#include "story.h"
#include "constants.h"
#include "item.h"
#include "fight.h"

using namespace std;

extern Inventory inventory;
extern vector<Item *> allItems;

// Implementation of PlayerModel methods
PlayerModel::PlayerModel(const string &name, int age, const string &gender, int hp, int stamina, int level, int intelligence,
                         int luck, int firearmSkill, int meeleWeaponSkill, int cash, int sp, const string &WeaponName)
    : CharacterModel(name, gender, hp, stamina, level), age(age), intelligence(intelligence), luck(luck),
      firearmSkill(firearmSkill), meeleWeaponSkill(meeleWeaponSkill), cash(cash), sp(sp), weaponName(weaponName) {}

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

void PlayerModel::setIntelligence(int intelligence)
{
    this->intelligence = intelligence;
}

void PlayerModel::setLuck(int luck)
{
    this->luck = luck;
}

void PlayerModel::setFirearmSkill(int firearmSkill)
{
    this->firearmSkill = firearmSkill;
}

void PlayerModel::setMeeleWeaponSkill(int meeleWeaponSkill)
{
    this->meeleWeaponSkill = meeleWeaponSkill;
}

void PlayerModel::setCash(int cash)
{
    this->cash = cash;
}

void PlayerModel::setSp(int sp)
{
    this->sp = sp;
}

void PlayerModel::setWeaponName(const string &weaponName)
{
    this->weaponName = weaponName;
}

int PlayerModel::getAge() const
{
    return age;
}

int PlayerModel::getIntelligence()
{
    return intelligence;
}

int PlayerModel::getLuck()
{
    return luck;
}

int PlayerModel::getFirearmSkill()
{
    return firearmSkill;
}

int PlayerModel::getMeeleWeaponSkill()
{
    return meeleWeaponSkill;
}

int PlayerModel::getCash()
{
    return cash;
}

int PlayerModel::getSp()
{
    return sp;
}

const string &PlayerModel::getWeaponName()
{
    return weaponName;
}

// Implementation of PlayerView methods
void PlayerView::showAllOfPlayerInfo(PlayerModel &player)
{
    cout << "Your character is: " << endl;
    cout << "-Name: " << player.getName() << endl;
    cout << "-Age: " << player.getAge() << endl;
    cout << "-Gender: " << player.getGender() << endl;
    showCharacterInfo(player);
    cout << "-Intelligence: " << player.getIntelligence() << endl;
    cout << "-Luck: " << player.getLuck() << endl;
    cout << "-Firearm kill: " << player.getFirearmSkill() << endl;
    cout << "-MeeleWeapon skill: " << player.getMeeleWeaponSkill() << endl;
    cout << "-Weapon: " << player.getWeaponName() << endl;
}

void PlayerView::showSomeOfPlayerInfo(PlayerModel &player)
{
    showCharacterInfo(player);
    cout << endl;
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

void PlayerController::displayAllOfPlayerInfo()
{
    playerView.showAllOfPlayerInfo(playerModel);
}

void PlayerController::displaySomeOfPlayerInfo()
{
    playerView.showSomeOfPlayerInfo(playerModel);
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

string chooseWeaponByPlayer()
{
    cout << color::YELLOW;

    for (int i = 0; i < 8; i++)
    {
        cout << "[" << i + 1 << "] " << allItems[i]->getName() << endl;
    }

    cout << color::RED;

    int weaponChoice{};
    cin >> weaponChoice;
    cout << RESET << endl;

    string weapon{};

    switch (weaponChoice)
    {
    case 1:
    {
        weapon = "AK47";
        break;
    }
    case 2:
    {
        weapon = "Shotgun";
        break;
    }
    case 3:
    {
        weapon = "Uzi Submachine Gun";
        break;
    }
    case 4:
    {
        weapon = "Pistol";
        break;
    }
    case 5:
    {
        weapon = "Axe";
        break;
    }
    case 6:
    {
        weapon = "Sword";
        break;
    }
    case 7:
    {
        weapon = "Nunchaku";
        break;
    }
    case 8:
    {
        weapon = "Knife";
        break;
    }
    }

    for (auto it = allItems.begin(); it != allItems.end(); it++)
    {
        if ((*it)->getName() == weapon)
        {
            inventory.addItem(*it);
            allItems.erase(it);
        }
    }

    return weapon;
}

PlayerController getPlayerInfo()
{

    system("cls");
    story playerStory;
    playerStory.printPlayerStory();

    cout << color::YELLOW << "Now tell me what's your name?" << color::RED << endl;
    string name{};
    getline(cin >> ws, name);
    name[0] = toupper(name[0]);
    cout << color::YELLOW << endl;

    cout << "How old are you " << name << "?" << endl;
    cout << color::RED;
    int age{};
    cin >> age;
    cout << color::YELLOW << endl;

    if (age <= 20)
    {
        cout << "Oh you're young, I hope you get out of here alive!" << endl;
        cout << "Now tell me your gender." << endl;
    }

    else
    {
        cout << "Alright, Now tell me your gender " << name << "." << endl;
    }

    cout << "[1] "
         << "Female" << endl;
    cout << "[2] "
         << "Male" << endl;

    cout << color::RED;
    int genderChoice{};
    cin >> genderChoice;
    cout << color::YELLOW << endl;

    string gender{};
    (genderChoice == 1) ? gender = "Female" : gender = "Male";

    cout << "What weapon do you want to fight with?" << RESET << endl;
    string weapon = chooseWeaponByPlayer();

    PlayerController player{name, age, gender, 2000, 1000, 1, 1, 1, 1, 1, 200, 0, weapon};
    player.setPlayerWeaponName(weapon);
    return player;
}