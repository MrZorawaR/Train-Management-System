#include <bits/stdc++.h>
using namespace std;

class Train {
public:
    string train_name;
    int train_number;
    string source;
    string destination;
    string date;
    int fare;
    int seats_available;

    Train(string train_name, int train_number, string source, string destination, string date, int fare, int seats_available) {
        this->train_name = train_name;
        this->train_number = train_number;
        this->source = source;
        this->destination = destination;
        this->date = date;
        this->fare = fare;
        this->seats_available = seats_available;
    }

    void displayTrainInfo() const {
        cout << "Train Name: " << train_name << endl;
        cout << "Train Number: " << train_number << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Date: " << date << endl;
        cout << "Fare: " << fare << endl;
        cout << "Seats Available: " << seats_available << endl;
    }
};

class Customer {
public:
    string name;
    int age;
    string gender;
    string contact_number;
    int seat_number;
    int train_number;

    Customer(const string& name, int age, const string& gender, const string& contact_number, int seat_number, int train_number) {
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->contact_number = contact_number;
        this->seat_number = seat_number;
        this->train_number = train_number;
    }
};

vector<Train> trains;
vector<Customer> customers;

void addTrain() {
    string train_name, source, destination, date;
    int train_number, fare, seats_available;

    cout << "Enter Train Name: ";
    cin.ignore();
    getline(cin, train_name);

    cout << "Enter train number: ";
    cin >> train_number;

    cout << "Enter source: ";
    cin.ignore();
    getline(cin, source);

    cout << "Enter destination: ";
    getline(cin, destination);

    cout << "Enter date: ";
    getline(cin, date);

    cout << "Enter fare: ";
    cin >> fare;

    cout << "Enter seats available: ";
    cin >> seats_available;

    trains.push_back(Train(train_name, train_number, source, destination, date, fare, seats_available));
}

void viewTrains() {
    if (trains.empty()) {
        cout << "No trains available." << endl;
        return;
    }

    for (const auto& train : trains) {
        train.displayTrainInfo();
        cout << endl;
    }
}

void bookTicket(int train_number) {
    for (auto& train : trains) {
        if (train.train_number == train_number) {
            if (train.seats_available > 0) {
                string name, gender, contact_number;
                int age;

                cout << "Enter your First name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter your age: ";
                cin >> age;

                cout << "Enter your gender: ";
                cin.ignore();
                getline(cin, gender);

                cout << "Enter your contact number: ";
                getline(cin, contact_number);

                int seat_number = train.seats_available;
                train.seats_available--;

                customers.push_back(Customer(name, age, gender, contact_number, seat_number, train_number));
                cout << "Ticket booked successfully!" << endl;
                return;
            } else {
                cout << "Sorry, no seats available for this train." << endl;
                return;
            }
        }
    }
    cout << "Invalid train number." << endl;
}

void printTicket(const Train& train, const Customer& customer) {
    cout << "\n--- Railway Reservation Ticket ---" << endl;
    cout << "Train Name: " << train.train_name << endl;
    cout << "Train Number: " << train.train_number << endl;
    cout << "Date: " << train.date << endl;
    cout << "Source: " << train.source << endl;
    cout << "Destination: " << train.destination << endl;
    cout << "Fare: " << train.fare << endl;

    cout << "\n--- Passenger Details ---" << endl;
    cout << "Name: " << customer.name << endl;
    cout << "Age: " << customer.age << endl;
    cout << "Gender: " << customer.gender << endl;
    cout << "Contact Number: " << customer.contact_number << endl;
    cout << "Seat Number: " << customer.seat_number << endl;
}

void viewBookedTickets() {
    if (customers.empty()) {
        cout << "No tickets booked." << endl;
        return;
    }

    for (const auto& customer : customers) {
        for (const auto& train : trains) {
            if (train.train_number == customer.train_number) {
                printTicket(train, customer);
                break;
            }
        }
    }
}


void interactiveMenu() {
    int choice;

    do {
        system("cls");
        // displayWelcomeScreen();
        cout << "\n--- Railway Reservation System ---" << endl;
        cout << "1. Add Train" << endl;
        cout << "2. View Trains" << endl;
        cout << "3. Book Ticket" << endl;
        cout << "4. View Booked Tickets" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTrain();
                break;
            case 2:
                viewTrains();
                break;
            case 3:
                int train_number;
                cout << "Enter train number: ";
                cin >> train_number;
                bookTicket(train_number);
                break;
            case 4:
                viewBookedTickets();
                break;
            case 5:
                cout << "Thank you for using the Railway Reservation System!" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }

        if (choice != 5) {
            cout << "\nPress any key to continue...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 5);
}

int main() {
    interactiveMenu();
    return 0;
}
