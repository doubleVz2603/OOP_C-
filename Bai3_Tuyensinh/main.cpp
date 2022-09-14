#include <iostream>
#include <vector>
#include <memory>
#include "Management.h"
#include "GradeA.cpp"
#include "GradeB.cpp"
#include "GradeC.cpp"
using namespace std;



void menu()
{
    int mainChoice, inChoice;
    int ID, levelPriority;
    string fullName, address;

    Management management;
    while (1)
    {
        system("CLS");
        cout << "----------------------------Menu----------------------------" << endl;
        cout << "----------1. add information of candidate        -----------" << endl;
        cout << "----------2. show candidate list                 -----------" << endl;
        cout << "----------3. search candidate by ID              -----------" << endl;
        cout << "----------4. exit                                -----------" << endl;
        cout << "enter your choice: ";
        cin >> mainChoice;
        switch (mainChoice)
        {
        case 1:
        {
            system("CLS");
            cout << "1. Grade A" << endl;
            cout << "2. Grade B" << endl;
            cout << "3. Grade C" << endl;
            cout << "4. Back" << endl;
            cin >> inChoice;
            if (inChoice == 4)
            {
                break;
            }

            system("CLS");

            cout << "ID: ";
            cin >> ID;
            cout << "full name: ";
            fflush(stdin);
            getline(cin, fullName);
            cout << "address: ";
            getline(cin, address);
            cout << "level priority: ";
            cin >> levelPriority;

            if (inChoice == 1)
            {
                management.add(unique_ptr<Candidate>(new GradeA(ID, levelPriority, fullName, address)), "grade A");
                system("CLS");
            }
            else if (inChoice == 2)
            {
                management.add(unique_ptr<Candidate>(new GradeB(ID, levelPriority, fullName, address)), "grade B");
                system("CLS");
            }
            else if (inChoice == 3)
            {
                management.add(unique_ptr<Candidate>(new GradeC(ID, levelPriority, fullName, address)), "grade C");
                system("CLS");
            }
            break;
        }
        case 2:
        {
            system("CLS");
            management.allShow();
            cout << "press 0 to back to menu...";
            cin >> inChoice;
            break;
        }
        case 3:
        {
            system("CLS");
            cout << "enter ID to search: ";
            cin >> ID;
            management.searchByID(ID);
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