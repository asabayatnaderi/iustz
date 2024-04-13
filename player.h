#pragma once

#include <string>
#include <cstdint>
#include "character.h"

using namespace std;

// PlayerModel class represents the data of a player character
class PlayerModel : public CharacterModel
{
private:
    uint8_t age{};
    int intelligence{};
    int luck{};
    int firearmSkill{};
    int meeleWeaponSkill{};
    int cash{};
    int sp{};
    string weaponName{};

public:
    PlayerModel() = default;

    // Constructor to initialize PlayerModel object with provided data
    PlayerModel(const string &name, int age, const string &gender, int hp, int stamina, int level, int intelligence, int luck,
                int firearmSkill, int meeleWeaponSkill, int cash, int sp, const string &weaponName);

    // Increase player's health points
    void hpIncrease(int hp);

    // Decrease player's health points
    void hpDecrease(int hp);

    // Increase player's stamina
    void staminaIncrease(int stamina);

    // Decrease player's stamina
    void staminaDecrease(int stamina);

    // Level up player
    void levelUp();

    // Increase player's intelligence
    void intelligenceIncrease();

    // Increase player's luck
    void luckIncrease();

    // Increase player's firearm skill
    void firearmSkillIncrease();

    // Increase player's melee weapon skill
    void meeleWeaponSkillIncrease();

    // Increase player's cash
    void cashIncrease(int cash);

    // Decrease player's cash
    void cashDecrease(int cash);

    // Increase player's skill points
    void spIncrease();

    // Decrease player's skill points
    void spDecrease();

    // Setter methods
    void setAge(int age);
    void setIntelligence(int intelligence);
    void setLuck(int luck);
    void setFirearmSkill(int firearmSkill);
    void setMeeleWeaponSkill(int MeeleWeaponSkill);
    void setCash(int cash);
    void setWeaponName(const string &weapon);
    void setSp(int sp);

    // Getter methods
    int getAge() const;
    int getIntelligence();
    int getLuck();
    int getFirearmSkill();
    int getMeeleWeaponSkill();
    int getCash();
    const string &getWeaponName();
    int getSp();
};

// PlayerView class represents the view of a player character
class PlayerView : public CharacterView
{
public:
    // Method to display all information of a player
    void showAllOfPlayerInfo(PlayerModel &player);

    // Method to display some information of a player
    void showSomeOfPlayerInfo(PlayerModel &player);
};

// PlayerController class represents the controller for player character operations
class PlayerController : public CharacterController
{
private:
    PlayerModel playerModel{};
    PlayerView playerView{};

public:
    PlayerController() = default;

    // Constructor to initialize PlayerController with player character data
    PlayerController(const string &name, int age, const string &gender, int hp, int stamina, int level, int intelligence, int luck,
                     int firearmSkill, int meeleWeaponSkill, int cash, int xp, const string &weaponName);

    // Decrease player's health points
    void decreaseHp(int hp);

    // Increase player's health points
    void increaseHp(int hp);

    // Decrease player's stamina
    void decreaseStamina(int stamina);

    // Increase player's stamina
    void increaseStamina(int stamina);

    // Level up player
    void levelUp();

    // Increase player's luck
    void luckIncrease();

    // Increase player's intelligence
    void intelligenceIncrease();

    // Increase player's firearm skill
    void firearmSkillIncrease();

    // Increase player's melee weapon skill
    void meeleWeaponSkillIncrease();

    // Increase player's cash
    void cashIncrease(int cash);

    // Decrease player's cash
    void cashDecrease(int cash);

    // Increase player's skill points
    void spIncrease();

    // Decrease player's skill points
    void spDecrease();

    // Display all information of a player
    void displayAllOfPlayerInfo();

    // Display some information of a player
    void displaySomeOfPlayerInfo();

    // Getter methods
    int getPlayerHp();
    int getPlayerStamina();
    int getPlayerLevel();
    int getPlayerIntelligence();
    int getPlayerLuck();
    int getPlayerFirearmSkill();
    int getPlayerMeeleWeaponSkill();
    int getPlayerCash();
    int getPlayerSp();
    const string &getPlayerWeaponName();

    // Setter methods
    void setPlayerWeaponName(const string &weaponName);
};

// Function to choose weapon by player
string chooseWeaponByPlayer();

// Function to get player information
PlayerController getPlayerInfo();