//maheera 21i-1158
#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <conio.h>

using namespace std;

const int MAX_FLIGHTS = 100;
const int MAX_PASSENGERS = 1000;
const int MAX_AIRPORTS = 10;

//THIS IS THE DETAILS OF ONE FLIGHT
class Flight {
    int flightNumber;
    string origin;
    string destination;
    string departureTime;
    string arrivalTime;
    int availableEconomySeats;
    int availableBusinessSeats;
    double cost;
public:
    Flight() {
        flightNumber = 0;
        origin = "";
        destination = "";
        departureTime = "";
        arrivalTime = "";
        availableEconomySeats = 0;
        availableBusinessSeats = 0;
        cost = 0.0;
    }
    Flight(int flightNumber, string origin, string destination, string departureTime, string arrivalTime, double cost, int availableEconomySeats, int availableBusinessSeats) {
        this->flightNumber = flightNumber;
        this->origin = origin;
        this->destination = destination;
        this->departureTime = departureTime;
        this->arrivalTime = arrivalTime;
        this->availableEconomySeats = availableEconomySeats;
        this->availableBusinessSeats = availableBusinessSeats;
        this->cost = cost;
    }

    void setFlightNumber(int flightNumber) {
        this->flightNumber = flightNumber;
    }
    void setOrigin(string origin) {
        this->origin = origin;
    }
    void setDestination(string destination) {
        this->destination = destination;
    }
    void setDepartureTime(string departureTime) {
        this->departureTime = departureTime;
    }
    void setArrivalTime(string arrivalTime) {
        this->arrivalTime = arrivalTime;
    }

    int getFlightNumber() {
        return flightNumber;
    }
    string getOrigin() {
        return origin;
    }
    string getDestination() {
        return destination;
    }
    string getDepartureTime() {
        return departureTime;
    }
    string getArrivalTime() {
        return arrivalTime;
    }
    int getAvailableEconomySeats() {
        return availableEconomySeats;
    }
    int getAvailableBusinessSeats() {
        return availableBusinessSeats;
    }
    double getCost() {
        return cost;
    }
    void bookSeat() {
        string seatType;
        cout << "Enter seat type (economy/business): ";
        cin >> seatType;

        if (seatType == "economy" && availableEconomySeats > 0) {
            availableEconomySeats--;
            cout << "Economy seat booked successfully." << endl;
        }
        else if (seatType == "business" && availableBusinessSeats > 0) {
            availableBusinessSeats--;
            cout << "Business seat booked successfully." << endl;
        }
        else {
            cout << "Sorry, no seats available of the requested type on this flight." << endl;
        }
    }
    
        // Calculate flight duration in minutes
    int calculateduration() {
        int departureHour = stoi(getDepartureTime().substr(0, 2));
        int departureMinute = stoi(getDepartureTime().substr(3, 2));
        int arrivalHour = stoi(getArrivalTime().substr(0, 2));
        int arrivalMinute = stoi(getArrivalTime().substr(3, 2));
        int duration = (arrivalHour * 60 + arrivalMinute) - (departureHour * 60 + departureMinute);
        // Convert duration to hours and round up to nearest hour
        int hours = (duration + 59) / 60;
        return hours;
    }
      
     
};


//THIS IS TO MAKE SURE THAT ONLY THE SET AMOUNT OF AIRPLANES TAKE OFF
class Airplane {
    int id;
    string model;
    int capacity;
    Flight assignedFlights[MAX_FLIGHTS];
    int numAssignedFlights;
public:
    Airplane(int id, string model, int capacity) {
        this->id = id;
        this->model = model;
        this->capacity = capacity;
        numAssignedFlights = 0;
    }
    int getId() {
        return id;
    }
    string getModel() {
        return model;
    }
    int getCapacity() {
        return capacity;
    }
    void assignFlight(Flight flight) {
        if (numAssignedFlights < MAX_FLIGHTS) {
            assignedFlights[numAssignedFlights++] = flight;
            cout << "Flight assigned successfully." << endl;
        }
        else {
            cout << "Sorry, this airplane is already assigned to the maximum number of flights." << endl;
        }
    }
    void printAssignedFlights() {
        cout << "Assigned flights:" << endl;
        for (int i = 0; i < numAssignedFlights; i++) {
            cout << assignedFlights[i].getFlightNumber() << " - " << assignedFlights[i].getOrigin() << " to " << assignedFlights[i].getDestination() << endl;
        }
    }
};

