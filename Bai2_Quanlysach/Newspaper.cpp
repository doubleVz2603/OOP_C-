#include "Newspaper.h"

Newspaper::Newspaper(int releaseDay, string code, string publisherName, int releaseAmount)
    : Document(code, publisherName, releaseAmount)
{
    this->releaseDay = releaseDay;
}
void Newspaper::show()
{
    cout << "release day: " << releaseDay << endl;
    cout << "code: " << getCode() << endl;
    cout << "publisher's name: " << getPublisherName() << endl;
    cout << "release amount: " << getReleaseAmount() << endl;
}
