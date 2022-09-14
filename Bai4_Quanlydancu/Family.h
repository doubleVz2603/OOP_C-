#ifndef FAMILY_H
#define FAMILY_H
#include <iostream>
#include <vector>
#include "Person.h"
using namespace std;

class Family
{
private:
    int memberAmount, houseNumber;
    vector<Person> listPerson;

public:
    void setMemberAmount(int);

    void setHouseNumber(int);

    int getMemberAmount();

    int getHouseNumber();

    void setListPerson(Person person);

    vector<Person> getListPerson();
};
#endif