#include "Ticket.h"

Ticket::Ticket(){
    flight = Flight();
    AutoLug = false;
}
/**
 * Constrói um novo Bilhete
 * @param flight Voo associado
 */
Ticket::Ticket(Flight flight){
    this->flight = flight;
    AutoLug = false;
}
//Getters:
Flight Ticket::getFlight(){return flight;};
bool Ticket::getAutoLug(){return AutoLug;}
//Setters:
/**
 * Adiciona/Remove bagagem automática do bilhete
 * @param state true se solicitou bagagem automática; false se não solicitou
 */
void Ticket::setAutoLug(bool state){AutoLug=state;}