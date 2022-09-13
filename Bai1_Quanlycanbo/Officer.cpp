#include "Officer.h"

Officer::Officer(string fullName, string address, string gender, int age)
{
    this->fullName = fullName;
    this->address = address;
    this->gender = gender;
    this->age = age;
}
string Officer::getFullName()
{
    return fullName;
}
string Officer::getAddress()
{
    return address;
}
string Officer::getGender()
{
    return gender;
}
int Officer::getAge()
{
    return age;
}

void Officer:: show(){}