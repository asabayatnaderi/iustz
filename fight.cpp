#include "fight.h"

using namespace std;

// player inventory
extern Inventory inventory;

extern Item *humanenemyWeapon;

vector<Item *> allItems = {&FightSection::ak47, &FightSection::shotgun, &FightSection::uziSubmachineGun, &FightSection::pistol,
                           &FightSection::axe, &FightSection::sword, &FightSection::nunchaku, &FightSection::knife,
                           &FightSection::c4, &FightSection::rpg7, &FightSection::grenade, &FightSection::flashbang,
                           &FightSection::cookie, &FightSection::chocolate, &FightSection::soda, &FightSection::hype};

FightSection::FightSection(const PlayerController &player, const ZombieController &zombie) : player(player), zombie(zombie){};
FightSection::FightSection(const PlayerController &player, const humanEnemyController &humanEnemy)
    : player(player), humanEnemy(humanEnemy){};

// calculate player staminaCost and damage based on weapon
FightSection::Fight FightSection::calculatePlayerStaminaCostAndDamage()
{
    FightSection::Fight fight;

    if (player.getPlayerWeaponName() == "AK47")
    {
        fight.damage = static_cast<int>(11 * playerCounter);
        fight.staminaCost = static_cast<int>(8 * playerCounter);
        ak47.setDamage(fight.damage);
        ak47.setStaminaCost(fight.staminaCost);
    }

    if (player.getPlayerWeaponName() == "Shotgun")
    {
        fight.damage = static_cast<int>(10 * playerCounter);
        fight.staminaCost = static_cast<int>(8 * playerCounter);
        shotgun.setDamage(fight.damage);
        shotgun.setStaminaCost(fight.staminaCost);
    }

    if (player.getPlayerWeaponName() == "Uzi Submachine Gun")
    {
        fight.damage = static_cast<int>(10 * playerCounter);
        fight.staminaCost = static_cast<int>(9 * playerCounter);
        uziSubmachineGun.setDamage(fight.damage);
        uziSubmachineGun.setStaminaCost(fight.staminaCost);
    }

    else if (player.getPlayerWeaponName() == "Pistol")
    {
        fight.damage = static_cast<int>(9 * playerCounter);
        fight.staminaCost = static_cast<int>(7 * playerCounter);
        pistol.setDamage(fight.damage);
        pistol.setStaminaCost(fight.staminaCost);
    }

    else if (player.getPlayerWeaponName() == "Axe")
    {
        fight.damage = static_cast<int>(8 * playerCounter);
        fight.staminaCost = static_cast<int>(5 * playerCounter);
        axe.setDamage(fight.damage);
        axe.setStaminaCost(fight.staminaCost);
    }

    else if (player.getPlayerWeaponName() == "Sword")
    {
        fight.damage = static_cast<int>(7 * playerCounter);
        fight.staminaCost = static_cast<int>(5 * playerCounter);
        sword.setDamage(fight.damage);
        sword.setStaminaCost(fight.staminaCost);
    }

    else if (player.getPlayerWeaponName() == "Nunchaku")
    {
        fight.damage = static_cast<int>(6 * playerCounter);
        fight.staminaCost = static_cast<int>(4 * playerCounter);
        nunchaku.setDamage(fight.damage);
        nunchaku.setStaminaCost(fight.staminaCost);
    }

    else if (player.getPlayerWeaponName() == "Knife")
    {
        fight.damage = static_cast<int>(5 * playerCounter);
        fight.staminaCost = static_cast<int>(3 * playerCounter);
        knife.setDamage(fight.damage);
        knife.setStaminaCost(fight.staminaCost);
    }

    return fight;
}

// calculate human enemy staminaCost and damage based on weapon
FightSection::Fight FightSection::calculateHumanEnemyStaminaCostAndDamage()
{
    FightSection::Fight fight;

    if (humanEnemy.getHumanEnemyWeaponName() == "AK47")
    {
        fight.damage = static_cast<int>(10 * humanEnemyCounter);
        fight.staminaCost = static_cast<int>(8 * humanEnemyCounter);
        humanEnemyAk47.setDamage(fight.damage);
        humanEnemyAk47.setStaminaCost(fight.staminaCost);
    }

    if (humanEnemy.getHumanEnemyWeaponName() == "Shotgun")
    {
        fight.damage = static_cast<int>(10 * humanEnemyCounter);
        fight.staminaCost = static_cast<int>(7 * humanEnemyCounter);
        humanEnemyShotgun.setDamage(fight.damage);
        humanEnemyShotgun.setStaminaCost(fight.staminaCost);
    }

    if (humanEnemy.getHumanEnemyWeaponName() == "Uzi Submachine Gun")
    {
        fight.damage = static_cast<int>(9 * humanEnemyCounter);
        fight.staminaCost = static_cast<int>(9 * humanEnemyCounter);
        humanEnemyUziSubmachineGun.setDamage(fight.damage);
        humanEnemyUziSubmachineGun.setStaminaCost(fight.staminaCost);
    }

    else if (humanEnemy.getHumanEnemyWeaponName() == "Pistol")
    {
        fight.damage = static_cast<int>(8 * humanEnemyCounter);
        fight.staminaCost = static_cast<int>(7 * humanEnemyCounter);
        humanEnemyPistol.setDamage(fight.damage);
        humanEnemyPistol.setStaminaCost(fight.staminaCost);
    }

    else if (humanEnemy.getHumanEnemyWeaponName() == "Axe")
    {
        fight.damage = static_cast<int>(7 * humanEnemyCounter);
        fight.staminaCost = static_cast<int>(6 * humanEnemyCounter);
        humanEnemyAxe.setDamage(fight.damage);
        humanEnemyAxe.setStaminaCost(fight.staminaCost);
    }

    else if (humanEnemy.getHumanEnemyWeaponName() == "Sword")
    {
        fight.damage = static_cast<int>(7 * humanEnemyCounter);
        fight.staminaCost = static_cast<int>(5 * humanEnemyCounter);
        humanEnemySword.setDamage(fight.damage);
        humanEnemySword.setStaminaCost(fight.staminaCost);
    }

    else if (humanEnemy.getHumanEnemyWeaponName() == "Nunchaku")
    {
        fight.damage = static_cast<int>(6 * humanEnemyCounter);
        fight.staminaCost = static_cast<int>(5 * humanEnemyCounter);
        humanEnemyNunchaku.setDamage(fight.damage);
        humanEnemyNunchaku.setStaminaCost(fight.staminaCost);
    }

    else if (humanEnemy.getHumanEnemyWeaponName() == "Knife")
    {
        fight.damage = static_cast<int>(4 * humanEnemyCounter);
        fight.staminaCost = static_cast<int>(3 * humanEnemyCounter);
        humanEnemyKnife.setDamage(fight.damage);
        humanEnemyKnife.setStaminaCost(fight.staminaCost);
    }

    return fight;
}

