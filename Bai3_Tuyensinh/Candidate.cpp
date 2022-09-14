#include "Candidate.h"

Candidate::Candidate(int ID, int levelPriority, string fullName, string address)
{
    this->ID = ID;
    this->levelPriority = levelPriority;
    this->fullName = fullName;
    this->address = address;
}
string Candidate::getFullName()
{
    return fullName;
}
string Candidate::getAddress()
{
    return address;
}
int Candidate::getLevelPriority()
{
    return levelPriority;
}
int Candidate::getID()
{
    return ID;
}

void Candidate::show()
{
    cout << "ID: " << ID << endl;
    cout << "full name: " << fullName << endl;
    cout << "address: " << address << endl;
    cout << "level priority: " << levelPriority << endl;
};
