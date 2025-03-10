//
// Created by Aulas FEUP on 16/12/2021.
//

#ifndef PROJECTAED_COMPANY_H
#define PROJECTAED_COMPANY_H
#include <vector>
#include "Airport.h"
#include "Plane.h"
#include "Flight.h"

using namespace std;

class Company {
public:
    vector<Plane> planes;
    vector<Airport> airports;
    vector<Flight> flights;
    vector<Passenger> passengers;
    Company(){
        planes = {};
        airports = {};
        flights = {};
        passengers = {};
    }

    //Getters:
    vector<Plane> getPlanes();
    vector<Airport> getAirports();
    vector<Flight> getFlights();
    vector<Passenger> getPassengers();

    //Add Elements to Company:
    void addPlane(Plane p);
    void addAirport(Airport a);
    void addFlight(Flight f);
    void addPassenger(Passenger p);

    //Remove Elements from Company:
    void removePlane(string LPlate);
    void removeAirport(string name, string city);
    void removeFlight (int number);
    void removePassenger(string name);

    //Check Elements:
    bool airportExists(string name);
    bool flightExists(int num);
    bool flightIsAssigned(int num);
    bool planeExists(string LPlate);

    //Filter Vectors:
    vector<Flight> flightsByOrigin(string name);
    vector<Flight> flightsByDestination(string name);
    vector<Plane> operationalPlanes();
    vector<Plane> planesByAirport(string name, string city);

    //Other
    bool isFull(Flight flight, Plane plane); //Returns true if the size of flight.passengers is equal to plane.max_ocupation
    int emptySeats(Flight flight, Plane plane); //Returns the number of empty seats in a flight
    Plane getPlaneForFlight(int num);
};


#endif //PROJECTAED_COMPANY_H
