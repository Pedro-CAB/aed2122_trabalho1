#include "Flight.h"

Flight::Flight(int number, float duration, string date, string origin, string destination){
    this->number = number,
    this->duration = duration;
    this->date = date;
    this->origin = origin;
    this->destination = destination;
}

int Flight::getNumberFlight(){
    return number;
}

float Flight::getDurationFlight(){
    return duration;
}

string Flight::getDateFlight(){
    return date;
}

string Flight::getOrigin(){
    return origin;
}

string Flight::getDestination(){
    return destination;
}

void Flight::setNumberFlight(int number){
    this->number = number;
}

void Flight::setDurationFlight(float duration){
    this->number = number;
}

void Flight::setDateFlight(string date){
    this->date = date;
}

void Flight::setOrigin(string origin){
    this->origin = origin;
}

void Flight::setDestination(string destination){
    this->destination = destination;
}
