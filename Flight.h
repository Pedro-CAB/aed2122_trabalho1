//
// Created by Utilizador on 26/11/2021.
//


#ifndef PROJECTAED_FLIGHT_H
#define PROJECTAED_FLIGHT_H

#include <string>
#include <list>
#include "Passenger.h"

using namespace std;

class Flight{
public:
    int number;
    string date, origin, destination, arrivalT, departureT;
    list<Passenger> passengers;
    Flight();
    Flight (int number, string arrivalT,string departureT, string date, string origin, string destination);

    //Getters:
    int getNumber();
    string getDate();
    string getOrigin();
    string getDestination();

    //Setters:
    void setNumber(int number);
    void setDate(string date);
    void setOrigin(string origin);
    void setDestination(string destination);

    //Others:
    bool operator == (const Flight & f) const;
    bool isPassengerIn(Passenger p);
};

#endif //PROJECTAED_FLIGHT_H