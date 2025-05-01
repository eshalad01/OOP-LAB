#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Users {
public:
    struct User {
        string user_id;
        string first_name;
        string last_name;
        string address;
        string email;
    };
    vector<User> records;

    void addUser(string id, string first, string last, string addr, string email) {
        records.push_back({id, first, last, addr, email});
    }

    string findUserIdByFirstName(string name) {
        for (User user : records) {
            if (user.first_name == name) {
                return user.user_id;
            }
        }
        return ""; 
    }
};

class Products {
public:
    struct Product {
        string product_id;
        string product_name;
        string description;
        int price;
    };
    vector<Product> records;

    void addProduct(string id, string name, string desc, int price) {
        records.push_back({id, name, desc, price});
    }

    string getProductNameById(string id) {
        for (Product product : records) {
            if (product.product_id == id) {
                return product.product_name;
            }
        }
        return "";
    }
};

class Orders {
public:
    struct Order {
        string order_id;
        string user_id;
        string product_id;
        int total_paid;
    };
    vector<Order> records;

    void addOrder(string oid, string uid, string pid, int paid) {
        records.push_back({oid, uid, pid, paid});
    }

    vector<Order> getOrdersByUserId(string uid) {
        vector<Order> userOrders;
        for (Order order : records) {
            if (order.user_id == uid) {
                userOrders.push_back(order);
            }
        }
        return userOrders;
    }
};

int main() {
    Users users;
    Products products;
    Orders orders;
    users.addUser("U1", "Linus", "Torvalds", "Finland", "linus@linux.com");
    users.addUser("U2", "John", "Doe", "USA", "john@doe.com");

    products.addProduct("P1", "Linux OS", "Open-source operating system", 0);
    products.addProduct("P2", "Git", "Version control system", 0);
    products.addProduct("P3", "C++ Compiler", "Compiler for C++ programs", 100);
    orders.addOrder("O1", "U1", "P1", 0);
    orders.addOrder("O2", "U1", "P2", 0);
    orders.addOrder("O3", "U2", "P3", 100);
    string linusId = users.findUserIdByFirstName("Linus");
    if (linusId.empty()) {
        cout << "User Linus not found!" << endl;
        return 0;
    }

    vector<Orders::Order> linusOrders = orders.getOrdersByUserId(linusId);
    cout << "Products ordered by Linus:" << endl;
    for (Orders::Order order : linusOrders) {
        string productName = products.getProductNameById(order.product_id);
        if (!productName.empty()) {
            cout << "- " << productName << endl;
        }
    }

    return 0;
}
