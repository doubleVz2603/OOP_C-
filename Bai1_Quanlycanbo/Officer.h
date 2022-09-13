#ifndef OFFICER_H
#define OFFICER_H
#include <iostream>
using namespace std;
class Officer
{
private:
    string fullName, address, gender;
    int age;

public:
    Officer(string, string, string, int);
    string getFullName();

    string getAddress();

    string getGender();

    int getAge();

    virtual void show() = 0;
};
#endif