#ifndef CANDIDATE_H
#define CANDIDATE_H
#include <iostream>
using namespace std;
class Candidate
{
private:
    int ID, levelPriority;
    string fullName, address;

public:
    Candidate(int, int, string, string);

    string getFullName();

    string getAddress();

    int getLevelPriority();

    int getID();

    void show();
};

#endif