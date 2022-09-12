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
vector<Certificate> Employee::getListCertificate()
{
    return listCertificate;
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
    this->email = email;
}
void Employee::setPhone(string phone)
{
    this->phone = phone;
}
void Employee::setBirthDay(string birthDay)
{
    this->birthDay = birthDay;
}
void Employee::setEmployeeCount()
{
    ++employee_count;
}
void Employee::resetEmployeeCount()
{
    employee_count = 0;
}
void Employee::setListCertificate(Certificate certificate)
{
    this->listCertificate.push_back(certificate);
}


void Employee::showInfo() {}
void Employee::input(){}
int Employee::employee_count;
