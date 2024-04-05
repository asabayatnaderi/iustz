#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <cstdint>
#include "character.h"

using namespace std;

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

    PlayerModel(const string &name, int age, const string &gender, int hp, int stamina, int level, int intelligence, int luck,
                int firearmSkill, int meeleWeaponSkill, int cash, int sp, const string &weaponName);

    void hpIncrease(int hp);
    void hpDecrease(int hp);

    void staminaIncrease(int stamina);
    void staminaDecrease(int stamina);

    void levelUp();

    void intelligenceIncrease();

    void luckIncrease();

    void firearmSkillIncrease();

    void meeleWeaponSkillIncrease();

    void cashIncrease(int cash);
    void cashDecrease(int cash);

    void spIncrease();
    void spDecrease();

    void setAge(int age);
    int getAge() const;

    void setIntelligence(int intelligence);
    int getIntelligence();

    void setLuck(int luck);
    int getLuck();

    void setFirearmSkill(int firearmSkill);
    int getFirearmSkill();

    void setMeeleWeaponSkill(int MeeleWeaponSkill);
    int getMeeleWeaponSkill();

    void setCash(int cash);
    int getCash();

    void setWeaponName(const string &weapon);
    const string &getWeaponName();

    void setSp(int sp);
    int getSp();
};

class PlayerView : public CharacterView
{
public:
    void showPlayerInfo(PlayerModel &player);
};

class PlayerController : public CharacterController
{
private:
    PlayerModel playerModel{};
    PlayerView playerView{};

public:
    PlayerController() = default;

    PlayerController(const string &name, int age, const string &gender, int hp, int stamina, int level, int intelligence, int luck,
                     int firearmSkill, int meeleWeaponSkill, int cash, int xp, const string &weaponName);

    void decreaseHp(int hp);
    void increaseHp(int hp);

    void decreaseStamina(int stamina);
    void increaseStamina(int stamina);

    void levelUp();

    void luckIncrease();

    void intelligenceIncrease();

    void firearmSkillIncrease();

    void meeleWeaponSkillIncrease();

    void cashIncrease(int cash);
    void cashDecrease(int cash);

    void spIncrease();
    void spDecrease();

    void displayPlayerInfo();

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
    void setPlayerWeaponName(const string &weaponName);
};

PlayerController getPlayerInfo();

#endif
