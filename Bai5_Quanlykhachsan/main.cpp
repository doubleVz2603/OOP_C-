#include <iostream>
#include <vector>
#include <memory>
#include "Management.h"
using namespace std;


void menu()
{
    int mainChoice, inChoice;
    char roomChoice;
    int ID, age, numRentalDays;
    string fullName, category;
    Management management;
    while (1)
    {
        system("CLS");
        cout << "----------------------------Menu----------------------------" << endl;
        cout << "----------1. enter information of booking person -----------" << endl;
        cout << "----------2. remove booking person by ID         -----------" << endl;
        cout << "----------3. bill of booking person              -----------" << endl;
        cout << "----------4. show booking person list            -----------" << endl;
        cout << "----------5. exit                                -----------" << endl;
        cout << "enter your choice: ";
        cin >> mainChoice;
        switch (mainChoice)
        {
        case 1:
        {
            Person person;
            system("CLS");
            fflush(stdin);
            cout << "full name: ";
            getline(cin, fullName);
            person.setFullName(fullName);
            cout << "ID: ";
            cin >> ID;
            person.setID(ID);
            cout << "age: ";
            cin >> age;
            person.setAge(age);

            system("CLS");
            cout << "type of room which want to choose: " << endl;
            Booking booking;
            booking.setPerson(person);

            cout << "press A to choose room 500$/day" << endl;
            cout << "press B to choose room 300$/day" << endl;
            cout << "press B to choose room 100$/day" << endl;
            cin >> roomChoice;

            if (roomChoice == 'A')
            {
                booking.setCategory(A);
                system("CLS");
            }
            else if (roomChoice == 'B')
            {
                booking.setCategory(B);
                system("CLS");
            }
            else if (roomChoice == 'C')
            {
                booking.setCategory(C);
                system("CLS");
            }

            cout << "number of rental days: " << endl;
            cin >> numRentalDays;
            booking.setNumRentalDays(numRentalDays);

            management.add(booking);
            break;
        }
        case 2:
        {
            system("CLS");
            cout << "enter ID which want to remove: " << endl;
            cin >> ID;
            management.removeBooking(ID);
            cout << "press 0 to back to menu...";
            cin >> inChoice;
            break;
        }
        case 3:
        {
            system("CLS");
            cout << "enter ID of booking person:" << endl;
            cin >> ID;
            cout << "bill of booking person: " << endl;
            system("CLS");
            management.bill(ID);
            cout << "press 0 to back to menu...";
            cin >> inChoice;
            break;
        }
        case 4:
        {
            system("CLS");
            management.allShow();
            cout << "press 0 to back to menu...";
            cin >> inChoice;
            break;
        }
        }
        if (mainChoice == 5)
        {
            break;
        }
    }
}

int main()
{
    menu();
}