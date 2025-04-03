#include<iostream>
#include<string>
#include<vector>
using namespace std;

class MediaItem{
protected:
    string name,pubDate,identifier,publisherName;
    bool isCheckedOutStatus;
public:
    MediaItem(string n,string pd,string id,string pub):name(n),pubDate(pd),identifier(id),publisherName(pub),isCheckedOutStatus(false){}
    virtual void showDetails()const{
        cout<<"Name: "<<name<<endl;
        cout<<"Published On: "<<pubDate<<endl;
        cout<<"ID: "<<identifier<<endl;
        cout<<"Publisher: "<<publisherName<<endl;
        cout<<"Availability: "<<(isCheckedOutStatus?"Checked Out":"Available")<<endl;
    }
    void checkOutItem(){
        if(isCheckedOutStatus){
            cout<<name<<" is already checked out."<<endl;
        }else{
            isCheckedOutStatus=true;
            cout<<name<<" has been checked out successfully."<<endl;
        }
    }
    void returnItem(){
        if(!isCheckedOutStatus){
            cout<<name<<" was not checked out."<<endl;
        }else{
            isCheckedOutStatus=false;
            cout<<name<<" has been returned successfully."<<endl;
        }
    }
    string getName()const{return name;}
};

class Book:public MediaItem{
private:
    string authorName,isbnCode;
    int totalPages;
public:
    Book(string n,string pd ,string id, string pub,string author,string isbn,int pages):MediaItem(n,pd,id,pub) ,authorName(author),isbnCode(isbn),totalPages(pages){}
    void showDetails()const override{
        cout<<"=== Book Information ==="<<endl;
        MediaItem::showDetails();
        cout<<"Author: "<<authorName<<endl;
        cout<<"ISBN: "<<isbnCode<<endl;
        cout<<"Total Pages: "<<totalPages<<endl;
        cout<<"------------------------"<<endl;
    }
};

int main(){
    MediaItem* book1=new Book ("The Great Gatsby","1925","B001","Scribner","F. Scott Fitzgerald","978-0743273565",180);
    MediaItem* book2=new Book ("To Kill a Mockingbird","1960","B002","J. B. Lippincott & Co.","Harper Lee","978-0061120084",281);
    book1->showDetails();
    cout<<endl;
    book2->showDetails();
    cout<<"\nTesting check-out and return:"<<endl;
    book1->checkOutItem();
    book1->showDetails();
    book1->returnItem();
    book1->showDetails();
    delete book1;
    delete book2;
    return 0;
}

