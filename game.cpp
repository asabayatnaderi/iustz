#include <string>
#include <iostream>
#include "player.h"
#include "weapons.h"
#include "items.h"

using namespace std;

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


int main(){
 
    PlayerModel player = getPlayerInfo();
    player = firstZombieFight(player);
    
}