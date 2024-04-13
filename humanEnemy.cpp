#include <ctime>

#include "humanEnemy.h"
#include "item.h"
#include "fight.h"

using namespace std;

Item *humanenemyWeapon;

// Factory class for human enemy; In the MVC model, this class is the equivalent of the MODEL class.

// Setter Methods
humanEnemyModel::humanEnemyModel(string newName, string newGender, string newRace, int newHp,
								 int newStamina, int newLevel, const string &newHumanEnemyWeaponName)
{
	name = newName;
	gender = newGender;
	race = newRace;
	hp = newHp;
	stamina = newStamina;
	level = newLevel;
	humanEnemyWeaponName = newHumanEnemyWeaponName;
};

void humanEnemyModel::setName(string newName)
{
	name = newName;
	return;
}

void humanEnemyModel::setGender(string newGender)
{
	gender = newGender;
	return;
}

void humanEnemyModel::setRace(string newRace)
{
	race = newRace;
	return;
}

void humanEnemyModel::setHp(int newHp)
{
	hp = newHp;
	return;
}

void humanEnemyModel::increaseHp(int newHp)
{
	hp += newHp;
	return;
}

void humanEnemyModel::decreaseHp(int newHp)
{
	hp -= newHp;
	return;
}

void humanEnemyModel::setStamina(int newStamina)
{
	stamina = newStamina;
	return;
}

void humanEnemyModel::increaseStamina(int newStamina)
{
	stamina += newStamina;
	return;
}

void humanEnemyModel::decreaseStamina(int newStamina)
{
	stamina -= newStamina;
	return;
}

void humanEnemyModel::setLevel(int newLevel)
{
	level = newLevel;
	return;
};

void humanEnemyModel::setState(states newState)
{
	state = newState;
	return;
}

void humanEnemyModel::setHumanEnamyWeaponName(const string &newHumanEnamyWeaponName)
{
	humanEnemyWeaponName = newHumanEnamyWeaponName;
	return;
}

void humanEnemyModel::updateState()
{
	if (hp < 15)
	{
		state = states::lowHp;
		return;
	}
	else if (stamina < 5)
	{
		state = states::lowStamina;
		return;
	}
	else if (state != states::attack)
	{
		state = states::attack;
		return;
	}
	else if (state == states::attack)
	{
		state = states::offOn;
		return;
	}
}

// Getter Methods
string humanEnemyModel::getName()
{
	return name;
}

string humanEnemyModel::getGender()
{
	return gender;
}

string humanEnemyModel::getRace()
{
	return race;
}

int humanEnemyModel::getHp()
{
	return hp;
}

int humanEnemyModel::getStamina()
{
	return stamina;
}

int humanEnemyModel::getLevel()
{
	return level;
};

const string &humanEnemyModel::getHumanEnamyWeaponName()
{
	return humanEnemyWeaponName;
}

states humanEnemyModel::getState()
{
	return state;
}

//-----------------------------------------------------------------------------------------------------------------------------

// View class in MVC model.

void humanEnemyView::displayGeneralData(string name, string gender, string race, int hp,
										int stamina, int level, const string &humanEnemyWeaponName)
{
	cout << "Name: " << name << endl;
	cout << "Gender: " << gender << endl;
	cout << "Race: " << race << endl;
	cout << "HP: " << hp << endl;
	cout << "Stamina: " << stamina << endl;
	cout << "Level: " << level << endl;
	cout << "Weapon name: " << humanEnemyWeaponName << endl;
}

void humanEnemyView::displayState(states state)
{
	if (state == states::offOn)
	{
		cout << "STATE: <offOn>" << endl;
	}
	else if (state == states::lowStamina)
	{
		cout << "STATE: <lowStamina>" << endl;
	}
	else if (state == states::lowHp)
	{
		cout << "STATE: <lowHp>" << endl;
	}
	else
	{
		cout << "STATE: <attack>" << endl;
	}
}

//-----------------------------------------------------------------------------------------------------------------------------

// Controller class in MVC model.

// Setter mothods
humanEnemyController::humanEnemyController(string name, string gender, string race, int hp, int stamina, int level,
										   const string &humanEnemyWeaponName) : enemy(name, gender, race, hp, stamina, level, humanEnemyWeaponName) {}

