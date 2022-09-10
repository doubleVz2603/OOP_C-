
#include "Person.h"

#include <iostream>
Person ::Person() {}

Person ::Person(int age, string fullName, string address, int ID)
{
    this->ID = ID;
    this->age = age;
    this->fullName = fullName;
    this->address = address;
}
string Person ::getFullName()
{
    return fullName;
}
string Person ::getAddress()
{
    return address;
}
int Person :: getAge()
{
    return this-> age;
}
int Person :: getID()
{
    return ID;
}
