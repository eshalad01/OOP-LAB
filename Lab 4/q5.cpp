#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MenuItem{
public:
    string name;
    string type; 
    double price;
    MenuItem(string n,string t,double p):name(n),type(t),price(p) 
	{}
};

class CoffeeShop {
private:
    string name;
    vector<MenuItem>menu;
    vector<string>orders;

public:
    CoffeeShop(string shopName):name(shopName)
	 {}

    void addMenuItem(MenuItem item){
        menu.push_back(item);
    }

    string addOrder(string itemName){
        for (const auto& item:menu){
            if(item.name==itemName){
                orders.push_back(itemName);
                return"Order added: "+itemName;
            }
        }
        return"This item is currently unavailable";
    }

    string fulfillOrder(){
        if (!orders.empty()){
            string item=orders.front();
            orders.erase(orders.begin());
            return "The "+item+" is ready";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total=0;
        for (const auto& order:orders) {
            for (const auto& item:menu) {
                if (item.name==order) {
                    total+=item.price;
                }
            }
        }
        return total;
    }

    string cheapestItem(){
        if (menu.empty())
		{ return "No items in the menu";}
        MenuItem cheapest=menu[0];
        for (const auto& item:menu) {
            if (item.price<cheapest.price) {
                cheapest=item;
            }
        }
        return cheapest.name;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (const auto& item:menu) {
            if (item.type=="drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> foods;
        for (const auto& item:menu) {
            if (item.type=="food") {
                foods.push_back(item.name);
            }
        }
        return foods;
    }
};

int main(int argc,char* argv[]) {
    CoffeeShop shop("Java Cafe");
    shop.addMenuItem(MenuItem("Espresso","drink",2.5));
    shop.addMenuItem(MenuItem("Sandwich","food",5.0));
    
    cout<<shop.addOrder("Espresso") << endl;
    cout<<shop.fulfillOrder() << endl;
    cout<<"Total due: $"<<shop.dueAmount()<<endl;

    return 0;
}