//DETAILS OF AIRPORT
class Airport {
    string name;
    string location;
    string Runnway;
    Flight flightSchedules[MAX_FLIGHTS];
    int numFlightSchedules;
public:
    Airport(string name, string location, string Runnway) {
        this->name = name;
        this->location = location;
        this->Runnway = Runnway;
        numFlightSchedules = 0;
    }
    string getName() {
        return name;
    }
    string getLocation() {
        return location;
    }
    string getRunway() {
        return Runnway;
    }
 
    // Add a flight schedule to the airport
    void addFlightSchedule(Flight flight) {
        if (numFlightSchedules >= MAX_FLIGHTS) {
            cout << "Cannot add more flight schedules. Maximum capacity reached." << endl;
            return;
        }

        flightSchedules[numFlightSchedules++] = flight;
    }
    // Remove a flight schedule from the airport
    void removeFlightSchedule(int flightNumber) {
        for (int i = 0; i < numFlightSchedules; i++) {
            if (flightSchedules[i].getFlightNumber() == flightNumber) {
                // Shift all flight schedules after the one to be removed by one index to the left
                for (int j = i + 1; j < numFlightSchedules; j++) {
                    flightSchedules[j - 1] = flightSchedules[j];
                }

                // Decrement the counter to reflect the removal of a flight schedule
                numFlightSchedules--;

                cout << "Flight #" << flightNumber << " has been removed from the airport schedule." << endl;
                return;
            }
        }

        // If the flight number is not found, display an error message
        cout << "Flight #" << flightNumber << " is not found in the airport schedule." << endl;
    }

    // Get the number of available seats in a particular flight schedule
    int getAvailableSeats(int flightNumber) {
        for (int i = 0; i < numFlightSchedules; i++) {
            if (flightSchedules[i].getFlightNumber() == flightNumber) {
                cout << "The Economy Seats Available are: "<< flightSchedules[i].getAvailableEconomySeats();
                cout << endl;
                cout << "The Business Seats Available are: " << flightSchedules[i].getAvailableBusinessSeats();
                cout << endl;
            }
        }

        // If the flight number is not found, return -1 to indicate an error
        return -1;
    }
};

//THIS CLASS WILL SHOW ALL THE FLIGHT TIMINGS AND DATA
class ShowFlightSchedule {
private:
    string cityFrom;
    string cityTo;
    string airport;
    string departureTime;
    string arrivalTime;
    bool isInternational;

public:
    // Constructors
    ShowFlightSchedule() {
        cityFrom = "";
        cityFrom = "";
        airport = "";
        departureTime = "";
        arrivalTime = "";
    }
    ShowFlightSchedule(string cityFrom, string cityTo, string airport, string departureTime,
        string arrivalTime, bool isInternational) :
        cityFrom(cityFrom), cityTo(cityTo), airport(airport), departureTime(departureTime),
        arrivalTime(arrivalTime), isInternational(isInternational) {}

    // Getter methods
    string getCityFrom() const { return cityFrom; }
    string getCityTo() const { return cityTo; }
    string getAirport() const { return airport; }
    string getDepartureTime() const { return departureTime; }
    string getArrivalTime() const { return arrivalTime; }
    bool getIsInternational() const { return isInternational; }

};
// Function to display flight schedule
void displayFlightSchedule(ShowFlightSchedule* schedules, int numSchedules) {
    cout << "FLIGHT SCHEDULE" << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    cout << left << setw(14) << "City From" << setw(14) << "City To" << setw(16) << "Airport" << setw(21) << "Departure Time" << setw(21) << "Arrival Time" << "International" << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < numSchedules; i++) {
        cout << left << setw(14) << schedules[i].getCityFrom() << setw(14) << schedules[i].getCityTo() << setw(16) << schedules[i].getAirport() << setw(21) << schedules[i].getDepartureTime() << setw(21) << schedules[i].getArrivalTime() << (schedules[i].getIsInternational() ? "Yes" : "No") << endl;
    }
    cout << "----------------------------------------------------------------------------------------------------" << endl;
}


class Route {
    string origin;
    string destination;
public:
    Route() {
        origin = "";
        destination = "";
    }
    Route(string origin, string destination) {
        this->origin = origin;
        this->destination = destination;
    }
    string getOrigin() {
        return origin;
    }
    string getDestination() {
        return destination;
    }
};

//THE CLASS USER WHICH ADMIN AND PASSENGER WILL INHERIT
class User {
private:
    string username;
    string password;

public:
    User() {
        username = "";
        password = "";
    }
    User(const string& username, const std::string& password) {
        setUsername(username);
        setPassword(password);
    }

    void setUsername(const string& username) {
        this->username = username;
    }

