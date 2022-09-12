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

class Employee
{
private:
    int ID;
    string fullName, email, phone, birthDay;
    static int employee_count;
    EmployeeType employee_type;
    vector<Certificate> listCertificate;

public:
    Employee();
    Employee(int, string, string, string, string, EmployeeType);
    virtual void showInfo() = 0;
    virtual void input() = 0;

    int getID();
    string getFullName();
    string getEmail();
    string getPhone();
    string getBirthDay();
    static int getEmployeeCount();
    EmployeeType getEmployeeType();
    vector<Certificate> getListCertificate();

    void setID(int);
    void setFullName(string);
    void setEmail(string);
    void setPhone(string);
    void setBirthDay(string);
    static void setEmployeeCount();
    static void resetEmployeeCount();
    void setListCertificate(Certificate);    
};



#endif