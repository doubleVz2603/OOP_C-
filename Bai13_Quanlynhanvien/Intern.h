#ifndef INTERN_H
#define INTERN_H
#include "Employee.h"
#include <iostream>
using namespace std;
class Intern : public Employee
{
private:
    string majors, semester, university_name;
    //Employee_type,Employee_count
public:
    Intern();
    Intern(string, string, string, int, string, string, string, string, EmployeeType);
    void showInfo();
    void update();
};
#endif