    void setPassword(const string& password) {
        // Check that password is at least 8 characters long
        if (password.length() < 8) {
            throw invalid_argument("Password must be at least 8 characters long");
        }

        bool has_uppercase = false;
        bool has_lowercase = false;
        bool has_number = false;
        bool has_special = false;

        for (char c : password) {
            if (std::isupper(c)) {
                has_uppercase = true;
            }
            else if (islower(c)) {
                has_lowercase = true;
            }
            else if (isdigit(c)) {
                has_number = true;
            }
            else if (!isalnum(c)) {
                has_special = true;
            }
        }

        // Check that password contains at least one uppercase letter, one lowercase letter, one number, and one special character
        if (!(has_uppercase && has_lowercase && has_number && has_special)) {
            throw invalid_argument("Password must contain at least one uppercase letter, one lowercase letter, one number, and one special character");
        }

        this->password = password;
    }

    const string& getUsername() const {
        return username;
    }

    const string& getPassword() const {
        return password;
    }

};

//TO REGISTER THE USER
void registerUser() {
    cout << "Please provide your desired username and password:" << endl;
    string username, password;

    // Get username
    cout << "Username: ";
    cin.ignore();
    getline(cin, username);

    // Get password
    cout << "Password: ";
    char c;
    password = "";
    while ((c = _getch()) != '\r') {
        if (c == '\b') {
            if (password.length() > 0) {
                password.pop_back();
                cout << "\b \b";
            }
        }
        else {
            password += c;
            cout << "*";
        }
    }
    cout << endl;

    try {
        User u;
        u.setUsername(username);
        u.setPassword(password);
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
        return;
    }

    cout << "Account created successfully." << endl;
}

//CLASS PASSENGER
class Passenger : public User {
    string name;
    int age;
    string cnic;
    string passport;
    Route bookedFlights[MAX_FLIGHTS];
    int numBookedFlights;
    string creditCardNumber;
    string expirationDate;
    double balance;
public:
    Passenger() {
        name = "";
        age = 0;
        cnic = "";
        passport = "";
        numBookedFlights = 0;
        creditCardNumber = "";
        expirationDate = "";
        balance = 0.0;
    }

    Passenger(string name, int age, string cnic, string passport) {
        this->name = name;
        this->age = age;
        this->cnic = cnic;
        this->passport = passport;
        numBookedFlights = 0;
    }
    // getters and setters
    void setCreditCardNumber(string ccNumber) {
        creditCardNumber = ccNumber;
    }
    string getCreditCardNumber() const {
        return creditCardNumber;
    }

    void setExpirationDate(string expDate) {
        expirationDate = expDate;
    }
    string getExpirationDate() const {
        return expirationDate;
    }

    void setBalance(double bal) {
        balance = bal;
    }
    double getBalance() const {
        return balance;
    }
    string getName() {
        return name;
    }
    int getAge() {
        return age;
    }
    string getCNIC() {
        return cnic;
    }
    string getPassport() {
        return passport;
    }
    void bookFlight(Route flight) {
        if (numBookedFlights < MAX_FLIGHTS) {
            bookedFlights[numBookedFlights++] = flight;
            cout << "Flight booked successfully." << endl;
        }
        else {
            cout << "Sorry, you have already booked the maximum number of flights." << endl;
        }
    }
    void accountDetails() {
        cout << "Your Account Details are:" << endl;
        cout << "Credit card number: " << creditCardNumber << endl;
        cout << "Expiration date (MM/YY): " << expirationDate << endl;
        cout << "Account balance: Rs." << balance << endl;
        cout << "Thank you for providing your financial details." << endl;
    }
   
};


//CLASS ADMIN
class Admin : public User {
private:
    string username;
    string password;
public:
    Admin(const string& username, const string& password) : User (username, password) {} 

    // Add a new flight to the flight schedule
    void addFlight(Flight flight, Flight flightSchedules[], int& numFlightSchedules) {
        if (numFlightSchedules >= MAX_FLIGHTS) {
            cout << "Cannot add more flights. Maximum capacity reached." << endl;
            return;
        }

        flightSchedules[numFlightSchedules++] = flight;
        cout << "Flight added successfully." << endl;
    }

    // Add a new route to the route schedule
    void addRoute(Route route, Route routeSchedule[], int& numRouteSchedules) {
        if (numRouteSchedules >= MAX_FLIGHTS) {
            cout << "Cannot add more routes. Maximum capacity reached." << endl;
            return;
        }

        routeSchedule[numRouteSchedules++] = route;
        cout << "Route added successfully." << endl;
    }
};

