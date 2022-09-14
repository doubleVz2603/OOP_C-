#ifndef BOOK_H
#define BOOK_H
#include "Document.h"
#include <iostream>
using namespace std;
class Book : public Document
{
private:
    string authorName;
    int pageAmount;

public:
    Book(string, int, string, string, int);

    void show();
};
#endif