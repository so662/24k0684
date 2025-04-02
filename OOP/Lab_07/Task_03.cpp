#include <iostream>
#include <string>
using namespace std;

class Ticket {
protected:
    int ticketID;
    string passengerName;
    double price;
    string date;
    string destination;

public:
    Ticket(int id, string name, double price, string date, string destination)
        : ticketID(id), passengerName(name), price(price), date(date), destination(destination) {}

    void reserve() {
        cout << "Ticket reserved for " << passengerName << " to " << destination << " on " << date << endl;
    }

    void cancel() {
        cout << "Cannot cancel , Already reserved with ticket id :" << ticketID << endl;
    }

    void displayTicketInfo() const {
        cout << "Ticket ID: " << ticketID << endl;
        cout << "Passenger Name: " << passengerName << endl;
        cout << "Price: $" << price << endl;
        cout << "Date: " << date << endl;
        cout << "Destination: " << destination << endl;
    }

};

class FlightTicket : public Ticket {
private:
    string airlineName;
    string flightNumber;
    string seatClass;

public:
    FlightTicket(int id, string name, double price, string date, string destination, string airline, string flight, string seatClass)
        : Ticket(id, name, price, date, destination), airlineName(airline), flightNumber(flight), seatClass(seatClass) {}

    void displayTicketInfo() {
        Ticket::displayTicketInfo();
        cout << "Airline: " << airlineName << endl;
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Seat Class: " << seatClass << endl;
    }
};

class TrainTicket : public Ticket {
private:
    string trainNumber;
    string coachType;
    string departureTime;

public:
    TrainTicket(int id, string name, double price, string date, string destination, string train, string coach, string time)
        : Ticket(id, name, price, date, destination), trainNumber(train), coachType(coach), departureTime(time) {}

    void reserve() {
        cout << "Train ticket reserved for " << passengerName << " on train " << trainNumber << " in " << coachType
             << " coach at " << departureTime << endl;
    }

    void displayTicketInfo()  {
        Ticket::displayTicketInfo();
        cout << "Train Number: " << trainNumber << endl;
        cout << "Coach Type: " << coachType << endl;
        cout << "Departure Time: " << departureTime << endl;
    }
};

class BusTicket : public Ticket {
private:
    string busCompany;
    string seatNumber;

public:
    BusTicket(int id, string name, double price, string date, string destination, string company, string seat)
        : Ticket(id, name, price, date, destination), busCompany(company), seatNumber(seat) {}

    void cancel() {
        cout << "Bus ticket with ID " << ticketID << " has been canceled." << endl;
    }

    void displayTicketInfo(){
        Ticket::displayTicketInfo();
        cout << "Bus Company: " << busCompany << endl;
        cout << "Seat Number: " << seatNumber << endl;
    }
};

class ConcertTicket : public Ticket {
private:
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(int id, string name, double price, string date, string destination, string artist, string venue, string seat)
        : Ticket(id, name, price, date, destination), artistName(artist), venue(venue), seatType(seat) {}

    void displayTicketInfo(){
        Ticket::displayTicketInfo();
        cout << "Artist Name: " << artistName << endl;
        cout << "Venue: " << venue << endl;
        cout << "Seat Type: " << seatType << endl;
    }
};

int main() {
    FlightTicket ft(1, "Ahmed Ali", 500.0, "2025-04-10", "New York", "Delta Airlines", "DL123", "Business");
    TrainTicket tt(2, "Soofiyan Khan", 100.0, "2025-04-12", "Chicago", "TR456", "Sleeper", "10:00 AM");
    BusTicket bt(3, "Hamza Ahmed", 50.0, "2025-04-15", "Los Angeles", "Greyhound", "B12");
    ConcertTicket ct(4, "Ali Soofiyan", 150.0, "2025-04-20", "Las Vegas", "The Weeknd", "MGM Grand", "VIP");

    ft.displayTicketInfo();
    ft.reserve();
    ft.cancel();
    cout << endl;

    tt.displayTicketInfo();
    tt.reserve();
    tt.cancel();
    cout << endl;

    bt.displayTicketInfo();
    bt.reserve();
    bt.cancel();
    cout << endl;

    ct.displayTicketInfo();
    ct.reserve();
    ct.cancel();
    cout << endl;

    return 0;
}
