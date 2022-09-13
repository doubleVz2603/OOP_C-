#ifndef STAFF_H
#define STAFF_H
#include <iostream>
#include "Officer.h"

class Staff : public Officer
{
private:
    string job;

public:
    Staff(string, string, string, string, int);

    void show();
};
#endif