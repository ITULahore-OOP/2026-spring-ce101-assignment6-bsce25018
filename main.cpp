#include <iostream>
#include <string>
#include "Hero.h"
#include "Warrior.h"
#include "Knight.h"
#include "MagicalEntity.h"
#include "SpellBlade.h"
#include "Guild.h"
using namespace std;

Hero *heroList[15];
int heroCount = 0;

void createHero(Guild &guild)
{
    string name;
    int health, power;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter health: ";
    cin >> health;
    cout << "Enter power: ";
    cin >> power;
    heroList[heroCount] = new Hero(name, health, power);
    guild += heroList[heroCount];
    heroCount++;
    cout << name << " added to guild!" << endl;
}

void createWarrior(Guild &guild)
{
    string name;
    int health, power, armor;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter health: ";
    cin >> health;
    cout << "Enter power: ";
    cin >> power;
    cout << "Enter armor rating: ";
    cin >> armor;
    heroList[heroCount] = new Warrior(name, health, power, armor);
    guild += heroList[heroCount];
    heroCount++;
    cout << name << " added to guild!" << endl;
}

void createKnight(Guild &guild)
{
    string name;
    int health, power, armor, charge;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter health: ";
    cin >> health;
    cout << "Enter power: ";
    cin >> power;
    cout << "Enter armor rating: ";
    cin >> armor;
    cout << "Enter charge bonus: ";
    cin >> charge;
    heroList[heroCount] = new Knight(name, health, power, armor, charge);
    guild += heroList[heroCount];
    heroCount++;
    cout << name << " added to guild!" << endl;
}

void createMage()
{
    int mana, spell;
    cout << "Enter mana pool: ";
    cin >> mana;
    cout << "Enter spell power: ";
    cin >> spell;
    MagicalEntity mage(mana, spell);
    cout << "Mana Pool: " << mage.getMana() << endl;
    cout << "Spell Power: " << mage.getSpellPower() << endl;
}

void createSpellBlade(Guild &guild)
{
    string name;
    int health, power, armor, mana, spell;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter health: ";
    cin >> health;
    cout << "Enter power: ";
    cin >> power;
    cout << "Enter armor rating: ";
    cin >> armor;
    cout << "Enter mana pool: ";
    cin >> mana;
    cout << "Enter spell power: ";
    cin >> spell;
    SpellBlade *sb = new SpellBlade(name, health, power, armor, mana, spell);
    heroList[heroCount] = static_cast<Warrior *>(sb);
    guild += heroList[heroCount];
    heroCount++;
    cout << name << " added to guild!" << endl;
    cout << "Hybrid Damage: " << sb->calculateHybridDamage() << endl;
}

void compareHeroes()
{
    if (heroCount < 2)
    {
        cout << "Need at least 2 heroes to compare!" << endl;
        return;
    }
    int a, b;
    cout << "Enter index of first hero (0 to " << heroCount - 1 << "): ";
    cin >> a;
    cout << "Enter index of second hero (0 to " << heroCount - 1 << "): ";
    cin >> b;
    if (a < 0 || a >= heroCount || b < 0 || b >= heroCount)
    {
        cout << "Invalid index!" << endl;
        return;
    }
    cout << "Is " << heroList[a]->getName() << " stronger than " << heroList[b]->getName() << "? ";
    cout << ((*heroList[a] > *heroList[b]) ? "YES" : "NO") << endl;
    cout << "Combined vitality: " << (*heroList[a] + *heroList[b]) << " HP" << endl;
}

void dealDamage()
{
    if (heroCount == 0)
    {
        cout << "No heroes created yet!" << endl;
        return;
    }
    int index, damage;
    cout << "Enter hero index (0 to " << heroCount - 1 << "): ";
    cin >> index;
    if (index < 0 || index >= heroCount)
    {
        cout << "Invalid index!" << endl;
        return;
    }
    cout << "Enter damage amount: ";
    cin >> damage;
    heroList[index]->takeDamage(damage);
    cout << heroList[index]->getName() << " HP is now: " << heroList[index]->getHealth() << endl;
}

int main()
{
    cout << "========================================" << endl;
    cout << "   FANTASY RPG GUILD SYSTEM             " << endl;
    cout << "========================================" << endl;

    string guildName;
    cout << "Enter your guild name: ";
    cin >> guildName;

    Guild myGuild(guildName);

    int choice;
    do
    {
        cout << "----- MENU -----" << endl;
        cout << "1.  Add Hero" << endl;
        cout << "2.  Add Warrior" << endl;
        cout << "3.  Add Knight" << endl;
        cout << "4.  Add Magical Entity" << endl;
        cout << "5.  Add Spellblade" << endl;
        cout << "6.  View Guild Roster" << endl;
        cout << "7.  View Guild Stats" << endl;
        cout << "8.  Compare Two Heroes" << endl;
        cout << "9.  Deal Damage to Hero" << endl;
        cout << "0.  Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            createHero(myGuild);
        }
        else if (choice == 2)
        {
            createWarrior(myGuild);
        }
        else if (choice == 3)
        {
            createKnight(myGuild);
        }
        else if (choice == 4)
        {
            createMage();
        }
        else if (choice == 5)
        {
            createSpellBlade(myGuild);
        }
        else if (choice == 6)
        {
            cout << myGuild;
        }
        else if (choice == 7)
        {
            myGuild.displayGuildStats();
        }
        else if (choice == 8)
        {
            compareHeroes();
        }
        else if (choice == 9)
        {
            dealDamage();
        }
        else if (choice == 0)
        {
            cout << "Exiting.." << endl;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    for (int i = 0; i < heroCount; i++)
        delete heroList[i];

    return 0;
}