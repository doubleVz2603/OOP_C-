#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;
class Person
{
private:
    int ID, age;
    string fullName;

public:
    void setFullName(string);

    void setAge(int);

    void setID(int);

    string getFullName();

    int getAge();

    int getID();
};

#endif