// calculate zombie & stronger zombie staminaCost and damage randomly
FightSection::Fight FightSection::calculateZombieStaminaCostAndDamage()
{
    FightSection::Fight fight;
    srand(time(0));
    int zombieStaminaCost{};
    int zombieDamage{};

    if (zombie.getName() == "Zombie")
    {
        while (true)
        {
            zombieStaminaCost = rand() % 3 + 5;
            zombieDamage = rand() % 3 + 5;

            if (zombieDamage >= zombieStaminaCost)
            {
                break;
            }
        }
        fight.damage = static_cast<int>(zombieDamage * zombieCounter);
        fight.staminaCost = static_cast<int>(zombieStaminaCost * zombieCounter);
    }

    else
    {
        while (true)
        {
            zombieStaminaCost = rand() % 3 + 15;
            zombieDamage = rand() % 3 + 15;

            if (zombieDamage >= zombieStaminaCost)
            {
                break;
            }
        }
        fight.damage = static_cast<int>(zombieDamage * strongerZombieCounter);
        fight.staminaCost = static_cast<int>(zombieStaminaCost * strongerZombieCounter);
    }

    return fight;
}

// calculate player staminaCost and damage based on throwable items
void FightSection::useGrenade()
{
    grenade.setDamage(static_cast<int>(15 * playerCounter));
    grenade.setStaminaCost(static_cast<int>(10 * playerCounter));
    player.decreaseStamina(static_cast<int>(10 * playerCounter));

    if (zombie.getName() == "Zombie" || zombie.getName() == "Stronger Zombie")
    {
        zombie.decreaseHp(static_cast<int>(15 * playerCounter));
    }

    else
    {
        humanEnemy.decreaseHp(static_cast<int>(15 * playerCounter));
    }

    cout << color::GREEN << "The operation was done successfully!" << RESET << endl;
    cout << endl;
    showInfo();
}

// calculate human enemy staminaCost and damage based on throwable items
void FightSection::humanEnemyUseGrenade()
{
    humanEnemyGrenade.setDamage(static_cast<int>(12 * humanEnemyCounter));
    humanEnemyGrenade.setStaminaCost(static_cast<int>(10 * humanEnemyCounter));
    humanEnemy.decreaseStamina(static_cast<int>(10 * humanEnemyCounter));
    player.decreaseHp(static_cast<int>(12 * humanEnemyCounter));

    cout << color::RED << "The operation was done successfully!" << RESET << endl;
    cout << endl;
}

// calculate player staminaCost and damage based on throwable items
void FightSection::useFlashbang()
{
    flashbang.setDamage(static_cast<int>(13 * playerCounter));
    flashbang.setStaminaCost(static_cast<int>(10 * playerCounter));
    player.decreaseStamina(static_cast<int>(10 * playerCounter));

    if (zombie.getName() == "Zombie" || zombie.getName() == "Stronger Zombie")
    {
        zombie.decreaseHp(static_cast<int>(13 * playerCounter));
    }

    else
    {
        humanEnemy.decreaseHp(static_cast<int>(13 * playerCounter));
    }

    cout << color::GREEN << "The operation was done successfully!" << RESET << endl;
    cout << endl;
    showInfo();
}

// calculate human enemy staminaCost and damage based on throwable items
void FightSection::humanEnemyUseFlashbang()
{
    humanEnemyFlashbang.setDamage(static_cast<int>(10 * humanEnemyCounter));
    humanEnemyFlashbang.setStaminaCost(static_cast<int>(8 * humanEnemyCounter));
    humanEnemy.decreaseStamina(static_cast<int>(8 * humanEnemyCounter));
    player.decreaseHp(static_cast<int>(10 * humanEnemyCounter));
    cout << color::RED << "The operation was done successfully!" << RESET << endl;
    cout << endl;
}

// calculate player staminaCost and damage based on throwable items
void FightSection::useC4()
{
    c4.setDamage(static_cast<int>(20 * playerCounter));
    c4.setStaminaCost(static_cast<int>(15 * playerCounter));
    player.decreaseStamina(static_cast<int>(15 * playerCounter));
    if (zombie.getName() == "Zombie" || zombie.getName() == "Stronger Zombie")
    {
        zombie.decreaseHp(static_cast<int>(20 * playerCounter));
    }

    else
    {
        humanEnemy.decreaseHp(static_cast<int>(20 * playerCounter));
    }
    cout << color::GREEN << "The operation was done successfully!" << RESET << endl;
    cout << endl;
    showInfo();
}

// calculate human enemy staminaCost and damage based on throwable items
void FightSection::humanEnemyUseC4()
{
    humanEnemyC4.setDamage(static_cast<int>(17 * humanEnemyCounter));
    humanEnemyC4.setStaminaCost(static_cast<int>(15 * humanEnemyCounter));
    humanEnemy.decreaseStamina(static_cast<int>(15 * humanEnemyCounter));
    player.decreaseHp(static_cast<int>(17 * humanEnemyCounter));
    cout << color::RED << "The operation was done successfully!" << RESET << endl;
    cout << endl;
}

// calculate player staminaCost and damage based on throwable items
void FightSection::useRPG7()
{
    rpg7.setDamage(static_cast<int>(18 * playerCounter));
    rpg7.setStaminaCost(static_cast<int>(13 * playerCounter));
    player.decreaseStamina(static_cast<int>(13 * playerCounter));

    if (zombie.getName() == "Zombie" || zombie.getName() == "Stronger Zombie")
    {
        zombie.decreaseHp(static_cast<int>(18 * playerCounter));
    }

    else
    {
        humanEnemy.decreaseHp(static_cast<int>(18 * playerCounter));
    }

    cout << color::GREEN << "The operation was done successfully!" << RESET << endl;
    cout << endl;
    showInfo();
}

// calculate human enemy staminaCost and damage based on throwable items
void FightSection::humanEnemyUseRPG7()
{
    humanEnemyRpg7.setDamage(static_cast<int>(15 * humanEnemyCounter));
    humanEnemyRpg7.setStaminaCost(static_cast<int>(14 * humanEnemyCounter));
    humanEnemy.decreaseStamina(static_cast<int>(14 * humanEnemyCounter));
    player.decreaseHp(static_cast<int>(15 * humanEnemyCounter));

    cout << color::RED << "The operation was done successfully!" << RESET << endl;
    cout << endl;
}

// update info of player and zombie and human enemy
void FightSection::updateInfo()
{
    player.spIncrease();
    player.levelUp();
    player.cashIncrease(200 * cashCounter);
    if (player.getPlayerLevel() % 3 == 0)
    {
        playerCounter++;
    }

    if (zombie.getName() == "Zombie" && zombie.getZombieLevel() % 3 == 1)
    {
        zombieCounter += 0.5;
    }

    if (zombie.getName() == "Stronger Zombie" && zombie.getZombieLevel() % 3 == 1)
    {
        strongerZombieCounter++;
    }

    if (humanEnemy.getLevel() % 3 == 2)
    {
        humanEnemyCounter++;
    }

    if (player.getPlayerLevel() % 4 == 0)
    {
        cashCounter++;
    }
}

