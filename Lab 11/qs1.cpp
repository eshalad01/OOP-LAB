#include <iostream>
#include <variant>
#include <stdexcept>
#include <string>

using namespace std;

class BadTypeException : public runtime_error {
public:
    BadTypeException(const string& message) : runtime_error(message) {}
};

template <typename... Types>
class TypeSafeContainer {
private:
    variant<Types...> data;

public:
    template <typename T>
    void store(const T& value) {
        data = value;
    }

    template <typename T>
    T get() const {
        if (std::holds_alternative<T>(data)) {
            return std::get<T>(data);
        } else {
            throw BadTypeException("Requested type does not match stored type.");
        }
    }
};

int main() {
    TypeSafeContainer<int, double, string> container;

    container.store(42);
    try {
        cout << container.get<int>() << endl;     
        cout << container.get<double>() << endl;  
    } catch (const BadTypeException& e) {
        cerr << e.what() << endl;
    }

    return 0;
}

