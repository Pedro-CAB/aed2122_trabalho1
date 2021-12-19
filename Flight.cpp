//
// Created by Utilizador on 26/11/2021.
//
#include "Flight.h"

Flight::Flight() : car(LuggageCar(0, 0, 0)){
    number = -1;
    departureT = "NULL_TIME";
    arrivalT = "NULL_TIME";
    date = "NULL_DATE";
    origin = Airport();
    destination = Airport();
    passengers = {};
    car = LuggageCar(0,0,0);
}

Flight::Flight(int number, string arrivalT, string departureT, string date, Airport origin, Airport destination) : car(LuggageCar(origin.getCar().getC(), origin.getCar().getN(), origin.getCar().getM())){
    this->number = number,
            this->departureT =departureT;
    this->arrivalT = arrivalT;
    this->date = date;
    this->origin = origin;
    this->destination = destination;
    this->car = origin.getCar();
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

string Flight::getArrivalT() {
    return arrivalT;
}

string Flight::getDepartureT() {
    return departureT;
}

list<Passenger> Flight::getPassengers() {
    return passengers;
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
    return (number==f.number);
}

bool Flight::operator<(const Flight &f) const {
    if (this->date != f.date)
        return this->date < f.date;
    else
        return this->departureT <= f.departureT;
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
void Flight::addPassenger(Passenger p) {
    passengers.push_back(p);
    int lug = p.getLuggage();
    bool result;
    while (lug>0){
        result  = car.addLuggage();
        lug--;
    }
}