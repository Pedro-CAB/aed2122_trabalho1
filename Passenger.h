//
// Created by Utilizador on 27/11/2021.
//

#ifndef PROJECTAED_PASSENGER_H
#define PROJECTAED_PASSENGER_H

#include <string>
#include "Ticket.h"
#include "Flight.h"

using namespace std;

class Passenger {
public:
    string name;
    Ticket ticket;
    Passenger(Ticket ticket);
    Passenger(string name, Ticket ticket);
    //Getters:
    string getName();
    Ticket getTicket();
    Flight getFlight();
    bool getLuggage();
};

#endif //PROJECTAED_PASSENGER_H