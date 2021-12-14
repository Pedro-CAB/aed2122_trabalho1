#include "Passenger.h"

Passenger::Passenger(Ticket ticket){
    this->ticket = ticket;
    this->name = "";
}
Passenger::Passenger(string name, Ticket ticket){
    this->ticket=ticket;
    this->name = name;
}
//Getters:
string Passenger::getName(){return name;}
Ticket Passenger::getTicket(){return ticket;}
Flight Passenger::getFlight(){};
bool getLuggage();
