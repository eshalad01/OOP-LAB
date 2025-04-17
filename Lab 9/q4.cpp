#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Flight {
private:
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    int bookedSeats;

public:
    Flight(string fn, string dep, string arr, int cap) 
        : flightNumber(fn), departure(dep), arrival(arr), capacity(cap), bookedSeats(0) {}

    void bookSeat() {
        if (bookedSeats < capacity) {
            bookedSeats++;
            cout << "Booking successful! Available seats: " << getAvailableSeats() << endl;
        } else {
            cout << "Booking failed! No available seats." << endl;
        }
    }

    void cancelSeat() {
        if (bookedSeats > 0) {
            bookedSeats--;
            cout << "Cancellation successful! Available seats: " << getAvailableSeats() << endl;
        } else {
            cout << "Cancellation failed! No seats booked." << endl;
        }
    }

    void upgradeSeat() {
        if (bookedSeats > 0) {
            cout << "Upgrade successful! You are now in an upgraded seat." << endl;
        } else {
            cout << "Upgrade failed! No seats booked." << endl;
        }
    }

    int getAvailableSeats() const {
        return capacity - bookedSeats;
    }
};

class Passenger {
private:
    string id;
    string name;

public:
    Passenger(string id, string name) : id(id), name(name) {}

    void requestBooking(Flight& flight) {
        flight.bookSeat();
    }

    void requestCancellation(Flight& flight) {
        flight.cancelSeat();
    }

    void requestUpgrade(Flight& flight) {
        flight.upgradeSeat();
    }
};

int main() {
    Flight flight1("A123", "Islamabad", "Lahore", 5);
    Passenger passenger1("B123", "Faizan Ahmed");

    passenger1.requestBooking(flight1); 
    passenger1.requestCancellation(flight1);

    return 0;
}

