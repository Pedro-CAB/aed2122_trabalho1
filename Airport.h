//
// Created by Utilizador on 27/11/2021.
//

#ifndef PROJECTAED_AIRPORT_H
#define PROJECTAED_AIRPORT_H

#include <string>
#include "BST.h"
#include "TTransportL.h"
#include <vector>
#include <algorithm>

using namespace std;

class Airport{
public:
    string name,city;
    BST<TTLocation> locations;
    Airport();
    Airport(string& airportName, string& cityName);

    //Getters:
    string getName();
    string getCity();
    BST<TTLocation> getLocations();

    //Setters:
    void setName(string& newName);
    void setLocations(BST<TTLocation>& locations);

    //Edit:
    void addLocation(const TTLocation& location);

    bool operator == (const Airport a);
};


#endif //PROJECTAED_AIRPORT_H