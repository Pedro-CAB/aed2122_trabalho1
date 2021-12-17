//
// Created by Utilizador on 27/11/2021.
//

#include "Airport.h"

Airport::Airport() : locations(TTLocation()), car(LuggageCar(0, 0, 0)) {
    name = "NULL_NAME";
    city = "NULL_CITYNAME";
}
Airport::Airport(string& airportName, string& cityName, int& c, int& n, int& m):locations(TTLocation()), car(LuggageCar(c, n, m))  {
    name = airportName;
    city = cityName;
}
string Airport::getName() {return name;}
BST<TTLocation> Airport::getLocations() {return locations;}
LuggageCar Airport::getCar() {return car;}
string Airport::getCity() {return city;}

void Airport::setName(string& newName) {name = newName;}
void Airport::setLocations(BST<TTLocation> &locations) {this->locations = locations;}
void Airport::setCar(int& c, int& n, int& m) {this->car = LuggageCar(c, n, m);}

/**
 * Adiciona um Local de Transporte à BST Locations
 * @param location Local de Transporte a adicionar (objeto do tipo TTLocation)
 */
void Airport::addLocation(const TTLocation& location) {locations.insert(location);}
bool Airport::operator == (const Airport &a) const{
    return (name == a.name && city == a.city);
}