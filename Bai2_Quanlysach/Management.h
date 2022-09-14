#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include "Document.h"
#include <vector>
#include <memory>
#include <iostream>
using namespace std;

class Management
{
private:
    vector<pair<unique_ptr<Document>, string>> listDocument;

public:
    void add(unique_ptr<Document> document, string category);

    void removeDocument(string code);

    void filterCategory(string category);

    void allShow();
};

#endif
