#include "Warrior.h"

Warrior::Warrior(string n, int h, int p, int r) : Hero(n, h, p)
{
    armorRating = r;
}

int Warrior::getArmor() const
{
    return armorRating;
}

int Warrior::calculateEffectiveHealth() const
{
    return getHealth() + (armorRating * 2);
}