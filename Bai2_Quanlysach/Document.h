#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <iostream>
using namespace std;
class Document
{
private:
    string code, publisherName;
    int releaseAmount;

public:
    Document(string, string, int);

    string getCode();

    string getPublisherName();

    int getReleaseAmount();

    virtual void show() = 0;
};
#endif