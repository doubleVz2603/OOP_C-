#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

class Document
{
private:
    string code, publisherName;
    int releaseAmount;

public:
    Document(string code, string publisherName, int releaseAmount)
    {
        this->code = code;
        this->publisherName = publisherName;
        this->releaseAmount = releaseAmount;
    }
    string getCode()
    {
        return code;
    }
    string getPublisherName()
    {
        return publisherName;
    }
    int getReleaseAmount()
    {
        return releaseAmount;
    }

    virtual void show() = 0;
};

class Book : public Document
{
private:
    string authorName;
    int pageAmount;

public:
    Book(string authorName, int pageAmount, string code, string publisherName, int releaseAmount)
        : Document(code, publisherName, releaseAmount)
    {
        this->authorName = authorName;
        this->pageAmount = pageAmount;
    }
    void show()
    {
        cout << "author's name: " << authorName << endl;
        cout << "amount of pages: " << pageAmount << endl;
        cout << "code: " << getCode() << endl;
        cout << "publisher's name: " << getPublisherName() << endl;
        cout << "release amount: " << getReleaseAmount() << endl;
    }
};

class Magazine : public Document
{
private:
    int releaseNumber, releaseMonth;

public:
    Magazine(int releaseNumber, int releaseMonth, string code, string publisherName, int releaseAmount)
        : Document(code, publisherName, releaseAmount)
    {
        this->releaseNumber = releaseNumber;
        this->releaseMonth = releaseMonth;
    }

    void show()
    {
        cout << "release number: " << releaseNumber << endl;
        cout << "release month: " << releaseMonth << endl;
        cout << "code: " << getCode() << endl;
        cout << "publisher's name: " << getPublisherName() << endl;
        cout << "release amount: " << getReleaseAmount() << endl;
    }
};

class Newspaper : public Document
{
private:
    int releaseDay;

public:
    Newspaper(int releaseDay, string code, string publisherName, int releaseAmount)
        : Document(code, publisherName, releaseAmount)
    {
        this->releaseDay = releaseDay;
    }
    void show()
    {
        cout << "release day: " << releaseDay << endl;
        cout << "code: " << getCode() << endl;
        cout << "publisher's name: " << getPublisherName() << endl;
        cout << "release amount: " << getReleaseAmount() << endl;
    }
};

class Management
{
private:
    vector<pair<unique_ptr<Document>, string>> listDocument;

public:
    void add(unique_ptr<Document> document, string category)
    {
        pair<unique_ptr<Document>, string> pair = make_pair(move(document), category);
        listDocument.push_back(move(pair));
    }

    void removeDocument(string code)
    {
        int i;
        int count = 0;
        vector<pair<unique_ptr<Document>, string>>::iterator index = listDocument.begin();
        for (index = listDocument.begin(), i = 0; index != listDocument.end(), i < listDocument.size(); ++index, ++i)
        {

            if (listDocument[i].first->getCode().compare(code) == 0)
            {
                listDocument.erase(index);
                ++count;
                break;
            }
        }
        if (count == 0)
        {
            cout << "no found" << endl;
        }
    }
    void filterCategory(string category)
    {
        int count = 0;
        cout << endl
             << "category " << category << endl;
        for (int i = 0; i < listDocument.size(); i++)
        {

            if (listDocument[i].second.compare(category) == 0)
            {
                cout << endl;
                listDocument[i].first->show();
                ++count;
            }
        }
        if (count == 0)
        {
            cout << "not found" << endl;
        }
    }

    void allShow()
    {
        system("CLS");
        for (int i = 0; i < listDocument.size(); i++)
        {
            cout << endl
                 << "Document " << i + 1 << ": " << endl;
            listDocument[i].first->show();
        }
    }
};

