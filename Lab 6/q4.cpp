#include <iostream>
#include <string>

using namespace std;

class Books {
protected:
    string genre,title,author;

public:
    Books(const string& g,const string& t,const string& a):genre(g),title(t),author(a) {}
    virtual void display() const=0;
    virtual ~Books() {}
};

class Novel:public Books {
public:
    Novel(const string& t,const string& a):Books("Novel",t,a) {}

    void display() const {
        cout<<"--------------------\n";
        cout<<"Genre:"<<genre<<"\nTitle:"<<title<<"\nAuthor:"<<author<<"\n";
        cout<<"--------------------\n";
    }
};

class Mystery:public Books {
public:
    Mystery(const string& t,const string& a):Books("Mystery",t,a) {}

    void display() const {
        cout<<"--------------------\n";
        cout<<"Genre:"<<genre<<"\nTitle:"<<title<<"\nAuthor:"<<author<<"\n";
        cout<<"--------------------\n";
    }
};

int main() {
    Novel book1("Pride and Prejudice","Jane Austen");
    Mystery book2("The Hound of the Baskervilles","Arthur Conan Doyle");

    book1.display();
    book2.display();

    return 0;
}

