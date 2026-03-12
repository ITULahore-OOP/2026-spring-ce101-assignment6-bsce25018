#include "SpellBlade.h"

SpellBlade::SpellBlade(string n, int h, int p, int r, int m, int s) : Warrior(n, h, p, r), MagicalEntity(m, s) // Constructor uses warrior class constructor and magicalentity class constructor as it is using multiple inheritence
{
}

int SpellBlade::calculateHybridDamage() const
{
    int hybridDamage;
    hybridDamage = getPower() + getSpellPower();
    return hybridDamage;
}
