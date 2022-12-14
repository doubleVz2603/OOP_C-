#include "Employee.h"
#include "Intern.h"
#include "Fresher.h"
#include "Experience.h"
#include "Management.h"
#include <iostream>

using namespace std;

void input(Management &management)
{
    char yes_no;
    string inChoice;
    system("CLS");
    cout << "1. Intern" << endl;
    cout << "2. Fresher" << endl;
    cout << "3. Experience" << endl;
    cout << "4. Back" << endl;
    try
    {
        cin >> inChoice;
        if (inChoice.length() > 1 || (int(inChoice[0] - 48) < 1 || int(inChoice[0] - 48) > 4))
        {
            throw "error format input...";
        }
        else
        {
            if (int(inChoice[0] - 48) == 4)
            {
                throw 101;
            }

            system("CLS");
            if (int(inChoice[0] - 48) == 1)
            {
                Employee *employee = new Intern();
                employee->input();
                management.add(*employee);
                system("CLS");
            }
            else if (int(inChoice[0] - 48) == 2)
            {
                Employee *employee = new Fresher();
                employee->input();
                management.add(*employee);
                system("CLS");
            }
            else if (int(inChoice[0] - 48) == 3)
            {
                Employee *employee = new Experience();
                employee->input();
                management.add(*employee);
                system("CLS");
            }
            Employee::setEmployeeCount();
        }
        cout << "Keep adding employee? y/n" << endl;
        cin >> yes_no;
        if (yes_no == 'y')
        {
            input(management);
        }
        else
        {
            cout << "this phase add " << Employee::getEmployeeCount() << " employee." << endl;
            Employee::resetEmployeeCount();
        }
    }
    catch (const char *error)
    {
        cout << error << endl;
    }
    catch (int)
    {
    }
}

void menu()
{
    string mainChoice, inChoice;
    int ID;
    Management management;
    while (1)
    {
        system("CLS");
        cout << "----------------------------Menu--------------------------------------" << endl;
        cout << "------------1. add information of employee               -------------" << endl;
        cout << "------------2. show employee list                        -------------" << endl;
        cout << "------------3. remove employee by ID                     -------------" << endl;
        cout << "------------4. update information of employee by ID      -------------" << endl;
        cout << "------------5. show employee list by type                -------------" << endl;
        cout << "------------6. exit                                      -------------" << endl;
        cout << "enter your choice: ";
        cin >> mainChoice;
        if (mainChoice.length() > 1 || (int(mainChoice[0] - 48) < 0 || int(mainChoice[0] - 48) > 6))
        {
            cout << "error format input..." << endl;
            system("pause");
            break;
        }
        else
        {
            switch (int(mainChoice[0] - 48))
            {
            case 1:
            {
                input(management);
                cout << "press 0 to back to menu...";
                cin >> inChoice;
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
                cout << "enter ID which want to remove: ";
                cin >> ID;
                management.removeByID(ID);
                cout << "press 0 to back to menu...";
                cin >> inChoice;
                break;
            }
            case 4:
            {
                system("CLS");
                cout << "enter ID which want to update: ";
                cin >> ID;
                management.update(ID);
                cout << "press 0 to back to menu...";
                cin >> inChoice;
                break;
            }
            case 5:
            {
                system("CLS");
                cout << "type of employeee: " << endl;
                cout << "press 0 to choose experience list" << endl;
                cout << "press 1 to choose fresher list" << endl;
                cout << "press 2 to choose intern list" << endl;
                cout << "press 3 to exit" << endl;
                try
                {
                    cin >> inChoice;
                    if (inChoice.length() > 1 || (int(inChoice[0] - 48) < 0 || int(inChoice[0] - 48) > 3))
                    {
                        throw "error format input...";
                    }
                    else
                    {
                        if (int(inChoice[0] - 48) == 3)
                        {
                            break;
                        }

                        if (int(inChoice[0] - 48) == 0)
                        {

                            management.showByType(experience);
                            cout << "back to menu press 0..." << endl;
                            cin >> inChoice;
                            break;
                        }
                        else if (int(inChoice[0] - 48) == 1)
                        {

                            management.showByType(fresher);
                            cout << "back to menu press 0..." << endl;
                            cin >> inChoice;
                            break;
                        }
                        else if (int(inChoice[0] - 48) == 2)
                        {
                            management.showByType(intern);
                            cout << "back to menu press 0..." << endl;
                            cin >> inChoice;
                            break;
                        }
                    }
                }
                catch (const char *msg)
                {
                    cout << msg << endl;
                    cout << "back to menu press 0..." << endl;
                    cin >> inChoice;
                }
                break;
            }
            default:
                break;
            }
            if (int(mainChoice[0] - 48) == 6)
            {
                break;
            }
        }
    }

    for (int i = 0; i < management.getListEmployee().size(); i++)
    {
        delete management.getListEmployee()[i];
        management.getListEmployee()[i] = NULL;
    }
    
}
int main()
{
    menu();
}
