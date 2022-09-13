#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include "Employee.h"
#include <vector>

class Management
{
private:
    vector<Employee*> listEmployee;

public:
    Management();
    void add(Employee&);
    void allShow();
    void removeByID(int);
    void update(int);
    void showByType(EmployeeType);
    vector<Employee*> getListEmployee();
};
#endif