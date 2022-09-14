#include "Management.h"

void Management::add(Booking booking)
{
    listBooking.push_back(booking);
}
void Management::removeBooking(int ID)
{
    int count = 0;
    int i;
    vector<Booking>::iterator index = listBooking.begin();
    for (index, i = 0; index != listBooking.end(), i < listBooking.size(); ++index, ++i)
    {
        if (listBooking[i].getPerson().getID() == ID)
        {
            listBooking.erase(index);
            ++count;
            break;
        }
    }
    if (count == 0)
    {
        cout << "no found" << endl;
    }
}

void Management::allShow()
{
    for (int i = 0; i < listBooking.size(); ++i)
    {
        cout << "ID: " << listBooking[i].getPerson().getID() << endl;
        cout << "full name: " << listBooking[i].getPerson().getFullName() << endl;
        cout << "age: " << listBooking[i].getPerson().getAge() << endl;
        cout << "kind of room: " << listBooking[i].getCategory() << endl;
        cout << "number of rental days: " << listBooking[i].getNumRentalDays() << endl;
    }
}

void Management::bill(int ID)
{
    int sum = 0;
    int count = 0;
    for (int i = 0; i < listBooking.size(); ++i)
    {

        if (listBooking[i].getPerson().getID() == ID)
        {
            sum = listBooking[i].getNumRentalDays() * listBooking[i].getCategory();
            ++count;
            break;
        }
    }

    if (count == 0)
    {
        cout << "no found" << endl;
    }
    else
    {
        cout << "bill of booking person: " << sum;
    }
}
