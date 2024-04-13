#pragma once

#include <string>

using namespace std;

// CharacterModel class represents the data of a character
class CharacterModel
{
private:
    string name{};
    string gender{};
    int hp{};
    int stamina{};
    int level{};

public:
    CharacterModel() = default;

    // Constructor to initialize CharacterModel object with provided data
    CharacterModel(const string &name, const string &gender, int hp, int stamina, int level);

    // Setter methods
    void setName(const string &name);
    void setGender(const string &gender);
    void setHp(int hp);
    void setStamina(int stamina);
    void setLevel(int level);

    // Getter methods
    const string &getName() const;
    const string &getGender() const;
    int getHp();
    int getStamina();
    int getLevel() const;
};

// CharacterView class represents the view of a character
class CharacterView
{
public:
    void showCharacterInfo(CharacterModel &character);
};

// CharacterController class represents the controller for character operations
class CharacterController
{
private:
    CharacterModel characterModel{};
    CharacterView characterView{};

public:
    CharacterController() = default;

    // Constructor to initialize CharacterController with character data
    CharacterController(const string &name, const string &gender, int healthPoints, int stamina, int level);

    void displayCharacterInfo();

    // Getter method
    const string &getName();
};