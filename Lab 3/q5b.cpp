#include "q5a.h"

using namespace std;


Book::Book(string bookName,string isbnNumber,string authorName,string publisher) {
    this->bookName=bookName;
    this->isbnNumber=isbnNumber;
    this->authorName=authorName;
    this->publisher=publisher;
}

string Book::getBookName(){
    return bookName;
}

string Book::getIsbnNumber(){
    return isbnNumber;
}

string Book::getAuthorName(){
    return authorName;
}

string Book::getPublisher(){
    return publisher;
}
string Book::getBookInfo()  {
    return "Book Name: "+bookName+"\n"+"ISBN: " +isbnNumber+"\n"+"Author: "+authorName+"\n"+"Publisher: "+publisher;
}

int main(int argc, char* argv[]) {
    if (argc!=21) { 
        cout<<"Invalid Inputs";
        return 1; 
		   }

    Book books[5];

    books[0]=Book(argv[1],argv[2],argv[3],argv[4]);
    books[1]=Book(argv[5],argv[6], argv[7],argv[8]);
    books[2]=Book(argv[9],argv[10],argv[11],argv[12]);
    books[3]=Book(argv[13],argv[14],argv[15],argv[16]);
    books[4]=Book(argv[17],argv[18],argv[19],argv[20]);

    for(int i=0;i<5;i++) {
        cout<<"\nBook "<<(i+1)<<" Info:\n";
        cout<<books[i].getBookInfo()<<endl; 
    }

    return 0;
}

