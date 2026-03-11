#ifndef SPELLBLADE_H
#define SPELLBLADE_H
#include "Warrior.h"
#include "MagicalEntity.h"

class SpellBlade : public Warrior, public MagicalEntity // Multiple inheritence
{
public:
    SpellBlade(string n, int h, int p, int r, int m, int s);
    int calculateHybridDamage() const;
};
#endif