// show info of player, zombie & human enemy
void FightSection::showInfo()
{
    if (zombie.getName() == "Zombie" || zombie.getName() == "Stronger Zombie")
    {
        cout << color::GREEN << "Your character: " << endl;
        player.displaySomeOfPlayerInfo();
        cout << color::RED << zombie.getName() << " character: " << endl;
        zombie.displaySomeOfZombieInfo();
        cout << RESET;
    }

    else
    {
        cout << color::GREEN << "Your character: " << endl;
        player.displaySomeOfPlayerInfo();
        cout << color::RED << "Human Enemy character: " << endl;
        cout << "-HP: " << humanEnemy.getHp() << endl;
        cout << "-Stamina: " << humanEnemy.getStamina() << endl;
        cout << "-Level: " << humanEnemy.getLevel() << endl;
        cout << RESET;
    }
}

// Player attack function on zombies
void FightSection::playerAttackZombie()
{
    Fight playerfight = calculatePlayerStaminaCostAndDamage();

    cout << color::GREEN << "You try to attack " << zombie.getName() << ". (Stamina Cost: " << playerfight.staminaCost
         << ", Damage: " << playerfight.damage << ")" << endl;
    player.decreaseStamina(playerfight.staminaCost);
    zombie.decreaseHp(playerfight.damage);
    cout << "Attack successful!" << RESET << endl;
    cout << endl;
}

// The player's attack function against the human enemy
void FightSection::playerAttackHumanEnemy()
{
    Fight playerfight = calculatePlayerStaminaCostAndDamage();

    cout << color::GREEN << "You try to attack Human Enemy. (Stamina Cost: " << playerfight.staminaCost
         << ", Damage: " << playerfight.damage << ")" << endl;
    player.decreaseStamina(playerfight.staminaCost);
    humanEnemy.decreaseHp(playerfight.damage);
    cout << "Attack successful!" << endl;
    cout << RESET << endl;
}

// Zombie attack function on humans
void FightSection::zombieAttack()
{
    Fight zombiefight = calculateZombieStaminaCostAndDamage();
    cout << color::RED << "The " << zombie.getName() << " tries to attack you. (Stamina Cost: " << zombiefight.staminaCost
         << ", Damage: " << zombiefight.damage << ")" << endl;

    zombie.decreaseStamina(zombiefight.staminaCost);
    player.decreaseHp(zombiefight.damage);
    cout << "Attack successful!" << RESET << endl;
    cout << endl;
}

// Human enemy attack function on the player
void FightSection::humanEnemyAttack()
{
    Fight humanEnemyFight = calculateHumanEnemyStaminaCostAndDamage();
    cout << color::RED << "The Human Enemy tries to attack you with " << humanEnemy.getHumanEnemyWeaponName() << ". (Stamina Cost: " << humanEnemyFight.staminaCost
         << ", Damage: " << humanEnemyFight.damage << ")" << endl;

    humanEnemy.decreaseStamina(humanEnemyFight.staminaCost);
    player.decreaseHp(humanEnemyFight.damage);
    cout << "Attack successful!" << RESET << endl;
    cout << endl;
}

// Level up function for the player
void FightSection::UpgradeCharacter()
{
    cout << color::GREEN;
    player.displayAllOfPlayerInfo();
    cout << RESET << endl;

    while (true)
    {

        cout << color::YELLOW << "What do you want to do?(your SP: " << player.getPlayerSp() << ")" << endl;
        cout << "[1] Intelligence"
             << "(" << player.getPlayerIntelligence() << ")" << endl;
        cout << "[2] Luck"
             << "(" << player.getPlayerLuck() << ")" << endl;
        cout << "[3] Firearm skill"
             << "(" << player.getPlayerFirearmSkill() << ")" << endl;
        cout << "[4] Meele weapon skill"
             << "(" << player.getPlayerMeeleWeaponSkill() << ")" << endl;
        cout << "[5] exit" << color::RED << endl;

        int choice{};
        cin >> choice;

        cout << RESET << endl;

        if (choice == 1)
        {
            if (player.getPlayerSp() > 0)
            {
                player.intelligenceIncrease();
                player.spDecrease();
                playerCounter += 0.2;
                cout << color::GREEN << "Intelligence upgraded!" << RESET << endl;
                cout << endl;
            }

            else
            {
                cout << color::RED << "your skill points is not enough for upgrading!" << RESET << endl;
                cout << endl;
            }
        }

        else if (choice == 2)
        {
            if (player.getPlayerSp() > 0)
            {
                player.spDecrease();
                player.luckIncrease();
                playerCounter += 0.2;
                cout << color::GREEN << "Luck upgraded!" << RESET << endl;
                cout << endl;
            }

            else
            {
                cout << color::RED << "your skill points is not enough for upgrading!" << RESET << endl;
                cout << endl;
            }
        }

        else if (choice == 3)
        {
            if (player.getPlayerSp() > 0)
            {
                player.spDecrease();
                player.firearmSkillIncrease();
                playerCounter += 0.4;
                cout << color::GREEN << "Firearm skill upgraded!" << RESET << endl;
                cout << endl;
            }

            else
            {
                cout << color::RED << "your skill points is not enough for upgrading!" << RESET << endl;
                cout << endl;
            }
        }

        else if (choice == 4)
        {
            if (player.getPlayerSp() > 0)
            {
                player.spDecrease();
                player.meeleWeaponSkillIncrease();
                playerCounter += 0.3;
                cout << color::GREEN << "Meele weapon skill upgraded!" << RESET << endl;
                cout << endl;
            }

            else
            {
                cout << color::RED << "your skill points is not enough for upgrading!" << RESET << endl;
                cout << endl;
            }
        }

        else if (choice == 5)
        {
            break;
        }
    }
}

