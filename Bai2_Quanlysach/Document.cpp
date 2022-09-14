#include "Document.h"

Document::Document(string code, string publisherName, int releaseAmount)
{
    this->code = code;
    this->publisherName = publisherName;
    this->releaseAmount = releaseAmount;
}
string Document::getCode()
{
    return code;
}
string Document::getPublisherName()
{
    return publisherName;
}
int Document::getReleaseAmount()
{
    return releaseAmount;
}

void Document::show() {}
