#include "Teacher.h"

Teacher ::Teacher() {}
Teacher ::Teacher(int age, string fullName, string address, int ID, int fixSalary, int bonus, int fine)
    : Person(age, fullName, address, ID)
{
    this->fixSalary = fixSalary;
    this->bonus = bonus;
    this->fine = fine;
}
void Teacher ::setFixSalary(int fixSalry)
{
    this->fixSalary = fixSalary;
}
void Teacher ::setBonus(int bonus)
{
    this->bonus = bonus;
}

void Teacher :: setFine(int fine)
{
    this->fine = fine;
}

int Teacher::getFixSalary()
{
    return fixSalary;
}
int Teacher::getBonus()
{
    return bonus;
}
int Teacher ::getFine()
{
    return fine;
}

int Teacher ::getRealSalary()
{
    return fixSalary + bonus - fine;
}