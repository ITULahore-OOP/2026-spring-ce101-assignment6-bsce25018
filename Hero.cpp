#include "Hero.h"

Hero::Hero(string n, int h, int p)
{
    heroName = n;
    health = h;
    basePower = p;
}

Hero::~Hero()
{
}

string Hero::getName() const
{
    return heroName;
}

int Hero::getHealth() const
{
    return health;
}

int Hero::getPower() const
{
    return basePower;
}

void Hero::takeDamage(int damage)
{
    if ((health - damage) < 0)
    {
        cout << "Health cannot be below 0" << endl;
    }
    else
    {
        health = health - damage;
    }
}

bool Hero::operator>(const Hero &other) const // Operator overloading
{
    if (basePower > other.basePower)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Hero::operator+(const Hero &other) const // Operator overloading
{
    return health + other.health;
}