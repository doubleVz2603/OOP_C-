#include "Employee.h"
#include <string>

Date::Date() {}
Date::Date(string day, string month, string year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}
string Date::getDay()
{
    return day;
}
string Date::getMonth()
{
    return month;
}

string Date::getYear()
{
    return year;
}
Employee ::Employee() {}
Employee ::Employee(int ID, string fullName, string email, string phone, Date birthDay, EmployeeType employee_type)
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
Date Employee ::getBirthDay()
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
void Employee::setBirthDay(Date birthDay)
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
void Employee::input() {}
int Employee::employee_count;
void phoneException(string phone)
{
    if (phone.length() != 10)
    {
        throw "phone number isn't length enough...";
    }
    else
    {
        if ((int(phone[0]) - 48) != 0)
        {
            throw "error format input...";
        }
        for (int i = 1; i < phone.length(); i++)
        {
            if ((int(phone[i]) - 48) < 0 || (int(phone[i]) - 48) > 9)
            {
                throw "error format input...";
            }
        }
    }
}

void fullNameException(string fullName)
{
    for (int i = 0; i < fullName.length(); i++)
    {
        if ((int(fullName[i]) > 90 && int(fullName[i]) < 97) || (int(fullName[i]) < 65 && int(fullName[i]) != 32))
        {
            throw "error format input...";
        }
        else if (int(fullName[i]) > 122)
        {
            throw "error format input...";
        }
        else if (int(fullName[i]) == 32 && int(fullName[i + 1]) == 32)
        {
            throw "error format input...";
        }
    }
}

void emailException(string email)
{
    int check = 0, checkDot = 0;
    for (int i = 0; i < email.length(); i++)
    {
        if (email[i] == '@')
        {
            ++check;
        }
        if (email[i] == '.')
        {
            ++checkDot;
        }
    }
    if (check != 1 || checkDot != 1)
    {
        throw "error format input...";
    }
    else
    {
        string temp = email.substr(0, email.find("@"));

        if (temp.length() < 6 || temp.length() > 30)
        {
            throw "error format input...";
        }
        for (int i = 0; i < email.length(); i++)
        {
            if ((int(email[i]) < 48 && int(email[i]) != 46) || ((int(email[i]) > 57 && int(email[i]) != 64) && int(email[i]) < 97))
            {
                throw "error format input...";
            }
            else if (int(email[i]) > 122)
            {
                throw "error format input...";
            }
            
        }
    }
}

void dateException(string day, string month, string year)
{
    // month exception

    for (int i = 0; i < month.length(); i++)
    {
        if (int(month[i]) < 48 || int(month[i]) > 57)
        {
            throw "error format input...";
        }
    }
    if (stoi(month) < 1 || stoi(month) > 12)
    {
        throw "error format input...";
    }
    if (month[0] == 0)
    {
        throw "error format input...";
    }
    // year exception
    for (int i = 0; i < year.length(); i++)
    {
        if (int(year[i]) < 48 || int(year[i]) > 57)
        {
            throw "error format input...";
        }
    }
    if (stoi(year) < 1900)
    {
        throw "error format input...";
    }

    // day exception
    for (int i = 0; i < day.length(); i++)
    {
        if (int(day[i]) < 48 || int(day[i]) > 57)
        {
            throw "error format input...";
        }
    }

    switch (stoi(month))
    {
    case 1:
        if (stoi(day) < 1 || stoi(day) > 31)
        {
            throw "error format input...";
        }
        break;
    case 2:
        if (stoi(year) % 4 == 0)
        {
            if (stoi(day) < 1 || stoi(day) > 28)
            {
                throw "error format input...";
            }
        }
        else
        {
            if (stoi(day) < 1 || stoi(day) > 29)
            {
                throw "error format input...";
            }
        }

        break;
    case 3:
        if (stoi(day) < 1 || stoi(day) > 31)
        {
            throw "error format input...";
        }
        break;
    case 4:
        if (stoi(day) < 1 || stoi(day) > 30)
        {
            throw "error format input...";
        }
        break;
    case 5:
        if (stoi(day) < 1 || stoi(day) > 31)
        {
            throw "error format input...";
        }
        break;
    case 6:
        if (stoi(day) < 1 || stoi(day) > 30)
        {
            throw "error format input...";
        }
        break;
    case 7:
        if (stoi(day) < 1 || stoi(day) > 31)
        {
            throw "error format input...";
        }
        break;
    case 8:
        if (stoi(day) < 1 || stoi(day) > 31)
        {
            throw "error format input...";
        }
        break;
    case 9:
        if (stoi(day) < 1 || stoi(day) > 30)
        {
            throw "error format input...";
        }
        break;
    case 10:
        if (stoi(day) < 1 || stoi(day) > 31)
        {
            throw "error format input...";
        }
        break;
    case 11:
        if (stoi(day) < 1 || stoi(day) > 30)
        {
            throw "error format input...";
        }
        break;
    case 12:
        if (stoi(day) < 1 || stoi(day) > 31)
        {
            throw "error format input...";
        }
        break;
    default:
        break;
    }
}