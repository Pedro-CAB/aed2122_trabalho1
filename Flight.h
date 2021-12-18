//
// Created by Utilizador on 26/11/2021.
//


#ifndef PROJECTAED_FLIGHT_H
#define PROJECTAED_FLIGHT_H

#include <string>
#include <list>
#include "Passenger.h"
#include "Airport.h"

using namespace std;

class Flight{
public:
    int number;
    string date, arrivalT, departureT;
    Airport origin, destination;
    list<Passenger> passengers;
    LuggageCar car;
    Flight();
    Flight (int number, string arrivalT,string departureT, string date, Airport origin, Airport destination);

    //Getters:
    int getNumber();
    string getDate();
    Airport getOrigin();
    Airport getDestination();
    string getArrivalT();
    string getDepartureT();
    list<Passenger> getPassengers();


    //Setters:
    void setNumber(int number);
    void setDate(string date);
    void setOrigin(Airport origin);
    void setDestination(Airport destination);

    //Others:
    bool operator == (const Flight & f) const;
    bool operator < (const Flight& f) const;
    bool isPassengerIn(Passenger p);
    void addPassenger(Passenger p);
};

#endif //PROJECTAED_FLIGHT_H