// player inventory
void FightSection::playerInventory()
{
    cout << color::YELLOW << "Which item do you want?" << RESET << endl;
    cout << endl;
    while (true)
    {
        int backCounter{inventory.vectorSize() + 1};
        cout << color::YELLOW;
        inventory.displayItems();
        cout << "[" << backCounter << "]"
             << " Back" << color::RED << endl;

        int choice{};
        cin >> choice;
        cout << color::YELLOW << endl;

        Item *item = inventory.getItem(choice);
        if (item != nullptr)
        {
            string itemName = item->getName();
            if (itemName == "AK47")
            {
                if (player.getPlayerWeaponName() != "AK47")
                {
                    player.setPlayerWeaponName("AK47");
                    cout << color::GREEN << "Your weapon changed to " << player.getPlayerWeaponName() << "!" << RESET << endl;
                    cout << endl;
                }

                else
                {
                    cout << color::RED << "You are currently fighting with the same weapon!" << endl;
                    cout << endl;
                }
            }

            else if (itemName == "Pistol")
            {
                if (player.getPlayerWeaponName() != "Pistol")
                {
                    player.setPlayerWeaponName("Pistol");
                    cout << color::GREEN << "Your weapon changed to " << player.getPlayerWeaponName() << "!" << RESET << endl;
                    cout << endl;
                }

                else
                {
                    cout << color::RED << "You are currently fighting with the same weapon!" << endl;
                    cout << endl;
                }
            }

            else if (itemName == "Shotgun")
            {
                if (player.getPlayerWeaponName() != "Shotgun")
                {
                    player.setPlayerWeaponName("Shotgun");
                    cout << color::GREEN << "Your weapon changed to " << player.getPlayerWeaponName() << "!" << RESET << endl;
                    cout << endl;
                }

                else
                {
                    cout << color::RED << "You are currently fighting with the same weapon!" << endl;
                    cout << endl;
                }
            }

            else if (itemName == "Uzi Submachine Gun")
            {
                if (player.getPlayerWeaponName() != "Uzi Submachine Gun")
                {
                    player.setPlayerWeaponName("Uzi Submachine Gun");
                    cout << color::GREEN << "Your weapon changed to " << player.getPlayerWeaponName() << "!" << RESET << endl;
                    cout << endl;
                }

                else
                {
                    cout << color::RED << "You are currently fighting with the same weapon!" << endl;
                    cout << endl;
                }
            }

            else if (itemName == "Axe")
            {
                if (player.getPlayerWeaponName() != "Axe")
                {
                    player.setPlayerWeaponName("Axe");
                    cout << color::GREEN << "Your weapon changed to " << player.getPlayerWeaponName() << "!" << RESET << endl;
                    cout << endl;
                }

                else
                {
                    cout << color::RED << "You are currently fighting with the same weapon!" << endl;
                    cout << endl;
                }
            }

            else if (itemName == "Knife")
            {
                if (player.getPlayerWeaponName() != "Knife")
                {
                    player.setPlayerWeaponName("Knife");
                    cout << color::GREEN << "Your weapon changed to " << player.getPlayerWeaponName() << "!" << RESET << endl;
                    cout << endl;
                }

                else
                {
                    cout << color::RED << "You are currently fighting with the same weapon!" << endl;
                    cout << endl;
                }
            }

            else if (itemName == "Sword")
            {
                if (player.getPlayerWeaponName() != "Sword")
                {
                    player.setPlayerWeaponName("Sword");
                    cout << color::GREEN << "Your weapon changed to " << player.getPlayerWeaponName() << "!" << RESET << endl;
                    cout << endl;
                }

                else
                {
                    cout << color::RED << "You are currently fighting with the same weapon!" << endl;
                }
            }

            else if (itemName == "Nunchaku")
            {
                if (player.getPlayerWeaponName() != "Nunchaku")
                {
                    player.setPlayerWeaponName("Nunchaku");
                    cout << color::GREEN << "Your weapon changed to " << player.getPlayerWeaponName() << "!" << RESET << endl;
                    cout << endl;
                }

                else
                {
                    cout << color::RED << "You are currently fighting with the same weapon!" << endl;
                    cout << endl;
                }
            }

            else if (itemName == "Grenade")
            {
                useGrenade();
                inventory.removeItem(choice);
            }

            else if (itemName == "Flashbang")
            {
                useFlashbang();
                inventory.removeItem(choice);
            }

            else if (itemName == "C4")
            {
                useC4();
                inventory.removeItem(choice);
            }

            else if (itemName == "RPG7")
            {
                useRPG7();
                inventory.removeItem(choice);
            }

            else if (itemName == "Cookie")
            {
                cookie.consume(player);
                inventory.removeItem(choice);
                cout << color::GREEN << "You have gained 30 HP!" << RESET << endl;
                cout << endl;
            }

            else if (itemName == "Soda")
            {
                soda.consume(player);
                inventory.removeItem(choice);
                cout << color::GREEN << "You have gained 30 stamina!" << RESET << endl;
                cout << endl;
            }

            else if (itemName == "Chocolate")
            {
                chocolate.consume(player);
                inventory.removeItem(choice);
                cout << color::GREEN << "You have gained 25 stamina & 25 HP!" << RESET << endl;
                cout << endl;
            }

            else if (itemName == "Hype")
            {
                hype.consume(player);
                inventory.removeItem(choice);
                cout << color::GREEN << "You have gained 40 stamina!" << RESET << endl;
                cout << endl;
            }
        }
        if (choice == backCounter)
        {
            break;
        }
    }
}

// Player fight function with zombies
PlayerController FightSection::startFightZombie()
{
    cout << color::RED;
    zombie.displayAllOFZombieInfo();
    cout << RESET << endl;

    while (player.getPlayerHp() > 0 && zombie.getZombieHp() > 0 && player.getPlayerStamina() > 0 && zombie.getZombieStamina() > 0)
    {
        cout << color::YELLOW << "It's your turn budy. Choose your action: " << endl;
        cout << color::RED << "[1] Attack" << endl;
        cout << color::GREEN << "[2] Character" << endl;
        cout << color::BLUE << "[3] Inventrory" << endl;

        cout << color::RED;
        int actionChoice{};
        cin >> actionChoice;

        cout << RESET << endl;

        if (actionChoice == 1)
        {
            playerAttackZombie();
            zombieAttack();

            if (player.getPlayerHp() <= 0 || player.getPlayerStamina() <= 0)
            {
                cout << color::RED << endl;
                cout << "You have been defeated by the zombie." << endl;
                cout << "Game Over!" << endl;
                cout << RESET << endl;
                break;
            }

            if (zombie.getZombieHp() <= 0 || zombie.getZombieStamina() <= 0)
            {
                cout << color::GREEN << endl;
                cout << "Congratulations! You defeated the zombie." << endl;
                cout << RESET << endl;
                updateInfo();
                break;
            }

            showInfo();
        }

        else if (actionChoice == 2)
        {
            UpgradeCharacter();
        }

        else if (actionChoice == 3)
        {
            playerInventory();
        }

        cout << endl;
    }
    return player;
}

