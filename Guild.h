#ifndef GUILD_H
#define GUILD_H

#include <iostream>
#include <string>
using namespace std;
#include "Hero.h"

class Guild
{
private:
    string guildName;
    Hero *roster[15]; // composition
    int memberCount;

public:
    Guild(string n);
    ~Guild();
    int calculateTotalGuildPower() const;
    void displayGuildStats() const;
    void operator+=(Hero *newHero);
    friend ostream &operator<<(ostream &os, const Guild &g);
};
#endif