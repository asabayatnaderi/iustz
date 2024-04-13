#pragma once

#include <iostream>
#include <ctime>
#include <vector>
#include "player.h"
#include "zombieEnemy.h"
#include "passiveItem.h"
#include "humanEnemy.h"
#include "inventory.h"
#include "story.h"
#include "item.h"
#include "constants.h"

using namespace std;

class FightSection
{
private:
    PlayerController player;
    ZombieController zombie;
    humanEnemyController humanEnemy;
    static float zombieCounter;
    static short strongerZombieCounter;
    static short humanEnemyCounter;
    static short cashCounter;
    static float playerCounter;

public:
    // Static variables for weapon and item types
    static AK47 ak47;
    static Pistol pistol;
    static Shotgun shotgun;
    static UziSubmachineGun uziSubmachineGun;
    static Knife knife;
    static Sword sword;
    static Axe axe;
    static Nunchaku nunchaku;
    static Grenade grenade;
    static Flashbang flashbang;
    static C4 c4;
    static RPG7 rpg7;
    static Cookie cookie;
    static Soda soda;
    static Chocolate chocolate;
    static Hype hype;

    // Static variables for human enemy weapon and item types
    static AK47 humanEnemyAk47;
    static Pistol humanEnemyPistol;
    static Shotgun humanEnemyShotgun;
    static UziSubmachineGun humanEnemyUziSubmachineGun;
    static Knife humanEnemyKnife;
    static Sword humanEnemySword;
    static Axe humanEnemyAxe;
    static Nunchaku humanEnemyNunchaku;
    static Grenade humanEnemyGrenade;
    static Flashbang humanEnemyFlashbang;
    static C4 humanEnemyC4;
    static RPG7 humanEnemyRpg7;
    static Cookie humanEnemyCookie;
    static Soda humanEnemySoda;
    static Chocolate humanEnemyChocolate;
    static Hype humanEnemyHype;

    struct Fight
    {
        int damage{};
        int staminaCost{};
    };

    // Constructors
    FightSection(const PlayerController &player, const ZombieController &zombie);
    FightSection(const PlayerController &player, const humanEnemyController &humanEnemy);

    // Methods for calculating damage and stamina cost
    Fight calculatePlayerStaminaCostAndDamage();
    Fight calculateHumanEnemyStaminaCostAndDamage();
    Fight calculateZombieStaminaCostAndDamage();

    // Methods for using different throwable items
    void useGrenade();
    void useFlashbang();
    void useC4();
    void useRPG7();
    void humanEnemyUseGrenade();
    void humanEnemyUseFlashbang();
    void humanEnemyUseC4();
    void humanEnemyUseRPG7();

    // Methods for updating and displaying information
    void updateInfo();
    void showInfo();

    // Methods for player and enemy attacks
    void playerAttackZombie();
    void playerAttackHumanEnemy();
    void zombieAttack();
    void humanEnemyAttack();

    // Method to upgrade character abilities
    void UpgradeCharacter();

    // Method to manage player inventory
    void playerInventory();

    // Method to start a fight with zombies
    PlayerController startFightZombie();

    // Method to start a fight with human enemies
    PlayerController startFightHumanEnemy();
};