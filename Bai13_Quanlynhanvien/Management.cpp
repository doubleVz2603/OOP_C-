#include "Management.h"
#include <memory>
#include <vector>
#include <iostream>
using namespace std;
Management ::Management() {}

void Management::add(Employee &employee)
{
    listEmployee.push_back(&employee);
}
void Management::allShow()
{
    for (int i = 0; i < listEmployee.size(); i++)
    {
        cout << endl
             << "employee " << i + 1 << endl;
        listEmployee[i]->showInfo();
    }
}

void Management::removeByID(int ID)
{
    int count = 0;
    int i;
    vector<Employee*>::iterator index = listEmployee.begin();
    for (index, i = 0; index != listEmployee.end(), i < listEmployee.size(); ++index, ++i)
    {
        if (listEmployee[i]->getID() == ID)
        {
            listEmployee.erase(index);
            ++count;
            break;
        }
    }
    if (count == 0)
    {
        cout << "no found" << endl;
    }
}
void Management::update(int ID)
{
    bool exist =false;
    for (int i = 0; i < listEmployee.size(); i++)
    {
        if(listEmployee[i]->getID() == ID)
        {
            listEmployee[i]->update();
            exist = true;
            break;
        }
    }
    if (exist == false)
    {
        cout<<"Employee isn't exist"<<endl;
    }
}

void Management::showByType(EmployeeType employee_type)
{
    for (int i = 0; i < listEmployee.size(); i++)
    {
        if(listEmployee[i]->getEmployeeType() == employee_type)
        {
            listEmployee[i]->showInfo();
        }
    }
    
}