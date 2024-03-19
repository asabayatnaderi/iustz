#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

using namespace std;

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

    CharacterModel(const string &name, const string &gender, int hp, int stamina, int level);

    void setName(const string &name);
    const string &getName() const;

    void setGender(const string &gender);
    const string &getGender() const;

    void setHp(int hp);
    int getHp();

    void setStamina(int stamina);
    int getStamina();

    void setLevel(int level);
    int getLevel() const;
};

class CharacterView
{
public:
    void showCharacterInfo(CharacterModel &character);
};

class CharacterController
{
private:
    CharacterModel characterModel{};
    CharacterView characterView{};

public:
    CharacterController() = default;
    CharacterController(const string &name, const string &gender, int healthPoints, int stamina, int level);

    void displayCharacterInfo();
};

#endif