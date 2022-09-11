#ifndef EXPERIENCE_H
#define EXPERIENCE_H
#include "Employee.h"
#include <iostream>
using namespace std;
class Experience : public Employee
{
private:
    int expInYear;
    string proSkill;
    //Employee_type,Employee_count
public:
    Experience();
    Experience(int, string, int, string, string, string, string, EmployeeType);
    void showInfo();
    void update();
};
#endif