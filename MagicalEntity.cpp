#include "MagicalEntity.h"

MagicalEntity::MagicalEntity(int m, int s)
{
    manaPool = m;
    spellPower = s;
}

int MagicalEntity::getMana() const
{
    return manaPool;
}

int MagicalEntity::getSpellPower() const
{
    return spellPower;
}