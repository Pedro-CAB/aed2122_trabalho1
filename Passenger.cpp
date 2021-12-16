//
// Created by Utilizador on 27/11/2021.
//

#include "Passenger.h"

Passenger::Passenger(){
    this->name = "";
    autoLug = 0;
}
Passenger::Passenger(string name, int autoLug){
    this->name = name;
    this->autoLug = autoLug;
}
//Getters:
string Passenger::getName(){return name;}
int Passenger::getLuggage(){return autoLug;}

bool Passenger::operator==(Passenger p2) const {
    return (name == p2.name && autoLug == p2.autoLug);
}