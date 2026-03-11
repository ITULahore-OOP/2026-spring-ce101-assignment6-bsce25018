#ifndef HERO_H
#define HERO_H
#include <string>
#include <iostream>
using namespace std;

class Hero
{
private:
    string heroName;
    int health;
    int basePower;

public:
    Hero(string n, int h, int p);
    ~Hero();
    string getName() const;
    int getHealth() const;
    int getPower() const;
    void takeDamage(int damage);
    bool operator>(const Hero &other) const; // Operator overloading
    int operator+(const Hero &other) const;  // Operator overloading
};
#endif