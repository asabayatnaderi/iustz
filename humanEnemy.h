#pragma once
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
		friend class humanEnemyController;

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

        int getIntelligence();

        int getLuck();

		states getState();

	private:
		humanEnemyModel(string newName, string newGender, string newRace, int newHp, int newStamina, int newIntelligence, int newLuck);

		string name, gender, race;

		int hp = 0, stamina = 0, intelligence = 0, luck = 0;

		states state {states::offOn};
};

//-----------------------------------------------------------------------------------------------------------------------------

//View class in MVC model.
class humanEnemyView{
	public:
		void displayGeneralData(string name, string gender, string race, int hp, int stamina);

		void displayIntelligence(int intelligence);

		void displayLuck(int luck);

		void displayState(states state);
};

//-----------------------------------------------------------------------------------------------------------------------------

//Controller class in MVC model.
class humanEnemyController{
	public:
		//Setter mothods
		humanEnemyController(string name, string gender, string race, int hp, int stamina, int intelligence, int luck);

		void setGeneralData();

		void setHp(int hp);

		void increaseHp(int hp);

		void decreaseHp(int hp);

		void setStamina(int stamina);

		void increaseStamina(int stamina);

		void decreaseStamina(int stamina);

		void setIntelligence();

		void increaseIntelligence();

		void setLuck();

		void increaseLuck();

		void updateState();

		//Getter methods
		int getHp();

		int getStamina();

		void getGeneralData();

		void getIntelligence();

		void getLuck();

		states getState();

	private:
		humanEnemyModel enemy;
		humanEnemyView viewEnemy;
};