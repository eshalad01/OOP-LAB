#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Entity {
    int id;
    string name;
};

bool compare(const Entity &one, const Entity &two) {
    if (one.id==two.id) {
        return one.name<two.name;
    } else {
        return one.id<two.id;
    }
}

int main(int argc, char *argv[]) {
    if (argc<2) {
        cout<<"Please provide the number of structures to create."<<endl;
        return 1;
    }

    int N=stoi(argv[1]);
    Entity entities[100];

    for (int i=0;i<N;i++) {
        cout<<"Enter id and name for entity "<<i+1<<": ";
        cin>>entities[i].id>>entities[i].name;
    }

    cout<<"\nEntities before sorting:\n";
    for(int i=0;i<N;i++) {
        cout<<"ID: "<< entities[i].id<<", Name: "<<entities[i].name<<endl;
    }
    sort(entities,entities+N,compare);

    cout << "\nEntities after sorting:\n";
    for(int i=0;i<N;i++) {
        cout<<"ID: "<<entities[i].id<<", Name: "<<entities[i].name<<endl;
    }

    return 0;
}
