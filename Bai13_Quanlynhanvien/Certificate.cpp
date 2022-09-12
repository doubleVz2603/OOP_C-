#include "Certificate.h"
#include <iostream>
using namespace std;

Certificate::Certificate() {}
Certificate::Certificate(int certificatedID, string certificatedName, string certificatedRank, string certificatedDate)
{
    this->certificatedID = certificatedID;
    this->certificatedDate = certificatedDate;
    this->certificatedName = certificatedName;
    this->certificatedRank = certificatedRank;
}

string Certificate::getCertificatedDate()
{
    return certificatedDate;
}

string Certificate::getCertificatedName()
{
    return certificatedName;
}

string Certificate::getCertificatedRank()
{
    return certificatedRank;
}

int Certificate::getCertificatedID()
{
    return certificatedID;
}

void Certificate::setCertificatedID(int certificatedID)
{
    this->certificatedID = certificatedID;
}
void Certificate::setCertificatedDate(string certificatedDate)
{
    this->certificatedDate = certificatedDate;
}
void Certificate::setCertificatedName(string certificatedName)
{
    this->certificatedName = certificatedName;
}

void Certificate::setCertificatedRank(string certificatedRank)
{
    this->certificatedDate = certificatedDate;
}