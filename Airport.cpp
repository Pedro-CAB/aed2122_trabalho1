//
// Created by Utilizador on 27/11/2021.
//

#include "Airport.h"

Airport::Airport(string& airportName):locations(TTLocation()) {
    this->name = airportName;
    this->flights = {};
}
string Airport::getName() {
    return name;
}

BST<TTLocation> Airport::getLocations() {
    return locations;
}
vector<Flight> Airport::getFlights(){
    return flights;
}
void Airport::setName(string& newName) {
    this->name = newName;
}

void Airport::setLocations(BST<TTLocation> &locations) {
    this->locations = locations;
}
/**
 * Adiciona um Local de Transporte à BST Locations
 * @param location Local de Transporte a adicionar (objeto do tipo TTLocation)
 */
void Airport::addLocation(const TTLocation& location) {
    locations.insert(location);
}

bool Airport::operator<(const Airport a) {
    return name < a.name;
}

void Airport::addFlight(const Flight flight){
    flights.push_back(flight);
}