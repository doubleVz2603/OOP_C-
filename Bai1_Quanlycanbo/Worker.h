#ifndef WORKER_H
#define WORKER_H
#include <iostream>
#include "Officer.h"
class Worker : public Officer
{
private:
    int level;

public:
    Worker(int, string, string, string, int);
    void show();
};
#endif