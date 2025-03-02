#include<iostream>
#include<vector>
using namespace std;

class Book {
public:
    string title,isbn;
    Book(string t,string i):title(t),isbn(i){}
};

class Catalog {
public:
    vector<Book*> books;
    void addBook(Book* book) {
        books.push_back(book);
    }
    void findBook(string isbn) {
        for(Book* book:books) {
            if(book->isbn==isbn) {
                cout<<"Book found: "<<book->title<<endl;
                return;
            }
        }
        cout<<"Book not found."<<endl;
    }
};

class Library {
private:
    Catalog catalog; // Composition
public:
    void addBook(Book* book) {
        catalog.addBook(book);
    }
    void findBook(string isbn) {
        catalog.findBook(isbn);
    }
};

int main() {
    Library myLibrary;
    Book book1("C++ Basics","1234");
    Book book2("Data Structures","5678");
    
    myLibrary.addBook(&book1);
    myLibrary.addBook(&book2);
    
    myLibrary.findBook("1234");
    myLibrary.findBook("9999"); // Not in catalog
    
    return 0;
}