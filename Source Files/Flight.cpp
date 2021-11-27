#include "Flight.h"

Flight::Flight(int number, float duration, string date, string origin, string destination){
    this->number = number,
            this->duration = duration;
    this->date = date;
    this->origin = origin;
    this->destination = destination;
}

int Flight::getNumber(){
    return number;
}

float Flight::getDuration(){
    return duration;
}

string Flight::getDate(){
    return date;
}

string Flight::getOrigin(){
    return origin;
}

string Flight::getDestination(){
    return destination;
}

void Flight::setNumber(int number){
    this->number = number;
}

void Flight::setDuration(float duration){
    this->number = number;
}

void Flight::setDate(string date){
    this->date = date;
}

void Flight::setOrigin(string origin){
    this->origin = origin;
}

void Flight::setDestination(string destination){
    this->destination = destination;
}