//THIS WILL BE FOR BOOKING AND CANCELLATION OF FLIGHTS
class FlightReservation {
    int numReservations;
    Flight flights[MAX_FLIGHTS];
    int numFlights;
public:
    FlightReservation() {
        numReservations = 0;
        numFlights = 0;
    }
    void bookFlight(Flight flight) {
        if (numFlights < MAX_FLIGHTS) {     
            flights[numFlights++] = flight;
            cout << "Flight booked successfully." << endl;
        }
        else {
            cout << "Sorry, cannot book more flights. Maximum capacity reached." << endl;
        }
    }
    void cancelFlight(int flightNumber) {
        for (int i = 0; i < numFlights; i++) {
            if (flights[i].getFlightNumber() == flightNumber) {
                // Shift all flights after the one to be canceled by one index to the left
                for (int j = i + 1; j < numFlights; j++) {
                    flights[j - 1] = flights[j];
                }
                numFlights--;
                cout << "Flight canceled successfully." << endl;
                return;
            }
        }
        cout << "Sorry, cannot find a flight with the given flight number." << endl;
    }
};

class Payment : public Flight, public Passenger {
private:
    Passenger passenger;
    Flight flight;
    int payment;
public:
    Payment(){
        payment = 0;
    }
    double calculateCost(string destination, int hours) 
    {
        double pricePerHour = 0.0;
        double costt;
        if (destination == "Dubai" || destination == "dubai" || destination == "Thailand" || destination == "thailand" || destination == "america" || destination == "America" || destination == "canada" || destination == "Canada")
        {
            // International flight
            pricePerHour = 20000.0;
            costt = hours * pricePerHour;
            float tax = costt * 1.10;
            costt += tax;
            return costt;
        }
        else if (destination == "Islamabad" || destination == "islamabad" || destination == "Lahore" || destination == "lahore" || destination == "karachi" || destination == "Karachi" || destination == "Peshawar" || destination == "peshawar" || destination == "Quetta" || destination == "quetta")
        {
            //local flight
            pricePerHour = 10000.0;
            costt = hours * pricePerHour;
            float tax = costt * 0.50;
            costt += tax;
            return costt;
        }
    }

    bool VerifyFinancialdetails()
    {
        if (getBalance() >= calculateCost(getDestination(), calculateduration()))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void generateTicket() {
        cout << "***********************************" << endl;
        cout << "Ticket Information" << endl;
        cout << "***********************************" << endl;
        cout << "Passenger Name: " << passenger.getName() << endl;
        cout << "Passenger Age: " << passenger.getAge() << endl;
        cout << "Flight Number: " << flight.getFlightNumber() << endl;
        cout << "Origin: " << flight.getOrigin() << endl;
        cout << "Destination: " << flight.getDestination() << endl;
        cout << "Departure Time: " << flight.getDepartureTime() << endl;
        cout << "Arrival Time: " << flight.getArrivalTime() << endl;
        cout << "Cost: Rs." << calculateCost(flight.getDestination(),flight.calculateduration()) << endl;
        cout << "***********************************" << endl;
    }
};


