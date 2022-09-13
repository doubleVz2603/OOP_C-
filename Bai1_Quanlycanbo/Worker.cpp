#include "Worker.h"

Worker::Worker(int level, string fullName, string address, string gender, int age)
    : Officer(fullName, address, gender, age)
{
    this->level = level;
}

void Worker::show()
{
    cout << "full name: " << this->getFullName() << endl;
    cout << "age: " << this->getAge() << endl;
    cout << "address: " << this->getAddress() << endl;
    cout << "gender: " << this->getGender() << endl;
    cout << "level: " << level << endl;
}
