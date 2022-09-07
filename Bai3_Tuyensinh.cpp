#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Candidate
{
private:
    int ID, levelPriority;
    string fullName, address;

public:
    Candidate(int ID, int levelPriority, string fullName, string address)
    {
        this->ID = ID;
        this->levelPriority = levelPriority;
        this->fullName = fullName;
        this->address = address;
    }
    string getFullName()
    {
        return fullName;
    }
    string getAddress()
    {
        return address;
    }
    int getLevelPriority()
    {
        return levelPriority;
    }
    int getID()
    {
        return ID;
    }

    void show()
    {
        cout << "ID: " << ID << endl;
        cout << "full name: " << fullName << endl;
        cout << "address: " << address << endl;
        cout << "level priority: " << levelPriority << endl;
    };
};

class GradeA : public Candidate
{
public:
    GradeA(int ID, int levelPriority, string fullName, string address)
        : Candidate(ID, levelPriority, fullName, address) {}
};

class GradeB : public Candidate
{
public:
    GradeB(int ID, int levelPriority, string fullName, string address)
        : Candidate(ID, levelPriority, fullName, address) {}
};

class GradeC : public Candidate
{
public:
    GradeC(int ID, int levelPriority, string fullName, string address)
        : Candidate(ID, levelPriority, fullName, address) {}
};

class Management
{
private:
    vector<pair<unique_ptr<Candidate>, string>> listCandidate;

public:
    void add(unique_ptr<Candidate> candidate, string grade)
    {
        pair<unique_ptr<Candidate>, string> pair = make_pair(move(candidate), grade);
        listCandidate.push_back(move(pair));
    }

    void searchByID(int ID)
    {
        int count = 0;
        for (int i = 0; i < listCandidate.size(); i++)
        {

            if (listCandidate[i].first->getID() == ID)
            {
                listCandidate[i].first->show();
                cout << listCandidate[i].second << endl;
                ++count;
            }
        }
        if (count == 0)
        {
            cout << "not found" << endl;
        }
    }

    void allShow()
    {
        system("CLS");
        for (int i = 0; i < listCandidate.size(); i++)
        {
            cout << endl
                 << "Candidate " << i + 1 << ": " << endl;
            listCandidate[i].first->show();
            cout << listCandidate[i].second << endl;
        }
    }
};

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