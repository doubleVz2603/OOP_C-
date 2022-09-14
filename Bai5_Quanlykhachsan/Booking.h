#ifndef BOOKING_H
#define BOOKING_H
#include "Person.h"
enum Room
{
    A = 500,
    B = 300,
    C = 100
};

class Booking
{
private:
    int numRentalDays;
    Room category;
    Person person;

public:
    void setPerson(Person);

    void setNumRentalDays(int);

    void setCategory(Room category);

    Person getPerson();

    Room getCategory();

    int getNumRentalDays();
};

#endif