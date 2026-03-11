#ifndef MAGICALENTITY_H
#define MAGICALENTITY_H

#include <iostream>
#include <string>
using namespace std;

class MagicalEntity
{
private:
    int manaPool;
    int spellPower;

public:
    MagicalEntity(int m, int s);
    int getMana() const;
    int getSpellPower() const;
};
#endif