#ifndef EMPLOYEE_H
#define EMPLOYEE_H
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

public:
    Employee();
    Employee(int, string, string, string, string, EmployeeType);
    virtual void showInfo() = 0;
    virtual void update() = 0;

    int getID();
    string getFullName();
    string getEmail();
    string getPhone();
    string getBirthDay();
    EmployeeType getEmployeeType();

    void setID(int);
    void setFullName(string);
    void setEmail(string);
    void setPhone(string);
    void setBirthDay(string);
    static int getEmployeeCount();

    
};



#endif