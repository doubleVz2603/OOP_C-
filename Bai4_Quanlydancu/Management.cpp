#include "Management.h"

void Management::input(int n)
{
    int ID, age, memberAmount, houseNumber;
    string fullName, job;

    for (int i = 0; i < n; ++i)
    {
        Family family;
        cout << "family " << i + 1 << endl;
        cout << "member in family: ";
        cin >> memberAmount;

        family.setMemberAmount(memberAmount);

        for (int j = 0; j < memberAmount; ++j)
        {
            cout << "member " << j + 1 << endl;
            cout << "ID: ";
            cin >> ID;
            cout << "full name: ";
            fflush(stdin);
            getline(cin, fullName);
            cout << "job: ";
            getline(cin, job);
            cout << "age: ";
            cin >> age;
            family.setListPerson(Person(ID, age, fullName, job));
        }
        cout << "house number: ";
        cin >> houseNumber;
        cout << endl
             << endl;
        family.setHouseNumber(houseNumber);
        listFamily.push_back(family);
    }
}
void Management::output()
{
    for (int i = 0; i < listFamily.size(); ++i)
    {
        cout << "family " << i + 1 << endl;
        cout << "house number: " << listFamily[i].getHouseNumber() << endl;
        cout << "member in family: " << listFamily[i].getMemberAmount() << endl
             << endl;
        for (int j = 0; j < listFamily[i].getListPerson().size(); ++j)
        {
            cout << "member " << j + 1 << endl;
            cout << "full name: " << listFamily[i].getListPerson()[j].getFullName() << endl;
            cout << "ID: " << listFamily[i].getListPerson()[j].getID() << endl;
            cout << "age: " << listFamily[i].getListPerson()[j].getAge() << endl;
            cout << "job: " << listFamily[i].getListPerson()[j].getJob() << endl
                 << endl;
        }
    }
}
