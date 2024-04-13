#pragma once

#include <iostream>
#include <string>
#include "player.h"

using namespace std;

// FSM
enum class states
{
	offOn = 0,
	lowStamina = 1,
	lowHp = 2,
	attack = 3
};

// Factory class for human enemy; In the MVC model, this class is the equivalent of the MODEL class.
class humanEnemyModel
{
public:
	friend class humanEnemyController;

	// Setter Methods
	void setName(string newName);

	void setGender(string newGender);

	void setRace(string newRace);

	void setHp(int newHp);

	void increaseHp(int newHp);

	void decreaseHp(int newHp);

	void setStamina(int newStamina);

	void increaseStamina(int newStamina);

	void decreaseStamina(int newStamina);

	void setLevel(int newLevel);

	void setState(states newState);

	void setHumanEnamyWeaponName(const string &weaponName);

	void updateState();

	// Getter Methods
	string getName();

	string getGender();

	string getRace();

	int getHp();

	int getStamina();

	int getLevel();

	const string &getHumanEnamyWeaponName();

	states getState();

private:
	humanEnemyModel() = default;
	humanEnemyModel(string newName, string newGender, string newRace, int newHp, int newStamina, int newLevel, const string &humanEnemyWeaponName);

	string name, gender, race, humanEnemyWeaponName;

	int hp = 0, stamina = 0, level = 0;

	states state{states::offOn};
};

//-----------------------------------------------------------------------------------------------------------------------------

// View class in MVC model.
class humanEnemyView
{
public:
	void displayGeneralData(string name, string gender, string race, int hp, int stamina, int level, const string &humanEnemyWeaponName);

	void displayState(states state);
};

//-----------------------------------------------------------------------------------------------------------------------------

// Controller class in MVC model.
class humanEnemyController
{
public:
	// Setter mothods
	humanEnemyController() = default;
	humanEnemyController(string name, string gender, string race, int hp, int stamina, int level, const string &humanEnemyWeaponName);

	void setGeneralData();

	void setHp(int hp);

	void increaseHp(int hp);

	void decreaseHp(int hp);

	void setStamina(int stamina);

	void increaseStamina(int stamina);

	void decreaseStamina(int stamina);

	void setLevel(int level);

	void setState(states newState);

	void updateState();

	void setHumanEnemyWeaponName(const string &newHumanEnemyWeaponName);

	// Getter methods
	int getHp();

	int getStamina();

	void getGeneralData();

	int getLevel();

	states getState();

	const string &getHumanEnemyWeaponName();

private:
	humanEnemyModel enemy;
	humanEnemyView viewEnemy;
};

//-----------------------------------------------------------------------------------------------------------------------------
class HumanEnemyFactory
{
private:
	int hpBaseHumanEnemy{100};
	int staminaBaseHumanEnemy{50};
	short levelBaseHumanEnemy{1};
	short HumanEnemyCounter{1};

public:
	humanEnemyController generateHumanEnemy(PlayerController player);
};