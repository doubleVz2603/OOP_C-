#include <iostream>
#include <vector>
#include "Management.cpp"
#include "Teacher.h"

using namespace std;

void menu()
{
    int mainChoice, inChoice;
    int ID, age, fixSalary, bonus, fine;
    string fullName, address;
    Management management;
    while (1)
    {
        system("CLS");
        cout << "----------------------------Menu----------------------------" << endl;
        cout << "----------1. add information of teacher          -----------" << endl;
        cout << "----------2. remove teacher by ID                -----------" << endl;
        cout << "----------3. show teacher list                   -----------" << endl;
        cout << "----------4. exit                                -----------" << endl;
        cout << "enter your choice: ";
        cin >> mainChoice;
        switch (mainChoice)
        {
        case 1:
        {
            system("CLS");
            fflush(stdin);
            cout << "full name: ";
            getline(cin, fullName);

            cout << "ID: ";
            cin >> ID;

            cout << "age: ";
            cin >> age;
            fflush(stdin);
            cout << "address: ";
            getline(cin, address);

            system("CLS");
            cout << "fix salary: " << endl;
            cin >> fixSalary;

            cout << "bonus: " << endl;
            cin >> bonus;

            cout << "fine: " << endl;
            cin >> fine;

            Teacher teacher(age, fullName, address, ID, fixSalary, bonus, fine);

            management.add(teacher);
            break;
        }
        case 2:
        {
            system("CLS");
            cout << "enter ID which want to remove: " << endl;
            cin >> ID;
            management.removeByID(ID);
            cout << "press 0 to back to menu...";
            cin >> inChoice;
            break;
        }
        case 3:
        {
            system("CLS");
            management.allShow();
            cout << "press 0 to back to menu...";
            cin >> inChoice;
            break;
        }
        }
        if (mainChoice == 4)
        {
            break;
        }
    }
}

int main()
{
    menu();
}