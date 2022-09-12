#include "Intern.h"


void phoneException(string phone)
{
    if (phone.length() != 10)
    {
        throw "phone number isn't length enough...";
    }
    else
    {
        if ((int(phone[0]) - 48) != 0)
        {
            throw "error format input...";
        }
        for (int i = 1; i < phone.length(); i++)
        {
            if ((int(phone[i]) - 48) < 0 || (int(phone[i]) - 48) > 9)
            {
                throw "error format input...";
            }
        }
    }
}
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
    cout << "he/she has " << this->getListCertificate().size() << " certificate: " << endl;
    for (int i = 0; i < this->getListCertificate().size(); i++)
    {
        cout << "certificate " << i + 1 << endl;
        cout << "certificate's ID: " << this->getListCertificate()[i].getCertificatedID() << endl;
        cout << "certificate's name: " << this->getListCertificate()[i].getCertificatedName() << endl;
        cout << "certificate's rank: " << this->getListCertificate()[i].getCertificatedRank() << endl;
        cout << "certificate's date: " << this->getListCertificate()[i].getCertificatedDate() << endl;
    }
}

void Intern::input()
{
    int certificatedID;
    string certificatedName, certificatedRank, certificatedDate;
    int ID, number_certificate;
    string fullName, email, phone, birthDay;
    cout << "ID: ";
    cin >> ID;
    fflush(stdin);
    cout << "full name: ";
    getline(cin, fullName);
    cout << "email: ";
    cin >> email;
again:
    try
    {
        cout << "phone: ";
        cin >> phone;
        phoneException(phone);
    }
    catch (const char *error)
    {
        cout << error <<endl;
        goto again;
    }

    cout << "birth day: ";
    cin >> birthDay;
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
    cout << "number certificate: " << endl;
    cin >> number_certificate;
    for (int i = 0; i < number_certificate; i++)
    {
        cout << endl
             << "certificate " << i + 1 << endl;
        cout << "certificate's ID: ";
        cin >> certificatedID;
        cout << "certificate's name: ";
        cin >> certificatedName;
        cout << "certificate's rank: ";
        cin >> certificatedRank;
        cout << "certificate's date: ";
        cin >> certificatedDate;
        Certificate certificate(certificatedID, certificatedName, certificatedRank, certificatedDate);
        this->setListCertificate(certificate);
    }
}