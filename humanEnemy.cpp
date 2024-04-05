#include "humanEnemy.h"
using namespace std;
//Factory class for human enemy; In the MVC model, this class is the equivalent of the MODEL class.

//Setter Methods
humanEnemyModel::humanEnemyModel(string newName, string newGender, string newRace, int newHp, int newStamina, int newIntelligence, int newLuck){
	name = newName;
	gender = newGender;
	race = newRace;
	hp = newHp;
	stamina = newStamina;
	intelligence = newIntelligence;
	luck = newLuck;
};

void humanEnemyModel::setName(string newName){
	name = newName;
	return;
}

void humanEnemyModel::setGender(string newGender){
    gender = newGender;
    return;
}

void humanEnemyModel::setRace(string newRace){
	race = newRace;
	return;
}

void humanEnemyModel::setHp(int newHp){
	hp = newHp;
	return;
}

void humanEnemyModel::increaseHp(int newHp){
	hp += newHp;
	return;
}

void humanEnemyModel::decreaseHp(int newHp){
	hp -= newHp;
	return;
}

void humanEnemyModel::setStamina(int newStamina){
	stamina = newStamina;
	return;
}

void humanEnemyModel::increaseStamina(int newStamina){
	stamina += newStamina;
	return;
}

void humanEnemyModel::decreaseStamina(int newStamina){
	stamina -= newStamina;
	return;
}

void humanEnemyModel::setIntelligence(int newIntelligence){
	intelligence = newIntelligence;
	return;
}

void humanEnemyModel::increaseIntelligence(){
    intelligence += 1;
    return;
}

void humanEnemyModel::setLuck(int newLuck){
	luck = newLuck;
	return;
}

void humanEnemyModel::increaseLuck(){
    luck += 1;
    return;
}

void humanEnemyModel::updateState(){
	if(hp < 15 && state != states::attack){
		state = states::lowHp;
		return;
	}
	else if(stamina < 5 && state != states::attack){
		state = states::lowStamina;
		return;
	}
	else if(state != states::attack){
		state = states::attack;
		return;
	}
	else if(state == states::attack){
		state = states::offOn;
		return;
	}
}

//Getter Methods
string humanEnemyModel::getName(){
	return name;
}

string humanEnemyModel::getGender(){
	return gender;
}

string humanEnemyModel::getRace(){
	return race;
}

int humanEnemyModel::getHp(){
	return hp;
}

int humanEnemyModel::getStamina(){
	return stamina;
}

int humanEnemyModel::getIntelligence(){
	return intelligence;
}

int humanEnemyModel::getLuck(){
	return luck;
}

states humanEnemyModel::getState(){
	return state;
}

//-----------------------------------------------------------------------------------------------------------------------------

//View class in MVC model.

void humanEnemyView::displayGeneralData(string name, string gender, string race, int hp, int stamina){
	cout << "NAME: " << name << endl;
	cout << "GENDER: " << gender << endl;
	cout << "RACE: " << race << endl;
	cout << "HP: " << hp << endl;
	cout << "STAMINA: " << stamina << endl;
}

void humanEnemyView::displayIntelligence(int intelligence){
	cout << "INTELLIGENCE: " << intelligence << endl;
}

void humanEnemyView::displayLuck(int luck){
	cout << "LUCK: " << luck << endl;
}

void humanEnemyView::displayState(states state){
	if(state == states::offOn){
		cout << "STATE: <offOn>" << endl;
	}
	else if(state == states::lowStamina){
		cout << "STATE: <lowStamina>" << endl;
	}
	else if(state == states::lowHp){
		cout << "STATE: <lowHp>" << endl;
	}
	else{
		cout << "STATE: <attack>" << endl;
	}
}

//-----------------------------------------------------------------------------------------------------------------------------

//Controller class in MVC model.

//Setter mothods
humanEnemyController::humanEnemyController(string name, string gender, string race, int hp, int stamina, int intelligence, int luck) : 
enemy(name, gender, race, hp, stamina, intelligence, luck){

};

void humanEnemyController::setGeneralData(){
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

void humanEnemyController::setHp(int hp){
	enemy.setHp(hp);
	return;
}

void humanEnemyController::increaseHp(int hp){
	enemy.increaseHp(hp);
	return;
}

void humanEnemyController::decreaseHp(int hp){
	enemy.decreaseHp(hp);
	return;
}

void humanEnemyController::setStamina(int stamina){
	enemy.setStamina(stamina);
	return;
}

void humanEnemyController::increaseStamina(int stamina){
	enemy.increaseStamina(stamina);
	return;
}

void humanEnemyController::decreaseStamina(int stamina){
	enemy.decreaseStamina(stamina);
	return;
}

void humanEnemyController::setIntelligence(){
	int intelligence = 0;
	cout << "Enter your desired intelligence level: " << endl;
	cin >> intelligence;
	enemy.setIntelligence(intelligence);
	return;
}

void humanEnemyController::increaseIntelligence(){
	enemy.increaseIntelligence();
	return;
}

void humanEnemyController::setLuck(){
	int luck = 0;
	cout << "Enter your desired luck level: " << endl;
	cin >> luck;
	enemy.setLuck(luck);
	return;
}

void humanEnemyController::increaseLuck(){
	enemy.increaseLuck();
	return;
}

void humanEnemyController::updateState(){
	enemy.updateState();
	return;
}

//Getter methods
int humanEnemyController::getHp(){
	return enemy.getHp();
};

int humanEnemyController::getStamina(){
	return enemy.getStamina();
};

void humanEnemyController::getGeneralData(){
	string name = enemy.getName();
	string gender = enemy.getGender();
	string race = enemy.getRace();
	int hp = enemy.getHp();
	int stamina = enemy.getStamina();
	viewEnemy.displayGeneralData(name, gender, race, hp, stamina);
	return;
}

void humanEnemyController::getIntelligence(){
	int intelligence = enemy.getIntelligence();
	viewEnemy.displayIntelligence(intelligence);
	return;
}

void humanEnemyController::getLuck(){
	int luck = enemy.getLuck();
	viewEnemy.displayLuck(luck);
	return;
}

states humanEnemyController::getState(){
	states state = enemy.getState();
	return state;
}