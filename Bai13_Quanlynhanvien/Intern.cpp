#include "Intern.h"

Intern ::Intern() {}
Intern ::Intern(string majors, string semester, string university_name, int ID, string fullName, string email, string phone, string birthDay, EmployeeType employee_type)
    : Employee(ID, fullName, email, phone, birthDay, employee_type)
{
    this->majors = majors;
    this->semester = semester;
    this->university_name = university_name;
}

void Intern ::showInfo()
{
    cout << "majors: " << majors << endl;
    cout << "semester: " << semester << endl;
    cout << "university's name: " << university_name << endl;
    cout << "ID: " << Employee::getID() << endl;
    cout << "full name: " << Employee ::getFullName() << endl;
    cout << "email: " << Employee ::getEmail() << endl;
    cout << "phone: " << Employee::getPhone() << endl;
    cout << "birth day: " << Employee ::getBirthDay() << endl;
}

void Intern ::update()
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
    cout << "majors: ";
    cin >> majors;
    cout << "semester: ";
    cin >> semester;
    cout << "university's name: ";
    cin >> university_name;
    this->majors = majors;
    this->semester = semester;
    this->university_name = university_name;
    this->setFullName(fullName);
    this->setBirthDay(birthDay);
    this->setEmail(email);
    this->setPhone(phone);
    this->setID(ID);
}
