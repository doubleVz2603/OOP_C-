#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Person{
    private:
        int age, ID;
        string fullName, address;
    public:
        Person(int age, string fullName, string address, int ID)
        {
            this->ID = ID;
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
        int getID()
        {
            return ID;
        }

};

class Teacher: public Person{
    private:
       int fixSalary, bonus, fine;
    public:
        Teacher(int age, string fullName, string address, int ID, int fixSalary, int bonus, int fine)
        :Person(age, fullName, address, ID)
        {
            this->fixSalary = fixSalary;
            this->bonus = bonus;
            this->fine = fine;
        }
        void setFixSalary(int fixSalry)
        {   
            this->fixSalary = fixSalary;
        }
        void setBonus(int bonus)
        {
            this->bonus = bonus;
        }

        void setFine(int fine)
        {
            this->fine = fine;
        }
        // void setRemainSalary(int remainSalary)
        // {
        //     this->remainSalary = remainSalary;
        // }
        int getFixSalary()
        {
            return fixSalary;
        }
        int getBonus()
        {
            return bonus;
        }
        int getFine()
        {
            return fine;
        }
        // int getRemainSalary()
        // {
        //     return remainSalary;
        // }

        int getRealSalary()
        {
            return fixSalary + bonus - fine;
        }

};

class Management{
    private:
        vector<Teacher> listTeacher;
    public:
        void add(Teacher teacher)
        {
            listTeacher.push_back(teacher);
        }

        void removeByID(int ID)
        {
            int i;
            vector<Teacher>::iterator index = listTeacher.begin();
            for (index, i = 0; index != listTeacher.end(), i < listTeacher.size(); ++index, ++i) 
            {
                if(listTeacher[i].getID() == ID)
                {
                    listTeacher.erase(index);
                }
            }
        }
        void allShow()
        {
            for(int j = 0; j < listTeacher.size(); ++ j)
                {
                    cout<<"member "<<j+1<<endl;
                    cout<<"full name: "<<listTeacher[j].getFullName()<<endl;
                    cout<<"ID: "<<listTeacher[j].getID()<<endl;
                    cout<<"age: "<<listTeacher[j].getAge()<<endl;
                    cout<<"address: "<<listTeacher[j].getAddress()<<endl;
                    cout<<"real salary: "<<listTeacher[j].getRealSalary()<<endl<<endl;
                }
        }
        
};

void menu()
{
    int mainChoice, inChoice;
    int ID, age, fixSalary, bonus, fine;
    string fullName, address;
    Management management;
	while(1)
	{
		system("CLS");
		cout<<"----------------------------Menu----------------------------"<<endl;
		cout<<"----------1. add information of teacher          -----------"<<endl;
		cout<<"----------2. remove teacher by ID                -----------"<<endl;
        cout<<"----------3. show teacher list                   -----------"<<endl;
		cout<<"----------4. exit                                -----------"<<endl;
		cout<<"enter your choice: ";
		cin>>mainChoice;
		switch (mainChoice)
		{
			case 1:
			{
                
                system("CLS");
                fflush(stdin);
                cout<<"full name: ";
                getline(cin, fullName);
                
                cout<<"ID: ";
                cin>>ID;
               
                cout<<"age: ";
                cin>>age;

                cout<<"address: ";
                getline(cin, address);
                
                system("CLS");
                cout<<"fix salary: "<<endl;
                cin>>fixSalary;
                
                cout<<"bonus: "<<endl;
                cin>>bonus;
                
                cout<<"fine: "<<endl;
                cin>>fine;
                
                Teacher teacher(age, fullName, address, ID, fixSalary, bonus, fine);

                management.add(teacher);
				break;
			}
			case 2:
			{
				system("CLS");
                cout<<"enter ID which want to remove: "<<endl;
                cin>>ID;
                management.removeByID(ID);
				cout<<"press 0 to back to menu...";
				cin>>inChoice;
				break;
			}
            case 3:
			{
                system("CLS");
				management.allShow();
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