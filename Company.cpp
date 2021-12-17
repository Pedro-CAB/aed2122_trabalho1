//
// Created by Aulas FEUP on 16/12/2021.
//

#include "Company.h"

vector<Plane> Company::getPlanes() {return planes;}

vector<Airport> Company::getAirports() {return airports;}

vector<Flight> Company::getFlights() {return flights;}

vector<Passenger> Company::getPassengers() {return passengers;}


void Company::addPlane(Plane p) {planes.push_back(p);}

void Company::addAirport(Airport a) {airports.push_back(a);}

void Company::addFlight(Flight f) {flights.push_back(f);}

void Company::addPassengers(Passenger p) {passengers.push_back(p);}

void Company::removeAirport(string name, string city) {
    for (auto airport : airports){
        if (airport.getName()==name && airport.getCity()==city){
            remove(airports.begin(), airports.end(), airport);
            break;
        }
    }
}

void Company::removeFlight(int number) {
    for (auto flight : flights){
        if (flight.getNumber()==number){
            remove(flights.begin(), flights.end(), flight);
            break;
        }
    }
}

void Company::removePassenger(string name) {
    for (auto passenger : passengers){
        if (passenger.getName()==name){
            remove(passengers.begin(), passengers.end(), passenger);
            break;
        }
    }
}
void Company::removePlane(string LPlate) {
    for (auto plane : planes){
        if (plane.getLPlate()==LPlate){
            remove(planes.begin(), planes.end(), plane);
            break;
        }
    }
}