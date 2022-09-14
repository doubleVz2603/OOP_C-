#include "Person.h"

Person::Person(int ID, int age, string fullName, string job)
{
    this->ID = ID;
    this->age = age;
    this->fullName = fullName;
    this->job = job;
}
string Person::getFullName()
{
    return fullName;
}
string Person::getJob()
{
    return job;
}
int Person::getAge()
{
    return age;
}
int Person::getID()
{
    return ID;
}
