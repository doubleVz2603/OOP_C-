#include "Fresher.h"


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
        cout << error << endl;
        goto again;
    }
    cout << "birth day: ";
    cin >> birthDay;
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
