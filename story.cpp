#include <iostream>
#include "constants.h"
#include "story.h"

using namespace std;

void story::printHumanEnemyStory()
{
    cout << UNDERLINED << color::LIGHTBLUE << BOLD << "After clearing the earth of zombies," << endl;
    cout << "man thought that he had a good life ahead of him," << endl;
    cout << "but with the death of the sun star," << endl;
    cout << "humans have migrated to a new planet and" << endl;
    cout << "now they are fighting with their fellows to get the facilities for survival." << endl;
    cout << RESET << endl;
}

void story::printPlayerStory()
{
    cout << UNDERLINED << color::LIGHTBLUE << BOLD << "We are at the end of 2050 and the apocalypse has happened." << endl;
    cout << "After countless catastrophes, the end of days has arrived." << endl;
    cout << "Zombies have overrun the city, and only you and a few friends remain." << endl;
    cout << "You are in a cold and dark room, which is a good place to hide, but you can't stay here forever to survive." << endl;
    cout << "You have to help all the members and fight against the zombies to escape the city to survive." << endl;
    cout << "It's time to destroy all the enemies in your way." << endl;
    cout << RESET << endl;
}

void story::printShopkeeperStory()
{
    cout << UNDERLINED << color::LIGHTBLUE << BOLD << "welcome to the best shop in the history of mankind" << endl;
    cout << "We present many items and great weapons in order for you to survive in this crazy and fascinating" << endl;
    cout << "Come on and choose your desired weapons." << RESET;
}