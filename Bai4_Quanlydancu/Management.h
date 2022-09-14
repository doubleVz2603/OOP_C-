#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <iostream>
#include "Family.h"
using namespace std;

class Management
{
private:
    vector<Family> listFamily;

public:
    void input(int);
    
    void output();
    
    
};

#endif