//
// Created by Utilizador on 26/11/2021.
//
#include "Flight.h"

Flight::Flight(){
    number = -1;
    departureT = "NULL_TIME";
    arrivalT = "NULL_TIME";
    date = "NULL_DATE";
    origin = Airport();
    destination = Airport();
    passengers = {};
}

Flight::Flight(int number, string arrivalT, string departureT, string date, Airport origin, Airport destination){
    this->number = number,
    this->departureT =departureT;
    this->arrivalT = arrivalT;
    this->date = date;
    this->origin = origin;
    this->destination = destination;
}

int Flight::getNumber(){
    return number;
}

string Flight::getDate(){
    return date;
}

Airport Flight::getOrigin(){
    return origin;
}

Airport Flight::getDestination(){
    return destination;
}

void Flight::setNumber(int number){
    this->number = number;
}

void Flight::setDate(string date){
    this->date = date;
}

void Flight::setOrigin(Airport origin){
    this->origin = origin;
}

void Flight::setDestination(Airport destination){
    this->destination = destination;
}

bool Flight::operator==(const Flight &f) const {
    return (number==f.number && arrivalT == f.arrivalT && departureT == f.departureT && date == f.date && origin == f.origin && destination == f.destination && passengers == f.passengers);
}
/**
 * Verifica se um passageiro está num voo
 * @param p Passageiro a procurar
 * @return true se estiver no voo, false se não estiver
 */
bool Flight::isPassengerIn(Passenger p) {
    for (auto passenger : passengers){
        if (passenger == p){
            return true;
        }
    }
    return false;
}