//
// Created by Utilizador on 27/11/2021.
//

#ifndef PROJECTAED_AIRPORT_H
#define PROJECTAED_AIRPORT_H

#include <string>
#include "BST.h"
#include "TTransportL.h"
#include "LuggageCar.h"
#include <vector>
#include <algorithm>

using namespace std;

class Airport{
public:
    string name,city;
    BST<TTLocation> locations;
    LuggageCar car;
    Airport();
    Airport(string& airportName, string& cityName, int& c, int& n, int& m);

    //Getters:
    string getName();
    string getCity();
    BST<TTLocation> getLocations();
    LuggageCar getCar();

    //Setters:
    void setName(string& newName);
    void setLocations(BST<TTLocation>& locations);
    void setCar(int& c, int& n, int& m);
    void setCity(string& city);

    //Edit:
    void addLocation(const TTLocation& location);
    bool operator ==(const Airport &a) const;
};


#endif //PROJECTAED_AIRPORT_H