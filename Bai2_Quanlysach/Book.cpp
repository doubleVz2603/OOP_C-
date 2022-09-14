#include "Book.h"

Book::Book(string authorName, int pageAmount, string code, string publisherName, int releaseAmount)
    : Document(code, publisherName, releaseAmount)
{
    this->authorName = authorName;
    this->pageAmount = pageAmount;
}
void Book::show()
{
    cout << "author's name: " << authorName << endl;
    cout << "amount of pages: " << pageAmount << endl;
    cout << "code: " << getCode() << endl;
    cout << "publisher's name: " << getPublisherName() << endl;
    cout << "release amount: " << getReleaseAmount() << endl;
}
