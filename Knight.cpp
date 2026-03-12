#include "Knight.h"

Knight::Knight(string n, int h, int p, int r, int b) : Warrior(n, h, p, r) // Constructor uses Warrior class contructor as it inherits Warrior class
{
    chargeBonus = b;
}

int Knight::getChargeBonus() const // Getter
{
    return chargeBonus;
}

int Knight::calculateBurstDamage() const
{
    int burstDamage;
    burstDamage = getPower() + chargeBonus;
    return burstDamage;
}