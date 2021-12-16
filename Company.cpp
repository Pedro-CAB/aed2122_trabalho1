//
// Created by Aulas FEUP on 15/12/2021.
//

#include "Company.h"
Company::Company(){
    airports = {};
    planes = {};
}

vector<Airport> Company::getAirports() {return airports;}
vector<Plane> Company::getPlanes() {return planes;}

void Company::setAirports(vector<Airport> a) {airports = a;}
void Company::setPlanes(vector<Plane> p) {planes = p;}

void Company::addAirport(Airport a) {airports.push_back(a);}
void Company::addPlane(Plane p) {planes.push_back(p);}
