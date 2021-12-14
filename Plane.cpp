#include "Plane.h"

Plane::Plane(string LPlate){
    LPlate_str= LPlate;
    letter = LPlate.substr(1,1);
    n = 0, c = 0, max_ocupation = 0, taken_seats = 0;
    to_do = {}, done={}, passengers ={};
}
//Getters:
string Plane::getLPlate() {return LPlate_str;}
string Plane::getLPlateLetter() {return letter;}
int Plane::getN(){return n;}
int Plane::getC() {return c;}
int Plane::getMaxOccupation() {return max_ocupation;}
int Plane::getTaken_Seats() {return taken_seats;}
int Plane::getVacantSeats() {return max_ocupation-taken_seats;}
queue<Service> Plane::getDone() {return done;}
queue<Service> Plane::getToDo() {return to_do;}
//Setters:
void Plane::setLPlate(string newLPlate) {LPlate_str=newLPlate;}
void Plane::setC(int c) {this->c=c;}
void Plane::setN(int n) {this->n=n;}
void Plane::setDone(queue<string> q) {}         //incomplete
void Plane::setToDo(queue<string> q) {}         //incomplete
void Plane::setMaxOc(int num) {max_ocupation=num;}
void Plane::setTakenS(int num) {taken_seats=num;}
//Edit:
void Plane::addPassenger(Passenger a){
    passengers.push_back(a);
}
void Plane::addTask(Service a){
    to_do.push(a);
}
void Plane::doNextNTasks(int n){
    for(n;n>0;n++){
        done.push(to_do.front());
        to_do.pop();
    }
}