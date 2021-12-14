#include "Airport.h"

Airport::Airport(string& airportName) {
    this->name = airportName;
    TTLocation dummy();
    BST<TTLocation> emptyBST(dummy);
    this->locations = emptyBST;
}

string Airport::getName() {
    return name;
}

BST<TTLocation> Airport::getLocations() {
    return locations;
}

void Airport::setName(string& newName) {
    this->name = newName;
}

void Airport::setLocations(BST<TTLocation> &locations) {
    this->locations = locations;
}

void Airport::addLocation(const TTLocation& location) {
    locations.insert(location);
}