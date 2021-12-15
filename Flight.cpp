#include "Flight.h"
/**
 * Constrói um voo vazio
 */
Flight::Flight(){
    number = -1;
    duration = -1;
    date = "NULL_DATE";
    origin = "NULL_ORIGIN";
    destination = "NULL_DESTINATION";
}
/**
 * Constrói um Voo
 * @param number Número do Voo
 * @param duration Duração do Voo em Horas
 * @param date Data do Voo em formato DD-MM-YY
 * @param origin Local de Origem
 * @param destination Local de Destino
 */
Flight::Flight(int number, float duration, string date, string origin, string destination) {
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
string Flight::getSchedule() {
    return schedule;
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
bool Flight::operator<(Flight flight) {
    int h = stoi(schedule.substr(0,2)),m = stoi(schedule.substr(3,2)), h2 = stoi(flight.getSchedule().substr(0,2)), m2 = stoi(flight.getSchedule().substr(3,2));
    if (h != h2){
        return h<h2;
    }
    else{
        return m<m2;
    }
}