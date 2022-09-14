#include "Family.h"

void Family::setMemberAmount(int memberAmount)
{
    this->memberAmount = memberAmount;
}
void Family::setHouseNumber(int houseNumber)
{
    this->houseNumber = houseNumber;
}
int Family::getMemberAmount()
{
    return memberAmount;
}
int Family::getHouseNumber()
{
    return houseNumber;
}

void Family::setListPerson(Person person)
{
    this->listPerson.push_back(person);
}

vector<Person> Family::getListPerson()
{
    return listPerson;
}
