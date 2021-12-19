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

queue<Flight> Plane::getFlightPlan() {return flightPlan;};


//Setters:
void Plane::setLPlate(string newLPlate) {LPlate=newLPlate;}
void Plane::setMaxOc(int num) {max_ocupation=num;}

//Edit:
/**
 * Acrescenta uma tarefa nova a ser realizada
 * @param a tarefa a acrescentar
 */
void Plane::addTask_to_do(Service a){
    queue<Service> auxTo_do;
    while (to_do.front() < a && !to_do.empty()) { auxTo_do.push(to_do.front());
        to_do.pop();
    } auxTo_do.push(a);
    while(!to_do.empty()){ auxTo_do.push(to_do.front());
        to_do.pop();
    }
    to_do = auxTo_do;
}

void Plane::addTask_done(Service a){
    queue<Service> auxDone;
    while (done.front() < a && !done.empty()) {
        auxDone.push(done.front());
        done.pop();
    }
    auxDone.push(a);
    while(!done.empty()){
        auxDone.push(done.front());
        done.pop();
    }
    done = auxDone;
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
void Plane::addFlight(Flight f) {
    queue<Flight> auxPlan;
    while (flightPlan.front() < f && !flightPlan.empty()) {
        auxPlan.push(flightPlan.front());
        flightPlan.pop();
    }
    auxPlan.push(f);
    while(!flightPlan.empty()){
        auxPlan.push(flightPlan.front());
        flightPlan.pop();
    }
    flightPlan = auxPlan;
}

bool Plane::operator==(Plane p) const {
    return (LPlate == p.LPlate);
}