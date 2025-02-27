#include <iostream>
#include <string>

using namespace std;

class CoffeeShop {
private:
    const string name;
    string menu[5]={"Coffee","Tea","Sandwich","Muffin","Juice"};
    string orders[10];
    int orderCount=0;
    double prices[5]={450,350,200,180,200};

public:
    CoffeeShop(string shopName):name(shopName) {}

    void addOrder(string item){
        bool found=false;
        for (int i=0;i<5;i++) {
            if (menu[i]==item) {
                found=true;
                if(orderCount<10){
                    orders[orderCount++]=item;
                } else {
                    cout<<"Order limit reached!"<<endl;
                }
                break;
            }
        }
        if(!found){
            cout<<"This item is currently unavailable!"<<endl;
        }
    }

    string fulfillOrder() {
        if(orderCount>0){
            string item=orders[--orderCount];
            return "The "+item +" is ready!";
        } else {
            return "All orders have been fulfilled";
        }
    }

    void listOrders() {
    if (orderCount==0) {
        cout<<"No orders taken."<<endl;
    } else {
        cout<<"Orders: ";
        for(int i=0;i<orderCount;i++) {
            if(i<orderCount-1) {
                cout<<orders[i]<<", ";
            } else {
                cout<<orders[i];
            }
        }
        cout<<endl;
    }
}


    double dueAmount() {
        double total=0;
        for (int i=0;i<orderCount;i++) {
            for(int j=0;j<5;j++) {
                if(orders[i]==menu[j]){
                    total+=prices[j];
                }
            }
        }
        return total;
    }

    string cheapestItem(){
        double minPrice=prices[0];
        string cheapest=menu[0];
        for (int i=1;i<5;i++) {
            if (prices[i]<minPrice) {
                minPrice=prices[i];
                cheapest=menu[i];
            }
        }
        return cheapest;
    }

    void drinksOnly(){
        cout << "Drinks: Coffee, Tea, Juice" << endl;
    }

    void foodOnly() {
        cout << "Food: Sandwich, Muffin" << endl;
    }
};
int main(int argc, char* argv[]){
	CoffeeShop c("Luna Coffe Shop");
	int choice=0;
	string order;
while (choice!=8) {
        cout<<"\nMenu: \n";
        cout<<"1. Add Order\n";
        cout<<"2. Fulfill Order\n";
        cout<<"3. List Orders\n";
        cout<<"4. View Due Amount\n";
        cout<<"5. Cheapest Item\n";
        cout<<"6. List Drinks Only\n";
        cout<<"7. List Food Only\n";
        cout<<"8. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
            	cout<<"Enter item name: "<<endl;
            	cin>>order;
            	
                c.addOrder(order);
                break;
            case 2:
                cout << c.fulfillOrder() << endl;
                break;
            case 3:
                c.listOrders();
                break;
            case 4:
                cout << "Total due: Rs" << c.dueAmount() << endl;
                break;
            case 5:
                cout << "Cheapest item: " << c.cheapestItem() << endl;
                break;
            case 6:
                c.drinksOnly();
                break;
            case 7:
                c.foodOnly();
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    
    return 0;
}

