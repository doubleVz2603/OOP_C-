#include <iostream>
#include <vector>
#include <memory>
using namespace std;

enum Room{
    A = 500,
    B = 300,
    C = 100
};

class Person{
    private:
        int ID, age;
        string fullName;
    public:
        void setFullName(string fullName)
        {
            this->fullName = fullName;
        }
        void setAge(int age)
        {
            this->age = age;
        }
        void setID(int ID)
        {
            this->ID = ID;
        }
        string getFullName()
        {
            return fullName;
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

class Booking{
    private:
        int numRentalDays;
        Room category;
        Person person;
    public:
        void setPerson(Person person)
        {
            this->person = person;
        }
        void setNumRentalDays(int numRentalDays)
        {
            this->numRentalDays = numRentalDays;
        }
        void setCategory(Room category)
        {
            this->category = category;
        }
        Person getPerson()
        {
            return person;
        }
        Room getCategory()
        {
            return category;
        }
        int getNumRentalDays()
        {
            return numRentalDays;
        }

};

class Management{
    private:
        vector<Booking> listBooking;
    public:
        void add(Booking booking)
        {
            listBooking.push_back(booking);
        }
        void removeBooking(int ID)
        {
            int i;
            vector<Booking>::iterator index = listBooking.begin();
            for (index, i = 0; index != listBooking.end(), i < listBooking.size(); ++index, ++i) {
        
            if(listBooking[i].getPerson().getID() == ID)
            {
                listBooking.erase(index);
            }
            }
        }

        void allShow()
        {
            for(int i = 0; i < listBooking.size(); ++ i)
            {
                cout<<"ID: " <<listBooking[i].getPerson().getID()<<endl;
                cout<<"full name: " <<listBooking[i].getPerson().getFullName()<<endl;
                cout<<"age: " <<listBooking[i].getPerson().getAge()<<endl;
                cout<<"kind of room: " <<listBooking[i].getCategory()<<endl;
                cout<<"number of rental days: " <<listBooking[i].getNumRentalDays()<<endl;
            }
        }

        void bill(int ID)
        {
            int sum = 0;
            for (int i = 0; i < listBooking.size(); ++i) {
        
            if(listBooking[i].getPerson().getID() == ID)
            {
                sum = listBooking[i].getNumRentalDays() * listBooking[i].getCategory();
                break;
            }
            }
            cout<<"bill of booking person: "<<sum;
        }
};

void menu()
{
    int mainChoice, inChoice;
    char roomChoice;
    int ID, age, numRentalDays;
    string fullName, category;
    Management management;
	while(1)
	{
		system("CLS");
		cout<<"----------------------------Menu----------------------------"<<endl;
		cout<<"----------1. enter information of booking person -----------"<<endl;
		cout<<"----------2. remove booking person by ID         -----------"<<endl;
		cout<<"----------3. bill of booking person              -----------"<<endl;
        cout<<"----------4. show booking person list            -----------"<<endl;
		cout<<"----------5. exit                                -----------"<<endl;
		cout<<"enter your choice: ";
		cin>>mainChoice;
		switch (mainChoice)
		{
			case 1:
			{
                Person person;
                system("CLS");
                fflush(stdin);
                cout<<"full name: ";
                getline(cin, fullName);
                person.setFullName(fullName);
                cout<<"ID: ";
                cin>>ID;
                person.setID(ID);
                cout<<"age: ";
                cin>>age;
                person.setAge(age);
                
                system("CLS");
                cout<<"type of room which want to choose: "<<endl;
                Booking booking;
                booking.setPerson(person);
            
                cout<<"A: 500$/day"<<endl;
				cout<<"B: 300$/day"<<endl;
                cout<<"C: 100$/day"<<endl;
                cin>>roomChoice;

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

                cout<<"number of rental days: "<<endl;
                cin>>numRentalDays;
                booking.setNumRentalDays(numRentalDays);

                management.add(booking);
				break;
			}
			case 2:
			{
				system("CLS");
                cout<<"enter ID which want to remove: "<<endl;
                cin>>ID;
                management.removeBooking(ID);
				cout<<"press 0 to back to menu...";
				cin>>inChoice;
				break;
			}
			case 3:
			{
                system("CLS");
                cout<<"enter ID of booking person:"<<endl;
                cin>>ID;
                cout<<"bill of booking person: "<<endl;
                system("CLS");
				management.bill(ID);
                cout<<"press 0 to back to menu...";
				cin>>inChoice;
				break;
			}
            case 4:
			{
                system("CLS");
				management.allShow();
                cout<<"press 0 to back to menu...";
				cin>>inChoice;
				break;
			}
		}
		if(mainChoice == 5)
		{
			break;
		}	
	}
}

int main()
{
    menu();
}