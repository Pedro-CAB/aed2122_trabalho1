//
// Created by Utilizador on 27/11/2021.
//

#ifndef PROJECTAED_AIRPORT_H
#define PROJECTAED_AIRPORT_H

#include <string>
#include "BST.h"
#include "TTransportL.h"
#include "Flight.h"
#include "Plane.h"
#include <vector>
#include <algorithm>

using namespace std;

class Airport{
public:
    string name;
    BST<TTLocation> locations;
    Airport(string& airportName);
    vector<Flight> departures, arrivals;
    vector<Plane> planes;

    //Getters:
    string getName();
    BST<TTLocation> getLocations();
    vector<Flight> getArrivals();
    vector<Flight> getDepartures();
    vector<Plane> getPlanes();

    //Setters:
    void setName(string& newName);
    void setLocations(BST<TTLocation>& locations);
    void setArrivals(vector<Flight> a);
    void setDepartures(vector<Flight> d);
    void setPlanes(vector<Plane> p);

    //Edit:
    void addLocation(const TTLocation& location);
    void addDeparture(const Flight d);
    void addArrival(const Flight a);
    void addPlane(const Plane p);

    void removeDeparture (const Flight d);
    void removeArrival (const Flight a);
    void removePlane (const Plane p);

    bool operator < (const Airport a);
};


#endif //PROJECTAED_AIRPORT_H