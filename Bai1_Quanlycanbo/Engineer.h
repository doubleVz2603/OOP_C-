#ifndef ENGINEER_H
#define ENGINEER_H
#include <iostream>
#include "Officer.h"
using namespace std;

class Engineer : public Officer
{
private:
    string specialized;

public:
    Engineer(string, string, string, string, int);

    void show();
};

#endif