#ifndef KNIGHT_H
#define KNIGHT_H

#include "Warrior.h"

class Knight : public Warrior // Multi Level Inheritence
{
private:
    int chargeBonus;

public:
    Knight(string n, int h, int p, int r, int b);
    int getChargeBonus() const;
    int calculateBurstDamage() const;
};
#endif