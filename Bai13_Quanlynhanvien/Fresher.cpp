
#include "Fresher.h"

Fresher ::Fresher() {}
Fresher ::Fresher(int graduation_date, string graduation_rank, string graduation_education, int ID, string fullName, string email, string phone, Date birthDay, EmployeeType employee_type)
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
    cout << "ID: " << this->getID() << endl;
    cout << "full name: " << this->getFullName() << endl;
    cout << "email: " << this->getEmail() << endl;
    cout << "phone: " << this->getPhone() << endl;
    cout << "birth day: " << this->getBirthDay().getDay() << "/" << this->getBirthDay().getMonth() << "/" << this->getBirthDay().getYear() << endl;
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

void Fresher::input()
{
    int certificatedID;
    string certificatedName, certificatedRank, certificatedDate;
    int ID, number_certificate;
    string fullName, email, phone, day, month, year; 
    cout << "ID: ";
    cin >> ID;

emailAgain:
    try
    {
        cout << "email: ";
        cin >> email;
        emailException(email);
    }
    catch (const char *error)
    {
        cout << error << endl;
        goto emailAgain;
    }

nameAgain:
    try
    {
        fflush(stdin);
        cout << "full name: ";
        getline(cin, fullName);
        fullNameException(fullName);
    }
    catch (const char *error)
    {
        cout << error << endl;
        goto nameAgain;
    }

phoneAgain:
    try
    {
        cout << "phone: ";
        cin >> phone;
        phoneException(phone);
    }
    catch (const char *error)
    {
        cout << error << endl;
        goto phoneAgain;
    }
birthDayAgain:
    try
    {
        cout << "birth day: " << endl;
        cout << "day: ";
        cin >> day;
        cout << "month: ";
        cin >> month;
        cout << "year: ";
        cin >> year;
        dateException(day, month, year);
    }
    catch (const char *error)
    {
        cout << error << endl;
        goto birthDayAgain;
    }
    Date birthDay(day, month, year);
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
