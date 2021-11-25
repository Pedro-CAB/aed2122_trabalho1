#include "Ticket.h"
Ticket::Ticket(Flight flight){
    this->flight = flight;
    AutoLug = false;
}
//Getters:
Flight Ticket::getFlight(){return flight;};
bool getAutoLug();
//Setters:
void setAutoLug(bool state);
