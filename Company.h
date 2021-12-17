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

    //Filter Vectors:
    vector<Flight> flightsByOrigin(string name, string city);
    vector<Flight> flightsByDestination(string name, string city);
    vector<Plane> planesByAirport(string name, string city);

};


#endif //PROJECTAED_COMPANY_H
