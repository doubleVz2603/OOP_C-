#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;
class Person
{
private:
    int ID, age;
    string fullName, job;

public:
    Person(int, int, string, string);

    string getFullName();

    string getJob();

    int getAge();

    int getID();
};
#endif