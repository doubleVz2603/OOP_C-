#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;


class Person
{
private:
    int age, ID;
    string fullName, address;

public:
    Person();
    Person(int, string, string, int);
    string getFullName();
    string getAddress();
    int getAge();
    int getID();
};

#endif