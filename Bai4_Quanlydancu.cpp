#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Person
{
private:
    int ID, age;
    string fullName, job;

public:
    Person(int ID, int age, string fullName, string job)
    {
        this->ID = ID;
        this->age = age;
        this->fullName = fullName;
        this->job = job;
    }
    string getFullName()
    {
        return fullName;
    }
    string getJob()
    {
        return job;
    }
    int getAge()
    {
        return age;
    }
    int getID()
    {
        return ID;
    }
};

class Family
{
private:
    int memberAmount, houseNumber;
    vector<Person> listPerson;

public:
    void setMemberAmount(int memberAmount)
    {
        this->memberAmount = memberAmount;
    }
    void setHouseNumber(int houseNumber)
    {
        this->houseNumber = houseNumber;
    }
    int getMemberAmount()
    {
        return memberAmount;
    }
    int getHouseNumber()
    {
        return houseNumber;
    }

    void setListPerson(Person person)
    {
        this->listPerson.push_back(person);
    }

    vector<Person> getListPerson()
    {
        return listPerson;
    }
};

class Management
{
private:
    vector<Family> listFamily;

public:
    void input(int n)
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
    void output()
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
};

int main()
{
    Management management;
    int n;
    cout << "enter number of family: ";
    cin >> n;
    management.input(n);
    system("CLS");
    management.output();
}