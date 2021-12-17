//
// Created by Utilizador on 27/11/2021.
//

#include "Ticket.h"

Ticket::Ticket(){
    flight = Flight();
    AutoLug = false;
}

Ticket::Ticket(Flight flight){
    this->flight = flight;
    AutoLug = false;
}
//Getters:
Flight Ticket::getFlight(){return flight;};
bool Ticket::getAutoLug(){return AutoLug;};
//Setters:
void Ticket::setAutoLug(bool state){AutoLug = state;};