// Player fight function with human enemies
PlayerController FightSection::startFightHumanEnemy()
{
    story newhumanEnemyStory;
    newhumanEnemyStory.printHumanEnemyStory();
    cout << color::RED;
    humanEnemy.getGeneralData();
    cout << RESET << endl;

    Inventory humanEnemyInventory;

    srand(time(0));

    // Random selection of consumable items for human enemies
    int randomConsumableItem{rand() % 3};
    int consumableItems1{rand() % 2 + 1};
    int consumableItems2{rand() % 2 + 1};
    switch (randomConsumableItem)
    {
    case 0:
    {
        humanEnemyInventory.addItem(&humanEnemyChocolate);
        humanEnemyInventory.addItem(&humanEnemyCookie);
        humanEnemyCookie.setInventoryAmount(consumableItems1);
        break;
    }
    case 1:
    {
        humanEnemyInventory.addItem(&humanEnemyChocolate);
        humanEnemyInventory.addItem(&humanEnemySoda);
        humanEnemySoda.setInventoryAmount(consumableItems1);
        break;
    }
    case 2:
    {
        humanEnemyInventory.addItem(&humanEnemyChocolate);
        humanEnemyInventory.addItem(&humanEnemyHype);
        humanEnemySoda.setInventoryAmount(consumableItems1);
        break;
    }
    }
    humanEnemyChocolate.setInventoryAmount(consumableItems2);

    // Random selection of throwable items for the human enemy
    int randomThrowableItem{rand() % 6};
    int ThrowableItems1{rand() % 2 + 1};
    int ThrowableItems2{rand() % 2 + 1};
    switch (randomThrowableItem)
    {
    case 0:
    {
        humanEnemyInventory.addItem(&humanEnemyGrenade);
        humanEnemyGrenade.setInventoryAmount(ThrowableItems1);
        humanEnemyInventory.addItem(&humanEnemyFlashbang);
        humanEnemyFlashbang.setInventoryAmount(ThrowableItems2);
        break;
    }

    case 1:
    {
        humanEnemyInventory.addItem(&humanEnemyGrenade);
        humanEnemyGrenade.setInventoryAmount(ThrowableItems1);
        humanEnemyInventory.addItem(&humanEnemyC4);
        humanEnemyC4.setInventoryAmount(ThrowableItems2);
        break;
    }

    case 2:
    {
        humanEnemyInventory.addItem(&humanEnemyGrenade);
        humanEnemyGrenade.setInventoryAmount(ThrowableItems1);
        humanEnemyInventory.addItem(&humanEnemyRpg7);
        humanEnemyRpg7.setInventoryAmount(ThrowableItems2);
        break;
    }
    case 3:
    {
        humanEnemyInventory.addItem(&humanEnemyC4);
        humanEnemyC4.setInventoryAmount(ThrowableItems1);
        humanEnemyInventory.addItem(&humanEnemyFlashbang);
        humanEnemyFlashbang.setInventoryAmount(ThrowableItems2);
        break;
    }

    case 4:
    {
        humanEnemyInventory.addItem(&humanEnemyRpg7);
        humanEnemyRpg7.setInventoryAmount(ThrowableItems1);
        humanEnemyInventory.addItem(&humanEnemyC4);
        humanEnemyC4.setInventoryAmount(ThrowableItems2);
        break;
    }

    case 5:
    {
        humanEnemyInventory.addItem(&humanEnemyFlashbang);
        humanEnemyFlashbang.setInventoryAmount(ThrowableItems1);
        humanEnemyInventory.addItem(&humanEnemyRpg7);
        humanEnemyRpg7.setInventoryAmount(ThrowableItems2);
        break;
    }
    }

    cout << endl;

    cout << endl;

    while ((player.getPlayerHp() > 0 && player.getPlayerStamina() > 0) && (humanEnemy.getHp() > 0 && humanEnemy.getStamina() > 0))
    {
        cout << color::YELLOW << "It's your turn budy. Choose your action: " << endl;
        cout << color::RED << "[1] Attack" << endl;
        cout << color::GREEN << "[2] Character" << endl;
        cout << color::BLUE << "[3] Inventrory" << color::RED << endl;

        int actionChoice{};
        cin >> actionChoice;

        cout << RESET << endl;

        if (actionChoice == 1)
        {
            playerAttackHumanEnemy();

            humanEnemy.updateState();

            if (player.getPlayerHp() <= 0 || player.getPlayerStamina() <= 0)
            {
                cout << endl;
                cout << color::RED << "You have been defeated by the enemy." << endl;
                cout << "Game Over!" << RESET << endl;
                cout << endl;
                break;
            }

            if (humanEnemy.getHp() <= 0 || humanEnemy.getStamina() <= 0)
            {
                cout << endl;
                cout << color::GREEN << "Congratulations! You defeated the enemy." << RESET << endl;

                if (humanEnemyInventory.vectorSize() > 0)
                {
                    auto humanEnemyItems = humanEnemyInventory.getItems();
                    auto playerItems = inventory.getItems();

                    for (auto &pair1 : humanEnemyItems)
                    {
                        if (pair1.second->getName() == "Cookie")
                        {
                            // Check if player already has a "Cookie"
                            bool foundCookie = false;
                            for (auto &pair2 : playerItems)
                            {
                                if (pair2.second->getName() == "Cookie")
                                {
                                    // If found, update the quantity
                                    pair2.second->setInventoryAmount(pair2.second->getInventoryAmount() + pair1.second->getInventoryAmount());
                                    foundCookie = true;
                                    break;
                                }
                            }
                            // If player doesn't have a "Cookie", add it to the player's inventory
                            if (!foundCookie)
                            {
                                playerItems.push_back({inventory.getNextItemNumber(), &cookie});
                                inventory.increaseNextItemNumber();
                                cookie.setInventoryAmount(pair1.second->getInventoryAmount());
                            }
                        }

                        else if (pair1.second->getName() == "Soda")
                        {
                            // Check if player already has a "Soda"
                            bool foundSoda = false;
                            for (auto &pair2 : playerItems)
                            {
                                if (pair2.second->getName() == "Soda")
                                {
                                    // If found, update the quantity
                                    pair2.second->setInventoryAmount(pair2.second->getInventoryAmount() + pair1.second->getInventoryAmount());
                                    foundSoda = true;
                                    break;
                                }
                            }
                            // If player doesn't have a "Soda", add it to the player's inventory
                            if (!foundSoda)
                            {
                                playerItems.push_back({inventory.getNextItemNumber(), &soda});
                                inventory.increaseNextItemNumber();
                                soda.setInventoryAmount(pair1.second->getInventoryAmount());
                            }
                        }

                        else if (pair1.second->getName() == "Hype")
                        {
                            // Check if player already has a "Hype"
                            bool foundHype = false;
                            for (auto &pair2 : playerItems)
                            {
                                if (pair2.second->getName() == "Hype")
                                {
                                    // If found, update the quantity
                                    pair2.second->setInventoryAmount(pair2.second->getInventoryAmount() + pair1.second->getInventoryAmount());
                                    foundHype = true;
                                    break;
                                }
                            }
                            // If player doesn't have a "Hype", add it to the player's inventory
                            if (!foundHype)
                            {
                                playerItems.push_back({inventory.getNextItemNumber(), &hype});
                                inventory.increaseNextItemNumber();
                                hype.setInventoryAmount(pair1.second->getInventoryAmount());
                            }
                        }

                        else if (pair1.second->getName() == "Chocolate")
                        {
                            // Check if player already has a "Chocolate"
                            bool foundChocolate = false;
                            for (auto &pair2 : playerItems)
                            {
                                if (pair2.second->getName() == "Chocolate")
                                {
                                    // If found, update the quantity
                                    pair2.second->setInventoryAmount(pair2.second->getInventoryAmount() + pair1.second->getInventoryAmount());
                                    foundChocolate = true;
                                    break;
                                }
                            }
                            // If player doesn't have a "Chocolate", add it to the player's inventory
                            if (!foundChocolate)
                            {
                                playerItems.push_back({inventory.getNextItemNumber(), &chocolate});
                                inventory.increaseNextItemNumber();
                                chocolate.setInventoryAmount(pair1.second->getInventoryAmount());
                            }
                        }

                        else if (pair1.second->getName() == "C4")
                        {
                            // Check if player already has a "C4"
                            bool foundC4 = false;
                            for (auto &pair2 : playerItems)
                            {
                                if (pair2.second->getName() == "C4")
                                {
                                    // If found, update the quantity
                                    pair2.second->setInventoryAmount(pair2.second->getInventoryAmount() + pair1.second->getInventoryAmount());
                                    foundC4 = true;
                                    break;
                                }
                            }
                            // If player doesn't have a "C4", add it to the player's inventory
                            if (!foundC4)
                            {
                                playerItems.push_back({inventory.getNextItemNumber(), &c4});
                                inventory.increaseNextItemNumber();
                                c4.setInventoryAmount(pair1.second->getInventoryAmount());
                            }
                        }

                        else if (pair1.second->getName() == "Grenade")
                        {
                            // Check if player already has a "Grenade"
                            bool foundGrenade = false;
                            for (auto &pair2 : playerItems)
                            {
                                if (pair2.second->getName() == "Grenade")
                                {
                                    // If found, update the quantity
                                    pair2.second->setInventoryAmount(pair2.second->getInventoryAmount() + pair1.second->getInventoryAmount());
                                    foundGrenade = true;
                                    break;
                                }
                            }
                            // If player doesn't have a "Grenade", add it to the player's inventory
                            if (!foundGrenade)
                            {
                                playerItems.push_back({inventory.getNextItemNumber(), &grenade});
                                inventory.increaseNextItemNumber();
                                grenade.setInventoryAmount(pair1.second->getInventoryAmount());
                            }
                        }

                        else if (pair1.second->getName() == "RPG7")
                        {
                            // Check if player already has a "RPG7"
                            bool foundRPG7 = false;
                            for (auto &pair2 : playerItems)
                            {
                                if (pair2.second->getName() == "RPG7")
                                {
                                    // If found, update the quantity
                                    pair2.second->setInventoryAmount(pair2.second->getInventoryAmount() + pair1.second->getInventoryAmount());
                                    foundRPG7 = true;
                                    break;
                                }
                            }
                            // If player doesn't have a "RPG7", add it to the player's inventory
                            if (!foundRPG7)
                            {
                                playerItems.push_back({inventory.getNextItemNumber(), &rpg7});
                                inventory.increaseNextItemNumber();
                                rpg7.setInventoryAmount(pair1.second->getInventoryAmount());
                            }
                        }

                        else if (pair1.second->getName() == "Flashbang")
                        {
                            // Check if player already has a "Flashbang"
                            bool foundFlashbang = false;
                            for (auto &pair2 : playerItems)
                            {
                                if (pair2.second->getName() == "Flashbang")
                                {
                                    // If found, update the quantity
                                    pair2.second->setInventoryAmount(pair2.second->getInventoryAmount() + pair1.second->getInventoryAmount());
                                    foundFlashbang = true;
                                    break;
                                }
                            }
                            // If player doesn't have a "Flashbang", add it to the player's inventory
                            if (!foundFlashbang)
                            {
                                playerItems.push_back({inventory.getNextItemNumber(), &flashbang});
                                inventory.increaseNextItemNumber();
                                flashbang.setInventoryAmount(pair1.second->getInventoryAmount());
                            }
                        }
                        inventory.setItems(playerItems);
                    }
                    bool hasItem{false};
                    for (auto &pair : playerItems)
                    {
                        if (pair.second->getName() == humanEnemy.getHumanEnemyWeaponName())
                        {
                            hasItem = true;
                            break;
                        }
                    }
                    if (!hasItem)
                    {
                        inventory.addItem(humanenemyWeapon);
                    }

                    cout << color::GREEN << "Enemy items added to your inventory." << endl;
                }

                else
                {
                    cout << color::RED << "The enemy left no booty for you." << RESET << endl;
                }

                cout << endl;
                updateInfo();
                break;
            }
            else
            {
                while ((humanEnemy.getState() == states::lowHp) || (humanEnemy.getState() == states::lowStamina))
                {
                    if (humanEnemy.getHp() < 20 && humanEnemy.getStamina() < 10)
                    {
                        if (humanEnemyInventory.ifExists(&humanEnemyChocolate))
                        {
                            humanEnemyChocolate.consume(humanEnemy);
                            cout << color::RED << "enemy eat a Chocolate!" << RESET << endl;
                            humanEnemyInventory.removeItem(humanEnemyInventory.getItemNumber(&humanEnemyChocolate));
                            humanEnemy.updateState();
                            cout << endl;
                        }
                        else
                        {
                            humanEnemy.setState(states::attack);
                        }
                        break;
                    }
                    else if (humanEnemy.getState() == states::lowHp)
                    {
                        if (humanEnemyInventory.ifExists(&humanEnemyCookie))
                        {
                            humanEnemyCookie.consume(humanEnemy);
                            cout << color::RED << "enemy eat a cookie!" << RESET << endl;
                            humanEnemyInventory.removeItem(humanEnemyInventory.getItemNumber(&humanEnemyCookie));
                            humanEnemy.updateState();
                            cout << endl;
                        }
                        else
                        {
                            humanEnemy.setState(states::attack);
                        }
                        break;
                    }
                    else if (humanEnemy.getState() == states::lowStamina)
                    {
                        if (humanEnemyInventory.ifExists(&humanEnemyHype))
                        {
                            humanEnemyHype.consume(humanEnemy);
                            cout << color::RED << "enemy eat a hype!" << RESET << endl;
                            humanEnemyInventory.removeItem(humanEnemyInventory.getItemNumber(&humanEnemyHype));
                            humanEnemy.updateState();
                            cout << endl;
                        }

                        else if (humanEnemyInventory.ifExists(&humanEnemySoda))
                        {
                            humanEnemySoda.consume(humanEnemy);
                            cout << color::RED << "enemy eat a soda!" << RESET << endl;
                            humanEnemyInventory.removeItem(humanEnemyInventory.getItemNumber(&humanEnemySoda));
                            humanEnemy.updateState();
                            cout << endl;
                        }
                        else
                        {
                            humanEnemy.setState(states::attack);
                        }
                        break;
                    }
                }

                if (humanEnemy.getState() == states::attack)
                {
                    srand(time(0));
                    int attackNum = rand() % 8;

                    if (attackNum == 1)
                    {
                        if (humanEnemyInventory.ifExists(&humanEnemyGrenade))
                        {
                            cout << color::RED << "human enemy are attacking you with GRENADE..." << RESET << endl;
                            cout << endl;
                            humanEnemyUseGrenade();
                            humanEnemyInventory.removeItem(humanEnemyInventory.getItemNumber(&humanEnemyGrenade));
                            cout << endl;
                        }
                        else
                        {
                            humanEnemyAttack();
                        }
                    }
                    else if (attackNum == 2)
                    {
                        if (humanEnemyInventory.ifExists(&humanEnemyC4))
                        {
                            cout << color::RED << "human enemy are attacking you with C4..." << RESET << endl;
                            cout << endl;
                            humanEnemyUseC4();
                            humanEnemyInventory.removeItem(humanEnemyInventory.getItemNumber(&humanEnemyC4));
                            cout << endl;
                        }
                        else
                        {
                            humanEnemyAttack();
                        }
                    }

                    else if (attackNum == 3)
                    {
                        if (humanEnemyInventory.ifExists(&humanEnemyFlashbang))
                        {
                            cout << color::RED << "human enemy are attacking you with FLASHBANG..." << RESET << endl;
                            cout << endl;
                            humanEnemyUseFlashbang();
                            humanEnemyInventory.removeItem(humanEnemyInventory.getItemNumber(&humanEnemyFlashbang));
                            cout << endl;
                        }
                        else
                        {
                            humanEnemyAttack();
                        }
                    }

                    else if (attackNum == 4)
                    {
                        if (humanEnemyInventory.ifExists(&humanEnemyRpg7))
                        {
                            cout << color::RED << "human enemy are attacking you with RPG7..." << RESET << endl;
                            cout << endl;
                            humanEnemyUseRPG7();
                            humanEnemyInventory.removeItem(humanEnemyInventory.getItemNumber(&humanEnemyRpg7));
                            cout << endl;
                        }
                        else
                        {
                            humanEnemyAttack();
                        }
                    }

                    else
                    {
                        humanEnemyAttack();
                    }

                    humanEnemy.updateState();

                    if (player.getPlayerHp() <= 0 || player.getPlayerStamina() <= 0)
                    {
                        cout << endl;
                        cout << color::RED << "You have been defeated by the enemy." << endl;
                        cout << "Game Over!" << RESET << endl;
                        cout << endl;
                        break;
                    }

                    if (humanEnemy.getHp() <= 0 || humanEnemy.getStamina() <= 0)
                    {
                        cout << endl;
                        cout << color::GREEN << "Congratulations! You defeated the enemy." << RESET << endl;

                        if (humanEnemyInventory.vectorSize() > 0)
                        {
                            auto humanEnemyItems = humanEnemyInventory.getItems();
                            auto playerItems = inventory.getItems();

                            for (auto &pair1 : humanEnemyItems)
                            {
                                if (pair1.second->getName() == "Cookie")
                                {
                                    // Check if player already has a "Cookie"
                                    bool foundCookie = false;
                                    for (auto &pair2 : playerItems)
                                    {
                                        if (pair2.second->getName() == "Cookie")
                                        {
                                            // If found, update the quantity
                                            pair2.second->setInventoryAmount(pair2.second->getInventoryAmount() + pair1.second->getInventoryAmount());
                                            foundCookie = true;
                                            break;
                                        }
                                    }
                                    // If player doesn't have a "Cookie", add it to the player's inventory
                                    if (!foundCookie)
                                    {
                                        playerItems.push_back({inventory.getNextItemNumber(), &cookie});
                                        inventory.increaseNextItemNumber();
                                        cookie.setInventoryAmount(pair1.second->getInventoryAmount());
                                    }
                                }

                                else if (pair1.second->getName() == "Soda")
                                {
                                    // Check if player already has a "Soda"
                                    bool foundSoda = false;
                                    for (auto &pair2 : playerItems)
                                    {
                                        if (pair2.second->getName() == "Soda")
                                        {
                                            // If found, update the quantity
                                            pair2.second->setInventoryAmount(pair2.second->getInventoryAmount() + pair1.second->getInventoryAmount());
                                            foundSoda = true;
                                            break;
                                        }
                                    }
                                    // If player doesn't have a "Soda", add it to the player's inventory
                                    if (!foundSoda)
                                    {
                                        playerItems.push_back({inventory.getNextItemNumber(), &soda});
                                        inventory.increaseNextItemNumber();
                                        soda.setInventoryAmount(pair1.second->getInventoryAmount());
                                    }
                                }

                                else if (pair1.second->getName() == "Hype")
                                {
                                    // Check if player already has a "Hype"
                                    bool foundHype = false;
                                    for (auto &pair2 : playerItems)
                                    {
                                        if (pair2.second->getName() == "Hype")
                                        {
                                            // If found, update the quantity
                                            pair2.second->setInventoryAmount(pair2.second->getInventoryAmount() + pair1.second->getInventoryAmount());
                                            foundHype = true;
                                            break;
                                        }
                                    }
                                    // If player doesn't have a "Hype", add it to the player's inventory
                                    if (!foundHype)
                                    {
                                        playerItems.push_back({inventory.getNextItemNumber(), &hype});
                                        inventory.increaseNextItemNumber();
                                        hype.setInventoryAmount(pair1.second->getInventoryAmount());
                                    }
                                }

                                else if (pair1.second->getName() == "Chocolate")
                                {
                                    // Check if player already has a "Chocolate"
                                    bool foundChocolate = false;
                                    for (auto &pair2 : playerItems)
                                    {
                                        if (pair2.second->getName() == "Chocolate")
                                        {
                                            // If found, update the quantity
                                            pair2.second->setInventoryAmount(pair2.second->getInventoryAmount() + pair1.second->getInventoryAmount());
                                            foundChocolate = true;
                                            break;
                                        }
                                    }
                                    // If player doesn't have a "Chocolate", add it to the player's inventory
                                    if (!foundChocolate)
                                    {
                                        playerItems.push_back({inventory.getNextItemNumber(), &chocolate});
                                        inventory.increaseNextItemNumber();
                                        chocolate.setInventoryAmount(pair1.second->getInventoryAmount());
                                    }
                                }

                                else if (pair1.second->getName() == "C4")
                                {
                                    // Check if player already has a "C4"
                                    bool foundC4 = false;
                                    for (auto &pair2 : playerItems)
                                    {
                                        if (pair2.second->getName() == "C4")
                                        {
                                            // If found, update the quantity
                                            pair2.second->setInventoryAmount(pair2.second->getInventoryAmount() + pair1.second->getInventoryAmount());
                                            foundC4 = true;
                                            break;
                                        }
                                    }
                                    // If player doesn't have a "C4", add it to the player's inventory
                                    if (!foundC4)
                                    {
                                        playerItems.push_back({inventory.getNextItemNumber(), &c4});
                                        inventory.increaseNextItemNumber();
                                        c4.setInventoryAmount(pair1.second->getInventoryAmount());
                                    }
                                }

                                else if (pair1.second->getName() == "Grenade")
                                {
                                    // Check if player already has a "Grenade"
                                    bool foundGrenade = false;
                                    for (auto &pair2 : playerItems)
                                    {
                                        if (pair2.second->getName() == "Grenade")
                                        {
                                            // If found, update the quantity
                                            pair2.second->setInventoryAmount(pair2.second->getInventoryAmount() + pair1.second->getInventoryAmount());
                                            foundGrenade = true;
                                            break;
                                        }
                                    }
                                    // If player doesn't have a "Grenade", add it to the player's inventory
                                    if (!foundGrenade)
                                    {
                                        playerItems.push_back({inventory.getNextItemNumber(), &grenade});
                                        inventory.increaseNextItemNumber();
                                        grenade.setInventoryAmount(pair1.second->getInventoryAmount());
                                    }
                                }

                                else if (pair1.second->getName() == "RPG7")
                                {
                                    // Check if player already has a "RPG7"
                                    bool foundRPG7 = false;
                                    for (auto &pair2 : playerItems)
                                    {
                                        if (pair2.second->getName() == "RPG7")
                                        {
                                            // If found, update the quantity
                                            pair2.second->setInventoryAmount(pair2.second->getInventoryAmount() + pair1.second->getInventoryAmount());
                                            foundRPG7 = true;
                                            break;
                                        }
                                    }
                                    // If player doesn't have a "RPG7", add it to the player's inventory
                                    if (!foundRPG7)
                                    {
                                        playerItems.push_back({inventory.getNextItemNumber(), &rpg7});
                                        inventory.increaseNextItemNumber();
                                        rpg7.setInventoryAmount(pair1.second->getInventoryAmount());
                                    }
                                }

                                else if (pair1.second->getName() == "Flashbang")
                                {
                                    // Check if player already has a "Flashbang"
                                    bool foundFlashbang = false;
                                    for (auto &pair2 : playerItems)
                                    {
                                        if (pair2.second->getName() == "Flashbang")
                                        {
                                            // If found, update the quantity
                                            pair2.second->setInventoryAmount(pair2.second->getInventoryAmount() + pair1.second->getInventoryAmount());
                                            foundFlashbang = true;
                                            break;
                                        }
                                    }
                                    // If player doesn't have a "Flashbang", add it to the player's inventory
                                    if (!foundFlashbang)
                                    {
                                        playerItems.push_back({inventory.getNextItemNumber(), &flashbang});
                                        inventory.increaseNextItemNumber();
                                        flashbang.setInventoryAmount(pair1.second->getInventoryAmount());
                                    }
                                }

                                inventory.setItems(playerItems);
                            }
                            bool hasItem{false};
                            for (auto &pair : playerItems)
                            {
                                if (pair.second->getName() == humanEnemy.getHumanEnemyWeaponName())
                                {
                                    hasItem = true;
                                    break;
                                }
                            }
                            if (!hasItem)
                            {
                                inventory.addItem(humanenemyWeapon);
                            }
                            cout << color::GREEN << "Enemy items added to your inventory." << RESET << endl;
                        }

                        else
                        {
                            cout << color::RED << "The enemy left no booty for you." << RESET << endl;
                        }

                        cout << endl;
                        updateInfo();
                        break;
                    }
                }
                else
                {
                    humanEnemy.updateState();
                }
            }

            showInfo();
        }

        else if (actionChoice == 2)
        {
            UpgradeCharacter();
        }

        else if (actionChoice == 3)
        {
            playerInventory();
        }

        cout << endl;
    }
    return player;
}

