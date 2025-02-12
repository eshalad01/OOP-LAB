#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string bookName;
    string isbnNumber;
    string authorName;
    string publisher;

public:
    
    Book() {}
    Book(string bookName,string isbnNumber,string authorName,string publisher);
    string getBookName();
    string getIsbnNumber();
    string getAuthorName();
    string getPublisher();
	string getBookInfo();
};

#endif

