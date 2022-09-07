#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

class Officer
{
private:
    string fullName, address, gender;
    int age;

public:
    Officer(string fullName, string address, string gender, int age)
    {
        this->fullName = fullName;
        this->address = address;
        this->gender = gender;
        this->age = age;
    }
    string getFullName()
    {
        return fullName;
    }
    string getAddress()
    {
        return address;
    }
    string getGender()
    {
        return gender;
    }
    int getAge()
    {
        return age;
    }

    virtual void show() = 0;
};

class Engineer : public Officer
{
private:
    string specialized;

public:
    Engineer(string specialized, string fullName, string address, string gender, int age)
        : Officer(fullName, address, gender, age)
    {
        this->specialized = specialized;
    }
    void show()
    {
        cout << "full name: " << getFullName() << endl;
        cout << "age: " << getAge() << endl;
        cout << "address: " << getAddress() << endl;
        cout << "gender: " << getGender() << endl;
        cout << "specialized: " << specialized << endl;
    }
};

class Worker : public Officer
{
private:
    int level;

public:
    Worker(int level, string fullName, string address, string gender, int age)
        : Officer(fullName, address, gender, age)
    {
        this->level = level;
    }

    void show()
    {
        cout << "full name: " << getFullName() << endl;
        cout << "age: " << getAge() << endl;
        cout << "address: " << getAddress() << endl;
        cout << "gender: " << getGender() << endl;
        cout << "level: " << level << endl;
    }
};

class Staff : public Officer
{
private:
    string job;

public:
    Staff(string job, string fullName, string address, string gender, int age)
        : Officer(fullName, address, gender, age)
    {
        this->job = job;
    }
    void show()
    {
        cout << "full name: " << getFullName() << endl;
        cout << "age: " << getAge() << endl;
        cout << "address: " << getAddress() << endl;
        cout << "gender: " << getGender() << endl;
        cout << "job: " << job << endl;
    }
};

class Management
{
private:
    vector<unique_ptr<Officer>> listOfficer;

public:
    void add(unique_ptr<Officer> officer)
    {
        listOfficer.push_back(move(officer));
    }

    void searchFullName(string fullName)
    {
        int count= 0;
        for (int i = 0; i < listOfficer.size(); i++)
        {
            if (listOfficer[i]->getFullName().compare(fullName) == 0)
            {
                listOfficer[i]->show();
                ++count;
                break;
            }
        }
        if(count == 0)
        {
            cout<<"not found"<<endl;
        }
    }

    void allShow()
    {
        system("CLS");
        for (int i = 0; i < listOfficer.size(); i++)
        {
            cout << endl
                 << "officer " << i + 1 << ": " << endl;
            listOfficer[i]->show();
        }
    }
};

void menu()
{
    string mainChoice, inChoice;
    string fullName, address, gender, specialized, job, age, level;

    Management management;
    while (1)
    {
        system("CLS");
        cout << "----------------------------Menu----------------------------" << endl;
        cout << "----------1. enter information of officer        -----------" << endl;
        cout << "----------2. search with full name               -----------" << endl;
        cout << "----------3. show officer list                   -----------" << endl;
        cout << "----------4. exit                                -----------" << endl;
        cout << "enter your choice: ";
        cin >> mainChoice;
        if (mainChoice.length() > 1 || (int(mainChoice[0] - 48) < 0 || int(mainChoice[0] - 48) > 4))
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
                system("CLS");
                cout << "1. worker" << endl;
                cout << "2. engineer" << endl;
                cout << "3. staff" << endl;
                cout << "4. Back" << endl;
                try
                {
                    cin >> inChoice;
                    if (inChoice.length() > 1 || (int(inChoice[0] - 48) < 0 || int(inChoice[0] - 48) > 4))
                    {
                        throw "error format input...";
                    }
                    else
                    {
                        if (int(inChoice[0] - 48) == 4)
                        {
                            break;
                        }
                        system("CLS");
                        fflush(stdin);
                        cout << "name: ";
                        getline(cin, fullName);
                        cout << "address: ";
                        getline(cin, address);
                        cout << "gender: ";
                        cin >> gender;
                        try
                        {
                            cout << "age: ";
                            cin >> age;
                            if (age.length() != 2)
                            {
                                throw "age is not reasonable";
                            }
                            else
                            {
                                for (int i = 0; i < age.length(); i++)
                                {
                                    if (int(age[i]) > 57 || int(age[i]) < 48)
                                    {
                                        throw 101;
                                    }
                                }
                            }
                        }
                        catch (const char *error)
                        {
                            cout << error << endl;
                            system("pause");
                            break;
                        }
                        catch (int)
                        {
                            cout << "error format input..." << endl;
                            system("pause");
                            break;
                        }

                        if (int(inChoice[0] - 48) == 1)
                        {
                            try
                            {
                                cout << "level: ";
                                cin >> level;
                                if(stoi(level) < 1 || stoi(level) > 10)
                                {
                                    throw "no level searched";
                                }
                                for (int i = 0; i < age.length(); i++)
                                {
                                    if (int(age[i]) > 57 || int(age[i]) < 48)
                                    {
                                        throw 101;
                                    }
                                    
                                }
                                
                            }
                            catch(const char* error)
                            {
                                cout << error << endl;
                                system("pause");
                                break;
                            }
                            catch(int)
                            {
                                cout << "error format input..." << endl;
                                system("pause");
                                break;
                            }
                            
                            management.add(unique_ptr<Officer>(new Worker(stoi(level), fullName, address, gender, stoi(age))));
                            system("CLS");
                        }
                        else if (int(inChoice[0] - 48) == 2)
                        {
                            fflush(stdin);
                            cout << "specialized: ";
                            getline(cin, specialized);
                            management.add(unique_ptr<Officer>(new Engineer(specialized, fullName, address, gender, stoi(age))));
                            system("CLS");
                        }
                        else if (int(inChoice[0] - 48) == 3)
                        {
                            fflush(stdin);
                            cout << "job: ";
                            getline(cin, job);
                            management.add(unique_ptr<Officer>(new Staff(job, fullName, address, gender, stoi(age))));
                            system("CLS");
                        }
                    }
                }
                catch (const char *msg)
                {
                    cout << msg << endl;
                    cout << "back to menu press 0" << endl;
                    cin >> inChoice;
                }

                break;
            }
            case 2:
            {
                system("CLS");
                cout << "enter full name to search: ";
                fflush(stdin);
                getline(cin, fullName);
                management.searchFullName(fullName);
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
            default:
                break;
            }
            if (int(mainChoice[0] - 48) == 4)
            {
                break;
            }
        }
    }
}
int main()
{
    menu();
}