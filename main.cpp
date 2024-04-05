#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include "items.h"
#include "humanEnemy.h"
#include "character.h"
#include "player.h"
#include "Weapons.h"
#include "story.h"

using namespace std;

PlayerController getPlayerInfo()
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

    PlayerController player{name, age, gender, 100, 50, 1, 1, 1};

    return PlayerController{name, age, gender, 100, 50, 1, 1, 1};
}

//---------------------------------------------------------------------------------------------------------------------------------
/*
PlayerModel firstZombieFight(PlayerModel player){
    cout << "oh careful , there's a zombie ahead!" << endl;
    cout << "take this gun and kill that monster!" << endl;
    cout << "Ak47 added to your inventory." << endl;
    cout << "for attacking enemy type the name of the gun you have in your inventory." << endl;
    cout << "now type Ak47 to attack this zombie!" << endl;
    ZombieModel zombie = ZombieModel("zombie" , "male" , 100 , 50 , 1);
    string attack;
    cin >> attack;
    if (attack == "Ak47"){
        AK47 ak = AK47( "ak47" , 50 , 20 , "rapid");
        cout << "nice shot!" << endl;
        zombie = ak.playerAttack(zombie);
        cout << "but he is still standing watch out!" << endl;
        player = zombie.attack(player);
        cout << "oh you got damaged! here eat this chocolate!"<< endl;
        cout << "chocolate added to your inventory." << endl;
        cout << "for using Items type the name of the item you have in your inventory." << endl;
        cout << "remember to use your items before attacking cause you cant use them after!" << endl;
        cout << "now eat that chocolate." << endl;
        Chocolate choco = Chocolate("choco" , 20 , false );
        string item;
        cin >> item;
        if (item == "chocolate"){
            player = choco.consume(player);
            cout << "now that you have regained your health , let's attack this zombie once more" << endl;
            cin >> attack;
            if (attack == "Ak47"){
                zombie = ak.playerAttack(zombie);
                cout << "nice you killed your first zombie , keep up the good work!";
                return player;
            }
            else{
            cout << "you missed!";
            }
        }
        else{
        cout << "you missed!";
        }

    }
    else{
        cout << "you missed!";
    }
}
*/
//---------------------------------------------------------------------------------------------------------------------------------

vector<string> remove123(vector<string> v, string name){
    auto i = find(v.begin(), v.end(), name);
    if (i != v.end()) {
        v.erase(i);
    }
    return v;
}

