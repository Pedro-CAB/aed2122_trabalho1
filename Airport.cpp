#include "Airport.h"
/**
 * Constrói um Aeroporto
 * @param airportName Nome do Aeroporto
 * @param locations Árvore de Locais de Transporte do Aeroporto
 */
Airport::Airport(string& airportName, BST<TTLocation> locations):locations(TTLocation()) {
    this->name = airportName;
    this->locations = locations;
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

void Airport::addFlight(const Flight flight){
    flights.push_back(flight);
}