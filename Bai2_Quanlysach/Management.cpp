#include "Management.h"

void Management::add(unique_ptr<Document> document, string category)
{
    pair<unique_ptr<Document>, string> pair = make_pair(move(document), category);
    listDocument.push_back(move(pair));
}

void Management::removeDocument(string code)
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
void Management::filterCategory(string category)
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

void Management::allShow()
{
    system("CLS");
    for (int i = 0; i < listDocument.size(); i++)
    {
        cout << endl
             << "Document " << i + 1 << ": " << endl;
        listDocument[i].first->show();
    }
}
