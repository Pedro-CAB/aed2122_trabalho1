#include <string>
#include "Ticket.h"
#include "Flight.h"
#ifndef UNTITLED1_PASSENGER_H
#define UNTITLED1_PASSENGER_H

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


#endif //UNTITLED1_PASSENGER_H
