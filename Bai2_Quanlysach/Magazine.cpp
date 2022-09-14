#include "Magazine.h"

Magazine::Magazine(int releaseNumber, int releaseMonth, string code, string publisherName, int releaseAmount)
    : Document(code, publisherName, releaseAmount)
{
    this->releaseNumber = releaseNumber;
    this->releaseMonth = releaseMonth;
}

void Magazine::show()
{
    cout << "release number: " << releaseNumber << endl;
    cout << "release month: " << releaseMonth << endl;
    cout << "code: " << getCode() << endl;
    cout << "publisher's name: " << getPublisherName() << endl;
    cout << "release amount: " << getReleaseAmount() << endl;
}