float FightSection::playerCounter{1.0f};
float FightSection::zombieCounter{1.0f};
short FightSection::strongerZombieCounter{1};
short FightSection::humanEnemyCounter{1};
short FightSection::cashCounter{1};

// player items
AK47 FightSection::ak47("AK47", 2000, 11, 8, 1, 0);
Pistol FightSection::pistol("Pistol", 1500, 9, 7, 1, 0);
Shotgun FightSection::shotgun("Shotgun", 1800, 10, 8, 1, 0);
UziSubmachineGun FightSection::uziSubmachineGun("Uzi Submachine Gun", 1700, 10, 9, 1, 0);
Knife FightSection::knife("Knife", 800, 5, 3, 1, 0);
Sword FightSection::sword("Sword", 1000, 7, 5, 1, 0);
Axe FightSection::axe("Axe", 1200, 8, 5, 1, 0);
Nunchaku FightSection::nunchaku("Nunchaku", 900, 6, 4, 1, 0);
Grenade FightSection::grenade("Grenade", 2500, 15, 10, 15, 0);
Flashbang FightSection::flashbang("Flashbang", 2300, 13, 10, 10, 0);
C4 FightSection::c4("C4", 3000, 20, 15, 15, 0);
RPG7 FightSection::rpg7("RPG7", 2800, 18, 13, 10, 0);
Cookie FightSection::cookie("Cookie", 300, false, 30, 0);
Soda FightSection::soda("Soda", 300, false, 25, 0);
Chocolate FightSection::chocolate("Chocolate", 500, false, 25, 0);
Hype FightSection::hype("Hype", 400, false, 30, 0);

