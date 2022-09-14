#include "Management.h"

void Management::add(unique_ptr<Candidate> candidate, string grade)
{
    pair<unique_ptr<Candidate>, string> pair = make_pair(move(candidate), grade);
    listCandidate.push_back(move(pair));
}

void Management::searchByID(int ID)
{
    int count = 0;
    for (int i = 0; i < listCandidate.size(); i++)
    {

        if (listCandidate[i].first->getID() == ID)
        {
            listCandidate[i].first->show();
            cout << listCandidate[i].second << endl;
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
    for (int i = 0; i < listCandidate.size(); i++)
    {
        cout << endl
             << "Candidate " << i + 1 << ": " << endl;
        listCandidate[i].first->show();
        cout << listCandidate[i].second << endl;
    }
}
