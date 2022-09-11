#include "Experience.h"

Experience ::Experience() {}
Experience ::Experience(int expInYear, string proSkill, int ID, string fullName, string email, string phone, string birthDay, EmployeeType employee_type)
    : Employee(ID, fullName, email, phone, birthDay, employee_type)
{
    this->expInYear = expInYear;
    this->proSkill = proSkill;
}

void Experience ::showInfo()
{
    cout << "expInYear: " << expInYear << endl;
    cout << "proSkill: " << proSkill << endl;
    cout << "ID: " << Employee::getID() << endl;
    cout << "full name: " << Employee ::getFullName() << endl;
    cout << "email: " << Employee ::getEmail() << endl;
    cout << "phone: " << Employee::getPhone() << endl;
    cout << "birth day: " << Employee ::getBirthDay() << endl;
}
void Experience::update()
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
    cout << "expInYear: ";
    cin >> expInYear;
    fflush(stdin);
    cout << "proSkill: ";
    getline(cin, proSkill);
    this->expInYear = expInYear;
    this->proSkill = proSkill;
    this->setFullName(fullName);
    this->setBirthDay(birthDay);
    this->setEmail(email);
    this->setPhone(phone);
    this->setID(ID);
}
