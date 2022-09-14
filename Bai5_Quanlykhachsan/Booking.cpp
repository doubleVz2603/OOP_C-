#include "Booking.h"

void Booking::setPerson(Person person)
{
    this->person = person;
}
void Booking::setNumRentalDays(int numRentalDays)
{
    this->numRentalDays = numRentalDays;
}
void Booking::setCategory(Room category)
{
    this->category = category;
}
Person Booking::getPerson()
{
    return person;
}
Room Booking::getCategory()
{
    return category;
}
int Booking::getNumRentalDays()
{
    return numRentalDays;
}
