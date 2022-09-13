#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <vector>
#include <memory>
#include <iostream>
#include "Officer.h"

class Management
{
private:
    vector<unique_ptr<Officer>> listOfficer;

public:
    void add(unique_ptr<Officer>);

    void searchFullName(string fullName);

    void allShow();
};
#endif