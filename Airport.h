#ifndef PROJECTAED_AIRPORT_H
#define PROJECTAED_AIRPORT_H

#include <string>
#include "BST.h"
#include "TTransportL.h"

using namespace std;

class Airport{
public:
    string name;
    BST<TTLocation> locations;
    Airport(string& airportName, BST<TTLocation> locations);

    //Getters:
    string getName();
    BST<TTLocation> getLocations();
    //Setters:
    void setName(string& newName);
    void setLocations(BST<TTLocation>& locations);
    //Edit:
    void addLocation(const TTLocation& location);
};
#endif //PROJECTAED_AIRPORT_H