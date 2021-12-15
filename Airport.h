#ifndef PROJECTAED_AIRPORT_H
#define PROJECTAED_AIRPORT_H

#include <string>
#include "BST.h"
#include "TTransportL.h"
#include "Flight.h"
#include <vector>

using namespace std;

class Airport{
public:
    string name;
    BST<TTLocation> locations;
    Airport(string& airportName, BST<TTLocation> locations);
    vector<Flight> flights;

    //Getters:
    string getName();
    BST<TTLocation> getLocations();
    vector<Flight> getFlights();
    //Setters:
    void setName(string& newName);
    void setLocations(BST<TTLocation>& locations);
    //Edit:
    void addLocation(const TTLocation& location);
    void addFlight(const Flight flight);
};
#endif //PROJECTAED_AIRPORT_H