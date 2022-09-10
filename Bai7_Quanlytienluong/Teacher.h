
#ifndef TEACHER_H
#define TEACHER_H
#include "Person.h"
class Teacher : public Person
{
private:
    int fixSalary, bonus, fine;

public:
    Teacher ();
    Teacher(int, string, string, int, int, int, int);
    void setFixSalary(int fixSalry);
    void setBonus(int bonus);
    void setFine(int fine);
    int getFixSalary();
    int getBonus();
    int getFine();
    int getRealSalary();
    
};

#endif