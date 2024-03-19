#pragma once
#ifndef HUMANENEMY_H
#define HUMANENEMY_H

#include <iostream>
#include <string>

using namespace std;

//FSM
enum class states{
	offOn = 0,
	lowStamina = 1,
	lowHp = 2,
	attack = 3
};

//Factory class for human enemy; In the MVC model, this class is the equivalent of the MODEL class.
class humanEnemyModel{
	public:
		//Setter Methods
		void setName(string newName);

        void setGender(string newGender);

		void setRace(string newRace);

		void setHp(int newHp);

		void increaseHp(int newHp);

		void decreaseHp(int newHp);

		void setStamina(int newStamina);

		void increaseStamina(int newStamina);

		void decreaseStamina(int newStamina);

		void setCash(int newCash);
		
		void updateCash(int newCash);

        void setAge(int newAge);

        void setIntelligence(int newIntelligence);

		void increaseIntelligence();

        void setLuck(int newLuck);

		void increaseLuck();

		void updateState();
		
		//Getter Methods
		string getName();

        string getGender();

		string getRace();

		int getHp();

		int getStamina();

		int getCash();

        int getAge();

        int getIntelligence();

        int getLuck();

		states getState();

	private:
		string name, gender, race;
		int hp = 50, stamina = 20, cash = 10, age = 0, intelligence = 0, luck = 0;
		states state {states::offOn};
};

//-----------------------------------------------------------------------------------------------------------------------------

//View class in MVC model.
class humanEnemyView{
	public:
		void displayGeneralData(string name, string gender, string race, int age, int hp, int stamina);

		void displayCash(int cash);

		void displayIntelligence(int intelligence);

		void displayLuck(int luck);

		void displayState(states state);
};

//-----------------------------------------------------------------------------------------------------------------------------

//Controller class in MVC model.
class humanEnemyController{
	public:
		//Setter mothods
		void setGeneralData();

		void setHp(int hp);

		void increaseHp(int hp);

		void decreaseHp(int hp);

		void setStamina(int stamina);

		void increaseStamina(int stamina);

		void decreaseStamina(int stamina);

		void setCash(int cash);

		void updateCash(int cash);

		void setIntelligence();

		void increaseIntelligence();

		void setLuck();

		void increaseLuck();

		void updateState();

		//Getter methods
		void getGeneralData();

		void getCash();

		void getIntelligence();

		void getLuck();

		void getState();

	private:
		humanEnemyModel enemy;
		humanEnemyView viewEnemy;
};

#endif