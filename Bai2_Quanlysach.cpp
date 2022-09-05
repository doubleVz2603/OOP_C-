#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Document{
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
            cout<<"author's name: " <<authorName<<endl;
            cout<<"amount of pages: " <<pageAmount<<endl;
            cout<<"code: " <<getCode()<<endl;
            cout<<"publisher's name: " <<getPublisherName()<<endl;
            cout<<"release amount: " <<getReleaseAmount()<<endl;
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
            cout<<"release number: " <<releaseNumber<<endl;
            cout<<"release month: " <<releaseMonth<<endl;
            cout<<"code: " <<getCode()<<endl;
            cout<<"publisher's name: " <<getPublisherName()<<endl;
            cout<<"release amount: " <<getReleaseAmount()<<endl;
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
            cout<<"release day: " <<releaseDay<<endl;
            cout<<"code: " <<getCode()<<endl;
            cout<<"publisher's name: " <<getPublisherName()<<endl;
            cout<<"release amount: " <<getReleaseAmount()<<endl;
        }

};  

class Management{
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
        vector<pair<unique_ptr<Document>, string>>::iterator index = listDocument.begin();
        for (index= listDocument.begin(), i = 0; index != listDocument.end(), i < listDocument.size(); ++index, ++i) {
        
            if(listDocument[i].first->getCode().compare(code) == 0)
            {
                listDocument.erase(index);
            }
        }
    }
    void filterCategory(string category)
    {
        cout<<endl<<"category "<<category<<endl;
        for (int i = 0; i < listDocument.size(); i++)
        {
            if(listDocument[i].second.compare(category) == 0)
            {
                
                listDocument[i].first->show();
            } 
        } 
    }

    void allShow()
    {
        system("CLS");   
        for (int i = 0; i < listDocument.size(); i++)
        {
            cout<<endl<<"Document "<<i + 1<<": "<<endl;
            listDocument[i].first->show();
        }  
    }
};

void menu()
{
    int mainChoice, inChoice;
    string code, publisherName, authorName, category;
    int releaseAmount, releaseDay, releaseNumber, releaseMonth, pageAmount;

    Management management;
	while(1)
	{
		system("CLS");
		cout<<"----------------------------Menu----------------------------"<<endl;
		cout<<"----------1. add information of document         -----------"<<endl;
		cout<<"----------2. remove document with code           -----------"<<endl;
		cout<<"----------3. show document list                  -----------"<<endl;
        cout<<"----------4. search document with category       -----------"<<endl;
		cout<<"----------5. exit                                -----------"<<endl;
		cout<<"enter your choice: ";
		cin>>mainChoice;
		switch (mainChoice)
		{
			case 1:
			{
				system("CLS");
				cout<<"1. book"<<endl;
				cout<<"2. magazine"<<endl;
                cout<<"3. newspaper"<<endl;
				cout<<"4. Back" <<endl;
				cin>>inChoice;
                if (inChoice == 4)
				{
					break;
				}	
                
                system("CLS");
                fflush(stdin);
                cout<<"publish name: ";
                getline(cin, publisherName);
                cout<<"code: ";
                cin>>code;
                cout<<"release amount: ";
                cin>>releaseAmount;

				if (inChoice == 1)
				{
                    fflush(stdin);
                    cout<<"author's name: ";
                    getline(cin, authorName);
                    cout<<"amount of pages: ";
                    cin>>pageAmount;
                    management.add(unique_ptr<Document> (new Book(authorName, pageAmount, code, publisherName, releaseAmount)), "book");
					system("CLS");
                    
				}
				else if (inChoice == 2)
				{
					cout<<"release number: ";
                    cin>>releaseNumber;
                    cout<<"release month: ";
                    cin>>releaseMonth;
                    management.add(unique_ptr<Document> (new Magazine(releaseNumber, releaseMonth, code, publisherName, releaseAmount)), "magazine");
					system("CLS");
				}
                else if (inChoice == 3)
				{
					cout<<"release day: ";
                    cin>> releaseDay;
                    management.add(unique_ptr<Document> (new Newspaper(releaseDay, code, publisherName, releaseAmount)), "newspaper");
					system("CLS");
				}
				break;
			}
			case 2:
			{
				system("CLS");
				cout<<"enter code of document to remove: ";
                fflush(stdin);
                getline(cin, code);
                management.removeDocument(code);
				cout<<"press 0 to back to menu...";
				cin>>inChoice;
				break;
			}
			case 3:
			{
                system("CLS");
				management.allShow();
                cout<<"press 0 to back to menu...";
				cin>>inChoice;
				break;
			}
            case 4:
			{
                system("CLS");
                cout<<"enter category: ";
                cin>>category;
				management.filterCategory(category);
                cout<<"press 0 to back to menu...";
				cin>>inChoice;
				break;
			}
		}
        
		if(mainChoice == 5)
		{
			break;
		}	
	}
}
int main()
{
    menu();
}