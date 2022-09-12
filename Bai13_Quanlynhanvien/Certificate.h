#ifndef CERTIFICATE_H
#define CERTIFICATE_H
#include <iostream>
using namespace std;



class Certificate
{
private:
    int certificatedID; 
    string certificatedName, certificatedRank, certificatedDate;

public:
    Certificate();
    Certificate(int, string, string, string);

    
    string getCertificatedName();
    string getCertificatedRank();
    string getCertificatedDate();
    int getCertificatedID();
    
    void setCertificatedName(string);
    void setCertificatedRank(string);
    void setCertificatedDate(string);
    void setCertificatedID(int);
};



#endif