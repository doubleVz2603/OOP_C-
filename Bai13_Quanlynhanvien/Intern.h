#ifndef INTERN_H
#define INTERN_H
#include "Employee.h"
#include <iostream>
using namespace std;


class Intern : public Employee
{
private:
    string majors, semester, university_name;
    
public:
    Intern();
    Intern(string, string, string, int, string, string, string, Date, EmployeeType);
    void showInfo();
    
    void input();
};
#endif