#include "Staff.h"

Staff::Staff(string job, string fullName, string address, string gender, int age)
    : Officer(fullName, address, gender, age)
{
    this->job = job;
}
void Staff::show()
{
    cout << "full name: " << this->getFullName() << endl;
    cout << "age: " << this->getAge() << endl;
    cout << "address: " << this->getAddress() << endl;
    cout << "gender: " << this->getGender() << endl;
    cout << "job: " << job << endl;
}