void humanEnemyController::setGeneralData()
{
	string name, gender, race;
	cout << "Enter your name: " << endl;
	cin >> name;
	cout << "Enter your gender(male or female): " << endl;
	cin >> gender;
	cout << "Enter your race: " << endl;
	cin >> race;

	enemy.setName(name);
	enemy.setGender(gender);
	enemy.setRace(race);
	return;
}

void humanEnemyController::setHp(int hp)
{
	enemy.setHp(hp);
	return;
}

void humanEnemyController::increaseHp(int hp)
{
	enemy.increaseHp(hp);
	return;
}

void humanEnemyController::decreaseHp(int hp)
{
	enemy.decreaseHp(hp);
	return;
}

void humanEnemyController::setStamina(int stamina)
{
	enemy.setStamina(stamina);
	return;
}

void humanEnemyController::increaseStamina(int stamina)
{
	enemy.increaseStamina(stamina);
	return;
}

void humanEnemyController::decreaseStamina(int stamina)
{
	enemy.decreaseStamina(stamina);
	return;
}

void humanEnemyController::setLevel(int level)
{
	enemy.setLevel(level);
	return;
}

void humanEnemyController::setState(states newState)
{
	enemy.setState(newState);
	return;
}

void humanEnemyController::updateState()
{
	enemy.updateState();
	return;
}

void humanEnemyController::setHumanEnemyWeaponName(const string &humanEnemyWeaponName)
{
	enemy.setHumanEnamyWeaponName(humanEnemyWeaponName);
}

// Getter methods
int humanEnemyController::getHp()
{
	return enemy.getHp();
};

int humanEnemyController::getStamina()
{
	return enemy.getStamina();
};

void humanEnemyController::getGeneralData()
{
	string name = enemy.getName();
	string gender = enemy.getGender();
	string race = enemy.getRace();
	int hp = enemy.getHp();
	int stamina = enemy.getStamina();
	int level = enemy.getLevel();
	string humanEnamyWeaponName = enemy.getHumanEnamyWeaponName();
	viewEnemy.displayGeneralData(name, gender, race, hp, stamina, level, humanEnamyWeaponName);
	return;
}

int humanEnemyController::getLevel()
{
	return enemy.getLevel();
};

states humanEnemyController::getState()
{
	states state = enemy.getState();
	return state;
}

const string &humanEnemyController::getHumanEnemyWeaponName()
{
	return enemy.getHumanEnamyWeaponName();
}

//-----------------------------------------------------------------------------------------------------------------------------

humanEnemyController HumanEnemyFactory::generateHumanEnemy(PlayerController player)
{
	srand(time(0));
	int numForGender = rand() % 2;
	string gender = (numForGender == 0) ? "Male" : "Female";

	int numForWeaponName = rand() % 7;
	string weapon{};
	switch (numForWeaponName)
	{
	case 0:
	{
		weapon = "AK47";
		humanenemyWeapon = &FightSection::ak47;
		break;
	}
	case 1:
	{
		weapon = "Shotgun";
		humanenemyWeapon = &FightSection::shotgun;
		break;
	}
	case 2:
	{
		weapon = "Uzi Submachine Gun";
		humanenemyWeapon = &FightSection::uziSubmachineGun;
		break;
	}
	case 3:
	{
		weapon = "Pistol";
		humanenemyWeapon = &FightSection::pistol;
		break;
	}
	case 4:
	{
		weapon = "Axe";
		humanenemyWeapon = &FightSection::axe;
		break;
	}
	case 5:
	{
		weapon = "Sword";
		humanenemyWeapon = &FightSection::sword;
		break;
	}
	case 6:
	{
		weapon = "Nunchaku";
		humanenemyWeapon = &FightSection::nunchaku;
		break;
	}
	case 7:
	{
		weapon = "Knife";
		humanenemyWeapon = &FightSection::knife;
		break;
	}
	}

	string name{};
	int hp{}, stamina{}, level{};

	name = "Human Enemy";
	hp = static_cast<int>(hpBaseHumanEnemy + HumanEnemyCounter * 20);
	stamina = static_cast<int>(staminaBaseHumanEnemy + HumanEnemyCounter * 20);
	level = levelBaseHumanEnemy++;
	HumanEnemyCounter++;

	return humanEnemyController(name, gender, "Human", hp, stamina, level, weapon);
};