#include "MagicalEntity.h"

MagicalEntity::MagicalEntity(int m, int s) // Constructor
{
    manaPool = m;
    spellPower = s;
}

// Getter
int MagicalEntity::getMana() const
{
    return manaPool;
}

int MagicalEntity::getSpellPower() const
{
    return spellPower;
}