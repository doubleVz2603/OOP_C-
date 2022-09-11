#include "Fresher.h"

Fresher ::Fresher() {}
Fresher ::Fresher(int graduation_date, string graduation_rank, string graduation_education, int ID, string fullName, string email, string phone, string birthDay, EmployeeType employee_type)
    : Employee(ID, fullName, email, phone, birthDay, employee_type)
{
    this->graduation_date = graduation_date;
    this->graduation_rank = graduation_rank;
    this->graduation_education = graduation_education;
}

void Fresher ::showInfo()
{
    cout << "graduation date: " << graduation_date << endl;
    cout << "graduation rank: " << graduation_rank << endl;
    cout << "graduation education: " << graduation_education << endl;
    cout << "ID: " << Employee::getID() << endl;
    cout << "full name: " << Employee ::getFullName() << endl;
    cout << "email: " << Employee ::getEmail() << endl;
    cout << "phone: " << Employee::getPhone() << endl;
    cout << "birth day: " << Employee ::getBirthDay() << endl;
}

void Fresher::update()
{
    string fullName, email, phone, birthDay;
    system("CLS");
    fflush(stdin);
    cout << "full name: ";
    getline(cin, fullName);
    cout << "email: ";
    cin >> email;
    cout << "phone: ";
    cin >> phone;
    cout << "birth day: ";
    cin >> birthDay;
    int ID;
    cout << "ID: ";
    cin >> ID;
    cout << "graduation date: ";
    cin >> graduation_date;
    cout << "graduation rank: ";
    cin >> graduation_rank;
    cout << "graduation education: ";
    cin >> graduation_education;
    this->graduation_date = graduation_date;
    this->graduation_rank = graduation_rank;
    this->graduation_education = graduation_education;
    this->setFullName(fullName);
    this->setBirthDay(birthDay);
    this->setEmail(email);
    this->setPhone(phone);
    this->setID(ID);
}
