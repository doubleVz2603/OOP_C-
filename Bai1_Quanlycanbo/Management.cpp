#include "Management.h"

void Management::add(unique_ptr<Officer> officer)
{
    listOfficer.push_back(move(officer));
}

void Management::searchFullName(string fullName)
{
    int count = 0;
    for (int i = 0; i < listOfficer.size(); i++)
    {
        if (listOfficer[i]->getFullName().compare(fullName) == 0)
        {
            listOfficer[i]->show();
            ++count;
            break;
        }
    }
    if (count == 0)
    {
        cout << "not found" << endl;
    }
}

void Management::allShow()
{
    system("CLS");
    for (int i = 0; i < listOfficer.size(); i++)
    {
        cout << endl
             << "officer " << i + 1 << ": " << endl;
        listOfficer[i]->show();
    }
}