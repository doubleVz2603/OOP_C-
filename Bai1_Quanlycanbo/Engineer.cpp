#include "Engineer.h"

Engineer::Engineer(string specialized, string fullName, string address, string gender, int age)
    : Officer(fullName, address, gender, age)
{
    this->specialized = specialized;
}
void Engineer:: show()
{
    cout << "full name: " << this->getFullName() << endl;
    cout << "age: " << this->getAge() << endl;
    cout << "address: " << this->getAddress() << endl;
    cout << "gender: " << this->getGender() << endl;
    cout << "specialized: " << specialized << endl;
}
