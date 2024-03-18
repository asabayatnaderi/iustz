#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "character.h"

using namespace std;

class PlayerModel : public CharacterModel
{
protected:
    int Age;
    int Intelligence;
    int Luck;

public:
    string Name;
    string Gender;
    int Stamina;
    int HealthPoints;
    int Level;
    // PlayerModel() = default;

    PlayerModel( string name, int age,  string gender, int healthPoints, int stamina, int level, int intelligence, int luck){
        Name = name;
        Age = age;
        Gender = gender;
        HealthPoints = healthPoints;
        Stamina = stamina;
        Level = level;
        Intelligence = intelligence;
        Luck = luck;
    };
    void SetHp(int hp) {
        HealthPoints = hp;
    }
    int GetHp() { 
        return HealthPoints; 
    }
    void hpIncrease(int hp){
       HealthPoints += hp;
    }
    void hpDecrease(int hp){
        HealthPoints -= hp;
    };

    void staminaIncrease(int estamina){
       Stamina += estamina;
    };
    void staminaDecrease(int estamina){
        Stamina -= estamina;
    };
    void attack(){

    };
    void levelUp();

    void intelligenceIncrease();

    void luckIncrease();

    void setAge(int age);
    int getAge() const;

    void setIntelligence(int intelligence);
    int getIntelligence();

    void setLuck(int luck);
    int getLuck();
};

class PlayerView : public CharacterView
{
public:
    void showPlayerInfo(PlayerModel &player);
};

class PlayerController : public CharacterController
{
private:
    PlayerModel playerModel;
    PlayerView playerView;

public:
    PlayerController() = default;

    PlayerController(const string &name, int age, const string &gender, int hp, int stamina, int level, int intelligence, int luck);
    PlayerModel getPlayerInfo()
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

    cout << "How old are you " << name << "?" << endl;

    int age{};
    cin >> age;

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

    string gender{};
    (genderChoice == 1) ? gender = "Female" : gender = "Male";

    PlayerModel player{name, age, gender, 100, 50, 1, 1, 1};

    return player;
    }
    void decreaseHp(int hp);
    void increaseHp(int hp);

    void decreaseStamina(int stamina);
    void increaseStamina(int stamina);

    void levelUp();

    void luckIncrease();

    void intelligenceIncrease();

    void displayPlayerInfo();

    int getPlayerHp();

    int getPlayerStamina();

    int getPlayerLevel();

    int getPlayerIntelligence();

    int getPlayerLuck();
};

#endif