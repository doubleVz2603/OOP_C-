#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <vector>
#include "Booking.h"
using namespace std;
class Management
{
private:
    vector<Booking> listBooking;

public:
    void add(Booking);

    void removeBooking(int);

    void allShow();

    void bill(int);
};

#endif