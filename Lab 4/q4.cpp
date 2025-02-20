#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string author;
    string title;
    float price;
    string publisher;
    int stock;
public:
    Book(string a,string t,float p,string pub,int s) 
        :author(a),title(t),price(p),publisher(pub),stock(s) {}

    void displayDetails(){
        cout<<"Title: "<<title<<"\nAuthor: "<<author<<"\nPrice: $"<<price<<"\nPublisher: "<<publisher 
             <<"\nStock: "<<stock<<endl;
    }
    bool isAvailable(int requestedCopies){
        return stock>=requestedCopies;
    }
    void updateStock(int soldCopies){
        stock-=soldCopies;
    }
    string getTitle() 
	{ return title; }
    string getAuthor() 
	{ return author; }
    float getPrice()
    { return price; }
};

int main(int argc, char* argv[]) {
    Book book1("J.K. Rowling", "Harry Potter", 29.99, "Bloomsbury", 10);

    string searchTitle=argv[1];
    string searchAuthor=argv[2];
    int requestedCopies=stoi(argv[3]);

    if(book1.getTitle()==searchTitle && book1.getAuthor()==searchAuthor) {
        book1.displayDetails();
        if (book1.isAvailable(requestedCopies)){
            cout<<"Total cost: $"<<(book1.getPrice()*requestedCopies)<<endl;
            book1.updateStock(requestedCopies);
        }else{
            cout<<"Required copies not in stock."<<endl;
        }
    } else {
        cout<<"Book not available."<<endl;
    }

    return 0;
}

