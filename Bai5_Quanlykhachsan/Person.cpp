#include "Person.h"

void Person::setFullName(string fullName)
{
    this->fullName = fullName;
}
void Person::setAge(int age)
{
    this->age = age;
}
void Person::setID(int ID)
{
    this->ID = ID;
}
string Person::getFullName()
{
    return fullName;
}
int Person::getAge()
{
    return age;
}
int Person::getID()
{
    return ID;
}
