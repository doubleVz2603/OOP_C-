#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Person{
    private:
        int age;
        string fullName, address;
    public:
        Person(int age, string fullName, string address)
        {
            this->age = age;
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
        int getAge()
        {
            return age;
        }

};

class Student : public Person{
    private:
        int grade;
    public:
        Student(string fullName, string address, int age, int grade)
        :Person(age, fullName, address)
        {
            this->grade = grade;
        }
        void show(){
            cout<<"full name: " <<getFullName()<<endl;
            cout<<"address: " <<getAddress()<<endl;
            cout<<"age: "<<getAge()<<endl;
            cout<<"grade: "<<grade<<endl;
        };
};


void menu()
{
    int mainChoice, inChoice;
    int age, grade;
    string fullName, address;

    vector<Student> listStudent;
	while(1)
	{
		system("CLS");
		cout<<"----------------------------Menu-----------------------------"<<endl;
		cout<<"----------1. add information of student           -----------"<<endl;
		cout<<"----------2. show student having age > 20         -----------"<<endl;
        cout<<"----------3. sum of student follow age and address-----------"<<endl;
		cout<<"----------4. exit                                 -----------"<<endl;
		cout<<"enter your choice: ";
		cin>>mainChoice;
		switch (mainChoice)
		{
			case 1:
			{
                system("CLS");
                cout<<"full name: ";
                fflush(stdin);
                getline(cin, fullName);
                cout<<"address: ";
                getline(cin, address);
                cout<<"age: ";
                cin>>age;
                cout<<"grade: ";
                cin>>grade;

                Student student(fullName, address, age, grade);
                listStudent.push_back(student);
				break;
			}
			case 2:
			{
                system("CLS");
                for (int i = 0; i < listStudent.size(); i++)
                {
                    if(listStudent[i].getAge() > 20)
                    {
                        listStudent[i].show();
                    }
                }
                
                cout<<"press 0 to back to menu...";
				cin>>inChoice;
				break;
			}
            case 3:
			{
                int sum = 0;
                system("CLS");
                cout<<"enter age: ";
                cin>>age;
                cout<<"enter address: ";
                fflush(stdin);
                getline(cin, address);
				for (int i = 0; i < listStudent.size(); i++)
                {
                    if(listStudent[i].getAge() == age && listStudent[i].getAddress().compare(address) == 0)
                    {
                        ++sum;
                    }
                }
                cout<<sum<<endl;
                cout<<"press 0 to back to menu...";
				cin>>inChoice;
				break;
			}
		}
        
		if(mainChoice == 4)
		{
			break;
		}	
	}
}
int main()
{
    menu();
}