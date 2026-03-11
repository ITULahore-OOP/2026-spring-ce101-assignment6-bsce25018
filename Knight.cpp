#include "Knight.h"

Knight::Knight(string n, int h, int p, int r, int b) : Warrior(n, h, p, r)
{
    chargeBonus = b;
}

int Knight::getChargeBonus() const
{
    return chargeBonus;
}

int Knight::calculateBurstDamage() const
{
    int burstDamage;
    burstDamage = getPower() + chargeBonus;
    return burstDamage;
}