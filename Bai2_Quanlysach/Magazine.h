#ifndef MAGAZINE_H
#define MAGAZINE_H
#include "Document.h"
#include <iostream>
using namespace std;
class Magazine : public Document
{
private:
    int releaseNumber, releaseMonth;

public:
    Magazine(int, int, string, string, int);

    void show();
};
#endif