PlayerController humanEnemyFight1(PlayerController player){
    int hp = player.getPlayerHp();
    int stamina = player.getPlayerStamina();

    int enemyHp = 0, enemyStamina = 0;

    Chocolate enemyChoco("Choco", 10, false);

    if(hp % 2 == 0){
        enemyHp = hp / 2;
    }
    else{
        enemyHp = (hp - 1) / 2;
    }

    if(stamina % 2 == 0){
        enemyStamina = stamina / 2;
    }
    else{
        enemyStamina = (stamina - 1) / 2;
    }

    humanEnemyController humanEnemy("evil witch", "Female", "Human", enemyHp, enemyStamina, 1, 1);
    
    //while(player.getPlayerHp() > 0 && player.getPlayerStamina() > 0 && humanEnemy.getHp() > 0 && humanEnemy.getStamina() > 0){

        story newhumanEnemyStory;
        newhumanEnemyStory.printHumanEnemyStory();

        cout << endl;
        cout << "Please enter your next move: " << endl;
        cout << "1)Attack" << endl;
        cout << "2)Inventory" << endl;
        cout << "3)Upgrade" << endl;
        cout << "4)Character" << endl;
        cout << endl;

        int nextMove;
        cin >> nextMove;
        cout << endl;

        vector<string> playerItems = {"AK47", "Pistol", "Knife", "Chocolate"};

        if(nextMove == 1){
            cout << "Select the item you want: " << endl;

            for(int i = 0; i < playerItems.size(); i++){
                cout << i << ")" << playerItems[i] << endl;
            }

            string item;
            cin >> item;
            cout << endl;

            if(item == "AK47"){
                AK47 ak("AK47", 60, 20, "bulletproofVest");

                humanEnemy = ak.playerAttackHuman(humanEnemy);
                cout << endl;
                cout << "You attacked the enemy." << endl;
                cout << endl;

                cout << "Player: " << endl;
                cout << "HP: " << player.getPlayerHp() << endl;
                cout << "STAMINA: " << player.getPlayerStamina() << endl;

                cout << "**************************************************" << endl;

                cout << "Human Enemy: " << endl;
                humanEnemy.getGeneralData();

                humanEnemy.updateState();
                states state = humanEnemy.getState();

                enemyHp = humanEnemy.getHp();
                enemyStamina = humanEnemy.getStamina();

                if(enemyHp != 0 && enemyStamina != 0){
                    if((state == states::lowHp) || (state == states::lowStamina)){
                        if(enemyChoco.Isconsumed == false){
                            enemyChoco.consume(humanEnemy);
                            enemyChoco.Isconsumed = true;
                            humanEnemy.updateState();
                        }
                        else{
                            humanEnemy.updateState();
                        }
                    }
                    else if(state == states::attack){
                        pistol ps("Pistol", 30, 15, "bulletproofVest");

                        player = ps.humanEnemyAttack(player);
                        cout << endl;
                        cout << "The enemy responded to your attack." << endl;
                        cout << endl;

                        cout << "Player: " << endl;
                        cout << "HP: " << player.getPlayerHp() << endl;
                        cout << "STAMINA: " << player.getPlayerStamina() << endl;

                        cout << "**************************************************" << endl;

                        cout << "Human Enemy: " << endl;
                        humanEnemy.getGeneralData();

                        humanEnemy.updateState();
                    }
                    else{
                        humanEnemy.updateState();
                    }
                }
                else{
                    cout << "Congratulations! You have defeated the enemy." << endl;
                    player.increaseXp(100);
                    //break;
                }

                if(player.getPlayerHp() <= 0 || player.getPlayerStamina() <= 0){
                    cout << "You lost!" << endl;
                    //break;
                }
            }
            else if(item == "Chocolate"){
                Chocolate choco("choco", 10, false);
                player = choco.consume(player);
                playerItems = remove123(playerItems, "Chocolate");
                cout << "You ate a chocolate." << endl;
                cout << "HP: " << player.getPlayerHp() << endl;
                cout << "STAMINA: " << player.getPlayerStamina() << endl;
            }
            else{
                cout << "Invalid selection." << endl;
            }
        }
        else if(nextMove == 2){
            cout << "All your items: " << endl;
            for(int i = 0; i < playerItems.size(); i++){
                cout << i << ")" << playerItems[i] << endl;
            }
        }
        else if(nextMove == 3){
            cout << "Which item do you want to upgrade?(your XP: " << player.getXp() << ")" << endl;
            cout << "1)Level" << endl;
            cout << "2)Intelligence" << endl;
            cout << "3)Luck" << endl;

            int choice = 0;
            cin >> choice;

            if(player.getXp() >= 50){
                if(choice == 1){
                    player.levelUp();
                    player.decreaseXp(50);
                }
                else if(choice == 2){
                    player.intelligenceIncrease();
                    player.decreaseXp(50);
                }
                else if(choice == 3){
                    player.luckIncrease();
                    player.decreaseXp(50);
                }
                else{
                    cout << "Invalid selection" << endl;
                }
            }
            else{
                cout << "Your XP is not enough to upgrade" << endl;
            }
        }
        else if(nextMove == 4){
            player.displayPlayerInfo();
        }
        else{
            cout << "Invalid selection" << endl;
        }
    //}
    return player;
}

//---------------------------------------------------------------------------------------------------------------------------------

int main() {
    PlayerController player = getPlayerInfo();

    humanEnemyFight1(player);

	/*
    srand(time(0));

    int randomNumber = rand() % 5;

    if(randomNumber == 0){
        //go shop
    }
    else if(randomNumber == 1 || randomNumber == 3){
        //human enemy
    }
    else if(randomNumber == 2 || randomNumber == 4){
        //zombie enemy
    }
    */
    return 0;
}