    int main() {

        int choice;

        const int numCities = 5;
        const int numAirports = 2;
        const int numLocalFlights = 10;
        const int numInternationalFlights = 5;
        const int numSchedules = numCities * numAirports * (numLocalFlights + numInternationalFlights);

        string cities[numCities] = { "Islamabad", "Peshawar", "Quetta", "Lahore", "Karachi" };
        string airports[numAirports] = { "North", "South" };
        string internationalDestinations[numInternationalFlights] = { "Dubai", "Thailand", "America", "Canada" };
        ShowFlightSchedule* schedules = new ShowFlightSchedule[numSchedules];

        int index = 0;

        string ccNumber, expDate;
        double balance;
        Passenger p("", 0, "", "");

        cout << "Welcome to NUCES Airline Flight System (NAFS)!\n";

        do {
            cout << "\n";
            cout << "1. Login as Admin\n";
            cout << "2. Login as Passenger\n";
            cout << "3. Register as Admin\n";
            cout << "4. Register as Passenger\n";
            cout << "5.See Flight Schedule\n";
            cout << "6. Exit\n";

            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                int select;

                do {
                    cout << "THIS IS THE ADMIN PANEL\n";
                    cout << "1.Add New Route of Flight\n";
                    cout << "2.Change the schedule of Flight\n";
                    cout << "3.Add Flight\n";
                    cout << "4.Remove Flight\n";
                    cout << "5.Exit\n";

                    cout << "Enter your choice: " << endl;
                    cin >> select;

                    switch (select)
                    {
                    case 1:
                    {
                        //add a new route add from which airport to which
                        break;
                    }
                    case 2:
                    {
                        //change the schdule ask user which schdule to change timing and all
                        break;
                    }
                    case 3:
                    {
                        //add flight
                        break;
                    }
                    case 4:
                    {
                        //remove flight
                        break;
                    }
                    }

                } while (select != 5);

                break;

            case 2:
                int selectt;

                do {
                    cout << "THIS IS THE PASSENGER PANEL\n";
                    cout << "1.Book a Flight\n";
                    cout << "2.Cancel a Flight\n";
                    cout << "3.Exit\n";

                    cout << "Enter your choice: " << endl;
                    cin >> selectt;

                    switch (selectt)
                    {
 
                    case 1:
                    {
                        // Create a Flight object
                        Flight myFlight (0,"", "", "", "", 0, 50, 20);
                       
                        //Ask user to enter origin and destination
                        string origin, destination;
                        cout << "Enter which city you are in: ";
                        cin >> origin;
                        myFlight.setOrigin(origin);
                        cout << "Enter what is your destination: ";
                        cin >> destination;
                        myFlight.setDestination(destination);
                       
                        // Ask user to enter arrival and departure times
                        string arrivalTime, departureTime;
                        cout << "Enter arrival time (HH:MM): ";
                        cin >> arrivalTime;
                        myFlight.setArrivalTime(arrivalTime);

                        cout << "Enter departure time (HH:MM): ";
                        cin >> departureTime;
                        myFlight.setDepartureTime(departureTime);

                        // Book a seat
                        myFlight.bookSeat();

                        //tell duration of flight
                      /*  cout << "The duration of your flight is: ";*/
                        int hours= myFlight.calculateduration();

                        Payment p;
                        p.calculateCost(destination,hours);
                        p.generateTicket();

                        break;
                    }
                    case 2:
                    {
                        //call cancel flight function
                        FlightReservation Fr;
                        cout << "Enter the Flight Number: ";
                        int num;
                        cin >> num;
                        Fr.cancelFlight(num);
                        break;
                    }
                    }

                } while (selectt != 3);
                break;

            case 3:
                //call the register as admin function
                registerUser();
                cout << "You have registered as an admin." << endl;
                break;
                
                break;
            case 4:
                //call the register as passenger function
                registerUser();
                cout << "You have registered as a passenger." << endl;

                // ask for account details for the passenger
                cout << "Please provide your account details:" << endl;
                cout << "Credit card number: ";
                cin >> ccNumber;
                cout << "Expiration date (MM/YY): ";
                cin >> expDate;
                cout << "Account balance: ";
                cin >> balance;

               
                p.setCreditCardNumber(ccNumber);
                p.setExpirationDate(expDate);
                p.setBalance(balance);
                p.accountDetails();
                break;
            case 5:
                cout << "\nFLIGHT SCHEDULE:\n";
                //Create flight schedules for all local flights
                for (int i = 0; i < numCities; i++) {
                    for (int j = 0; j < numAirports; j++) {
                        for (int k = 1; k <= numLocalFlights; k++) {
                            string cityFrom = cities[i];
                            string cityTo = cities[(i + k) % numCities];
                            string airport = airports[j];
                            string departureTime = to_string(6 + k % 4) + ":00 AM";
                            string arrivalTime = to_string(6 + (k + 1) % 4) + ":00 AM";
                            bool isInternational = false;
                            schedules[index++] = ShowFlightSchedule(cityFrom, cityTo, airport, departureTime, arrivalTime, isInternational);
                        }
                    }
                }
                // Create flight schedules for all international flights
                for (int i = 0; i < numCities; i++) {
                    for (int j = 0; j < numAirports; j++) {
                        for (int k = 0; k < numInternationalFlights; k++) {
                            string cityFrom = cities[i];
                            string cityTo = internationalDestinations[k];
                            string airport = airports[j];
                            string departureTime = to_string(9 + k % 4) + ":00 PM";
                            string arrivalTime = to_string(9 + (k + 1) % 4) + ":00 AM";
                            bool isInternational = true;
                            schedules[index++] = ShowFlightSchedule(cityFrom, cityTo, airport, departureTime,
                                arrivalTime, isInternational);
                        }
                    }
                }

                // Display flight schedule
                displayFlightSchedule(schedules, numSchedules);
                break;
            case 6:
                cout << "\nGoodbye!\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
                break;
            }
        } while (choice != 6);

        delete[] schedules;

        return 0;
    }
