#include "Employee.h"

Employee ::Employee() {}
Employee ::Employee(int ID, string fullName, string email, string phone, string birthDay, EmployeeType employee_type)
{
    this->fullName = fullName;
    this->birthDay = birthDay;
    this->email = email;
    this->phone = phone;
    this->ID = ID;
    this->employee_type = employee_type;
}

int Employee ::getID()
{
    return ID;
}
string Employee ::getFullName()
{
    return fullName;
}
string Employee ::getEmail()
{
    return email;
}
string Employee ::getPhone()
{
    return phone;
}
string Employee ::getBirthDay()
{
    return birthDay;
}
EmployeeType Employee::getEmployeeType()
{
    return employee_type;
}
int Employee::getEmployeeCount()
{
    return employee_count;
}


void Employee::setID(int ID)
{
    this->ID = ID;
}
void Employee::setFullName(string fullName)
{
    this->fullName = fullName;
}
void Employee::setEmail(string email)
{
    this->ID = ID;
}
void Employee::setPhone(string phone)
{
    this->phone = phone;
}
void Employee::setBirthDay(string birthday)
{
    this->birthDay = birthDay;
}


void Employee::update() {}
void Employee::showInfo() {}
int Employee::employee_count;