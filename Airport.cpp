//
// Created by Utilizador on 27/11/2021.
//

#include "Airport.h"

Airport::Airport() : locations(TTLocation()){
    name = "NULL_NAME";
    city = "NULL_CITYNAME";
}
Airport::Airport(string& airportName, string& cityName):locations(TTLocation()) {
    name = airportName;
    city = cityName;
}
string Airport::getName() {return name;}
BST<TTLocation> Airport::getLocations() {return locations;}

string Airport::getCity() {return city;}

void Airport::setName(string& newName) {name = newName;}
void Airport::setLocations(BST<TTLocation> &locations) {this->locations = locations;}
/**
 * Adiciona um Local de Transporte à BST Locations
 * @param location Local de Transporte a adicionar (objeto do tipo TTLocation)
 */
void Airport::addLocation(const TTLocation& location) {locations.insert(location);}

bool Airport::operator==(const Airport a) {return name == a.name && city == a.city && locations == a.locations;}