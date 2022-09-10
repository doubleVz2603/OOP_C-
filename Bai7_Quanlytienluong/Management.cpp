#include "Teacher.h"
#include <vector>
#include <iostream>

using namespace std;
class Management
{
private:
    vector<Teacher> listTeacher;

public:
    void add(Teacher teacher)
    {
        listTeacher.push_back(teacher);
    }

    void removeByID(int ID)
    {
        int i;
        vector<Teacher>::iterator index = listTeacher.begin();
        for (index, i = 0; index != listTeacher.end(), i < listTeacher.size(); ++index, ++i)
        {
            if (listTeacher[i].getID() == ID)
            {
                listTeacher.erase(index);
            }
        }
    }
    void allShow()
    {
        for (int j = 0; j < listTeacher.size(); ++j)
        {
            cout << "member " << j + 1 << endl;
            cout << "full name: " << listTeacher[j].getFullName() << endl;
            cout << "ID: " << listTeacher[j].getID() << endl;
            cout << "age: " << listTeacher[j].getAge() << endl;
            cout << "address: " << listTeacher[j].getAddress() << endl;
            cout << "real salary: " << listTeacher[j].getRealSalary() << endl
                 << endl;
        }
    }
};