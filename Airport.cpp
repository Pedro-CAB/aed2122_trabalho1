//
// Created by Utilizador on 27/11/2021.
//

#include "Airport.h"

Airport::Airport(string& airportName):locations(TTLocation()) {
    name = airportName;
    departures = {};
    arrivals = {};
    planes = {};
}
string Airport::getName() {return name;}
BST<TTLocation> Airport::getLocations() {return locations;}
vector<Flight> Airport::getArrivals() {return arrivals;}
vector<Flight> Airport::getDepartures() {return departures;}
vector<Plane> Airport::getPlanes() {return planes;}

void Airport::setName(string& newName) {name = newName;}
void Airport::setLocations(BST<TTLocation> &locations) {this->locations = locations;}
void Airport::setArrivals(vector<Flight> a) {arrivals=a;}
void Airport::setDepartures(vector<Flight> d) {departures = d;}
void Airport::setPlanes(vector<Plane> p) {planes = p;}
/**
 * Adiciona um Local de Transporte à BST Locations
 * @param location Local de Transporte a adicionar (objeto do tipo TTLocation)
 */
void Airport::addLocation(const TTLocation& location) {locations.insert(location);}
void Airport::addArrival(const Flight a) {arrivals.push_back(a);}
void Airport::addDeparture(const Flight d) {departures.push_back(d);}
void Airport::addPlane(const Plane p) {planes.push_back(p);}

bool Airport::operator<(const Airport a) {return name < a.name;}