// human enemy items
AK47 FightSection::humanEnemyAk47("AK47", 1000, 10, 8, 1, 0);
Pistol FightSection::humanEnemyPistol("Pistol", 500, 8, 7, 1, 0);
Shotgun FightSection::humanEnemyShotgun("Shotgun", 1500, 10, 7, 1, 0);
UziSubmachineGun FightSection::humanEnemyUziSubmachineGun("Uzi Submachine Gun", 1000, 9, 9, 1, 0);
Knife FightSection::humanEnemyKnife("Knife", 250, 4, 3, 1, 0);
Sword FightSection::humanEnemySword("Sword", 1000, 7, 5, 1, 0);
Axe FightSection::humanEnemyAxe("Axe", 1500, 7, 6, 1, 0);
Nunchaku FightSection::humanEnemyNunchaku("Nunchaku", 1000, 6, 5, 1, 0);
Grenade FightSection::humanEnemyGrenade("Grenade", 3000, 12, 10, 5, 0);
Flashbang FightSection::humanEnemyFlashbang("Flashbang", 2500, 10, 8, 5, 0);
C4 FightSection::humanEnemyC4("C4", 4500, 17, 15, 5, 0);
RPG7 FightSection::humanEnemyRpg7("RPG7", 6000, 15, 14, 5, 0);
Cookie FightSection::humanEnemyCookie("Cookie", 600, false, 10, 0);
Soda FightSection::humanEnemySoda("Soda", 200, false, 10, 0);
Chocolate FightSection::humanEnemyChocolate("Chocolate", 600, false, 10, 0);
Hype FightSection::humanEnemyHype("Hype", 200, false, 10, 0);