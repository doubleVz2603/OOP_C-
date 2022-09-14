#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <vector>
#include <iostream>
#include <memory>
#include "Candidate.h"
using namespace std;
class Management
{
private:
    vector<pair<unique_ptr<Candidate>, string>> listCandidate;

public:
    void add(unique_ptr<Candidate>, string);

    void searchByID(int);

    void allShow();
};

#endif