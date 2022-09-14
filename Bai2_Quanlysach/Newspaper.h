#ifndef NEWSPAPER_H
#define NEWSPAPER_H
#include "Document.h"
#include <iostream>
using namespace std;

class Newspaper : public Document
{
private:
    int releaseDay;

public:
    Newspaper(int, string, string, int);

    void show();
};

#endif