void menu()
{
    string mainChoice, inChoice;
    string code, publisherName, authorName, category, releaseAmount, pageAmount, releaseMonth, releaseDay;
    int releaseNumber;

    Management management;
    while (1)
    {
        system("CLS");
        cout << "----------------------------Menu----------------------------" << endl;
        cout << "----------1. add information of document         -----------" << endl;
        cout << "----------2. remove document with code           -----------" << endl;
        cout << "----------3. show document list                  -----------" << endl;
        cout << "----------4. search document with category       -----------" << endl;
        cout << "----------5. exit                                -----------" << endl;
        cout << "enter your choice: ";
        cin >> mainChoice;
        if (mainChoice.length() > 1 || (int(mainChoice[0] - 48) < 0 || int(mainChoice[0] - 48) > 5))
        {
            cout << "error format input..." << endl;
            system("pause");
            break;
        }
        else
        {
            switch (int(mainChoice[0] - 48))
            {
            case 1:
            {
                system("CLS");
                cout << "1. book" << endl;
                cout << "2. magazine" << endl;
                cout << "3. newspaper" << endl;
                cout << "4. Back" << endl;
                try
                {
                    cin >> inChoice;
                    if (inChoice.length() > 1 || (int(inChoice[0] - 48) < 0 || int(inChoice[0] - 48) > 4))
                    {
                        throw "error format input...";
                    }
                    else
                    {
                        if (int(inChoice[0] - 48) == 4)
                        {
                            break;
                        }
                        system("CLS");
                        fflush(stdin);
                        cout << "publish name: ";
                        getline(cin, publisherName);
                        cout << "code: ";
                        cin >> code;

                        try
                        {
                            cout << "release amount: ";
                            cin >> releaseAmount;

                            for (int i = 0; i < releaseAmount.length(); i++)
                            {
                                if (int(releaseAmount[i]) > 57 || int(releaseAmount[i]) < 48)
                                {
                                    throw 101;
                                }
                            }
                        }
                        catch (int)
                        {
                            cout << "error format input..." << endl;
                            system("pause");
                            break;
                        }

                        if (int(inChoice[0] - 48) == 1)
                        {
                            try
                            {

                                fflush(stdin);
                                cout << "author's name: ";
                                getline(cin, authorName);
                                cout << "amount of pages: ";
                                cin >> pageAmount;
                                for (int i = 0; i < pageAmount.length(); i++)
                                {
                                    if (int(pageAmount[i]) > 57 || int(pageAmount[i]) < 48)
                                    {
                                        throw 101;
                                    }
                                }
                            }

                            catch (int)
                            {
                                cout << "error format input..." << endl;
                                system("pause");
                                break;
                            }

                            management.add(unique_ptr<Document>(new Book(authorName, stoi(pageAmount), code, publisherName, stoi(releaseAmount))), "book");
                            system("CLS");
                        }
                        else if (int(inChoice[0] - 48) == 2)
                        {
                            try
                            {
                                cout << "release number: ";
                                cin >> releaseNumber;
                                cout << "release month: ";
                                cin >> releaseMonth;
                                for (int i = 0; i < releaseMonth.length(); i++)
                                {
                                    if (int(releaseMonth[i]) > 57 || int(releaseMonth[i]) < 48)
                                    {
                                        throw 101;
                                    }
                                }

                                if (stoi(releaseMonth) < 1 || stoi(releaseMonth) > 12)
                                {
                                    throw "no month in year..";
                                }
                            }
                            catch (const char *errorMonth)
                            {
                                cout << errorMonth << endl;
                                system("pause");
                                break;
                            }
                            catch (int)
                            {
                                cout << "error format input..." << endl;
                                system("pause");
                                break;
                            }
                            management.add(unique_ptr<Document>(new Magazine(releaseNumber, stoi(releaseMonth), code, publisherName, stoi(releaseAmount))), "magazine");
                            system("CLS");
                        }
                        else if (int(inChoice[0] - 48) == 3)
                        {
                            try
                            {
                                cout << "release day: ";
                                cin >> releaseDay;
                                for (int i = 0; i < releaseDay.length(); i++)
                                {
                                    if (int(releaseDay[i]) > 57 || int(releaseDay[i]) < 48)
                                    {
                                        throw 101;
                                    }
                                }

                                if (stoi(releaseDay) < 1 || stoi(releaseDay) > 31)
                                {
                                    throw "no day in month..";
                                }
                            }
                            catch (const char *errorDay)
                            {
                                cout << errorDay << endl;
                                system("pause");
                                break;
                            }
                            catch (int)
                            {
                                cout << "error format input..." << endl;
                                system("pause");
                                break;
                            }
                            management.add(unique_ptr<Document>(new Newspaper(stoi(releaseDay), code, publisherName, stoi(releaseAmount))), "newspaper");
                            system("CLS");
                        }
                    }
                }
                catch (const char *msg)
                {
                    cout << msg << endl;
                    cout << "back to menu press 0" << endl;
                    cin >> inChoice;
                }

                break;
            }
            case 2:
            {
                system("CLS");
                cout << "enter code of document to remove: ";
                fflush(stdin);
                getline(cin, code);
                management.removeDocument(code);
                cout << "press 0 to back to menu...";
                cin >> inChoice;
                break;
            }
            case 3:
            {
                system("CLS");
                management.allShow();
                cout << "press 0 to back to menu...";
                cin >> inChoice;
                break;
            }
            case 4:
            {
                system("CLS");
                cout << "enter category: ";
                cin >> category;
                management.filterCategory(category);
                cout << "press 0 to back to menu...";
                cin >> inChoice;
                break;
            }
            }

            if (int(mainChoice[0] - 48) == 5)
            {
                break;
            }
        }
    }
}
int main()
{
    menu();
}