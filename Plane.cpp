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
/**
 * Adiciona o passageiro a à lista passengers e retorna true se a operação for bem sucedida
 * @param a Passageiro a inserir
 */
bool Plane::addPassenger(Passenger a){
    if (taken_seats == max_ocupation){
        return false;
    }
    passengers.push_back(a);
    return true;
}
/**
 * Adiciona a Tarefa a à fila de tarefas a realizar
 * @param a Tarefa a inserir
 */
void Plane::addTask(Service a){
    to_do.push(a);
}
/**
 * Remove as próximas n tarefas da fila de tarefas a realizar e insere-as na fila de tarefas efetuadas
 * @param n Número de tarefas a realizar
 */
void Plane::doNextNTasks(int n){
    for(n;n>0;n++){
        done.push(to_do.front());
        to_do.pop();
    }
}