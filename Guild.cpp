#include "Guild.h"

Guild::Guild(string n) // Constructor
{
    guildName = n;
    memberCount = 0;
    for (int i = 0; i < 15; i++)
    {
        roster[i] = nullptr; // Initialize ptr array to nullptr
    }
}

Guild::~Guild()
{
    cout << "The guild " << guildName << " has been disbanded!\n"; // Print message when destructor is used
}

int Guild::calculateTotalGuildPower() const
{
    int total = 0;
    for (int i = 0; i < memberCount; i++)
    {
        total = total + roster[i]->getPower();
    }
    return total;
}

void Guild::displayGuildStats() const // Function to display stats
{
    cout << "Guild Name: " << guildName << endl;
    cout << "Total Members: " << memberCount << "/15" << endl;
    cout << "Total Guild Power: " << calculateTotalGuildPower() << endl;
}

void Guild::operator+=(Hero *newHero)
{
    if (memberCount < 15) // check if array has space for new hero
    {
        roster[memberCount] = newHero; // Add hero to array
        memberCount++;
    }
    else
    {
        cout << "Guild is at full capacity!" << endl;
    }
}

ostream &operator<<(ostream &os, const Guild &g) // Function to output stats
{
    os << "Guild: " << g.guildName << endl;
    os << "Members: " << g.memberCount << "/15" << endl;
    for (int i = 0; i < g.memberCount; i++)
    {
        os << "- " << g.roster[i]->getName() << " (Power: " << g.roster[i]->getPower() << ")" << endl;
    }
    return os;
}