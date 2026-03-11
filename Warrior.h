#ifndef WARRIOR_H
#define WARRIOR_H
#include "Hero.h"

class Warrior : public Hero // Inheritance
{
private:
    int armorRating;

public:
    Warrior(string n, int h, int p, int r);
    int getArmor() const;
    int calculateEffectiveHealth() const;
};
#endif