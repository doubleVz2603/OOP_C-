#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Certificate.h"
#include <vector>
#include <iostream>
using namespace std;

enum EmployeeType{
    experience,
    fresher,
    intern
};
void phoneException(string);
void fullNameException(string);
void emailException(string);
void dateException(string, string, string);


class Date{
    private:
        string day, month, year;
    public:
        Date();
        Date(string, string, string);
        string getDay();
        string getMonth();
        string getYear();
};


class Employee
{
private:
    int ID;
    string fullName, email, phone;
    Date birthDay;
    static int employee_count;
    EmployeeType employee_type;
    vector<Certificate> listCertificate;

public:
    Employee();
    Employee(int, string, string, string, Date, EmployeeType);
    virtual void showInfo() = 0;
    virtual void input() = 0;

    int getID();
    string getFullName();
    string getEmail();
    string getPhone();
    Date getBirthDay();
    static int getEmployeeCount();
    EmployeeType getEmployeeType();
    vector<Certificate> getListCertificate();

    void setID(int);
    void setFullName(string);
    void setEmail(string);
    void setPhone(string);
    void setBirthDay(Date);
    static void setEmployeeCount();
    static void resetEmployeeCount();
    void setListCertificate(Certificate);    
};



#endif