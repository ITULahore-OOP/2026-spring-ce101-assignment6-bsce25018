#include "Warrior.h"

Warrior::Warrior(string n, int h, int p, int r) : Hero(n, h, p) // constructor uses Hero class constructor as it inherits Hero class
{
    armorRating = r;
}

int Warrior::getArmor() const // Getter
{
    return armorRating;
}

int Warrior::calculateEffectiveHealth() const
{
    return getHealth() + (armorRating * 2);
}