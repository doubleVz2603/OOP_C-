#ifndef FRESHER_H
#define FRESHER_H
#include "Employee.h"
#include <iostream>
using namespace std;

class Fresher : public Employee
{
private:
    int graduation_date;
    string graduation_rank, graduation_education;
    
public:
    Fresher();
    Fresher(int, string, string, int, string, string, string, Date, EmployeeType);
    void showInfo();
    
    void input();
};
#endif