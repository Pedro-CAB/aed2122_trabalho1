//
// Created by Utilizador on 27/11/2021.
//

#include "Plane.h"

Plane::Plane(string LPlate, int ocupation){
    this->LPlate= LPlate;
    max_ocupation = ocupation;
    to_do = {}, done={};
    queue<Flight> flightPlan = {};
}

//Getters:
string Plane::getLPlate() {return LPlate;}
int Plane::getMaxOccupation() {return max_ocupation;}
queue<Service> Plane::getDone() {return done;}
queue<Service> Plane::getToDo() {return to_do;}


//Setters:
void Plane::setLPlate(string newLPlate) {LPlate=newLPlate;}
void Plane::setDone(queue<string> q) {}         //incomplete
void Plane::setToDo(queue<string> q) {}         //incomplete
void Plane::setMaxOc(int num) {max_ocupation=num;}

//Edit:
/**
 * Acrescenta uma tarefa nova a ser realizada
 * @param a tarefa a acrescentar
 */
void Plane::addTask(Service a){
    to_do.push(a);
}
/**
 * Passa n tarefas da fila de tarefas a realizar para a fila de tarefas realizadas
 * @param n número de tarefas a realizar
 */
void Plane::doNextNTasks(int n){
    for(n;n>0;n++){
        done.push(to_do.front());
        to_do.pop();
    }
}
/**
 * Verifica se o avião tem voos planeados para o futuro
 * @return true se tiver pelo menos um voo no seu plano ou false se ão tiver nenhum
 */
bool Plane::hasFlights() {return flightPlan.size()>0;}
/**
 * Devolve o próximo voo que o avião tem no seu plano
 * @return Próximo Voo
 */
Flight Plane::nextFlight() {
    return (flightPlan.front());
}

bool Plane::operator==(Plane p) const {
    return (LPlate == p.LPlate);
}