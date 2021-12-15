#include "Passenger.h"

Passenger::Passenger(Ticket ticket){
    this->ticket = ticket;
    this->name = "";
}
/**
 *
 * @param name Nome do Passageiro
 * @param ticket Bilhete associado (objeto Ticket)
 */
Passenger::Passenger(string name, Ticket ticket){
    this->ticket=ticket;
    this->name = name;
}
//Getters:
string Passenger::getName(){return name;}
Ticket Passenger::getTicket(){return ticket;}
Flight Passenger::getFlight(){return ticket.getFlight();}
bool getLuggage();