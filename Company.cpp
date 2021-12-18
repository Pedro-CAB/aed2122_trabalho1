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

void Company::addPassenger(Passenger p) {passengers.push_back(p);}

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
/**
 * Retorna todos os voos do mesmo aeroporto de origem
 * @param name Nome do Aeroporto
 * @param city Cidade do Aeroporto
 * @return
 */
vector<Flight> Company::flightsByOrigin(string name) {
    vector<Flight> filtered = {};
    for (auto flight : flights){
        if (flight.getOrigin().getName() == name){
            filtered.push_back(flight);
        }
    }
    return filtered;
}
/**
 * Retorna um vetor de todos os voos com um mesmo aeroporto de destino
 * @param name Nome do Aeroporto
 * @param city Cidade do Aeroporto
 * @return
 */
vector<Flight> Company::flightsByDestination(string name) {
    vector<Flight> filtered = {};
    for (auto flight : flights){
        if (flight.getDestination().getName() == name){
            filtered.push_back(flight);
        }
    }
    return filtered;
}
/**
 * Retorna todos os aviões que estão num determinado aeroporto
 * @param name Nome do Aeroporto
 * @param city Cidade do Aeroporto
 * @return
 */
vector<Plane> Company::planesByAirport(string name, string city) {
    vector<Plane> filtered = {};
    for (auto plane : planes){
        if (plane.getFlightPlan().front().getOrigin().getName() == name && plane.getFlightPlan().front().getOrigin().getCity() == city){
            filtered.push_back(plane);
        }
    }
    return filtered;
}
/**
 * Retorna um vetor com os aviões operacionais
 * @return
 */
vector<Plane> Company::operationalPlanes() {
    vector<Plane> filtered = {};
    for(auto plane : planes){
        if (plane.getFlightPlan().size()>0){
            filtered.push_back(plane);
        }
    }
    return filtered;
}

Plane Company::getPLane(int flightN) {
    for (auto plane: planes) {
        queue<Flight> flightPlan = plane.getFlightPlan();
        while (!flightPlan.empty()) {
            if (flightPlan.front().getNumber() == flightN)
                return plane;
            else
                flightPlan.pop();
        }
    }
    throw "flightN not in planes!";
}

bool Company::isFull(Flight flight, Plane plane) {
    if (flight.passengers.size() == plane.max_ocupation)
        return true;
    else
        return false;
}

int Company::emptySeats(Flight flight, Plane plane) {
    return plane.max_ocupation - flight.passengers.size();
}

bool Company::airportExists(string name) {
    for (auto airport : airports){
        if(airport.getName()==name)
            return true;
    }
    return false;
}