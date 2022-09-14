#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "Management.h"
#include "Book.h"
#include "Newspaper.h"
#include "Magazine.h"
using namespace std;


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