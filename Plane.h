//
// Created by Utilizador on 27/11/2021.
//

#ifndef PROJECTAED_PLANE_H
#define PROJECTAED_PLANE_H

#include <string>
#include <list>
#include <queue>
#include "Service.h"
#include "Flight.h"


using namespace std;

class Plane {
public:
    Plane(string LPlate, int ocupation);
    string LPlate;
    int max_ocupation;
    queue<Service> to_do, done;
    queue<Flight> flightPlan;

    //Getters:
    string getLPlate();
    int getN(), getC(), getMaxOccupation();
    queue<Service> getToDo(), getDone();
    queue<Flight> getFlightPlan();

    //Setters:
    void setLPlate(string newLPlate),setN(int n),
            setC(int c), setMaxOc(int num),setTakenS(int num);

    //Edit:
    void addTask_to_do(Service a);
    void addTask_done(Service a);
    void addFlight(Flight f);
    void doNextNTasks(int n);
    bool hasFlights();
    Flight nextFlight();
    bool operator ==(Plane p) const;
};

#endif //PROJECTAED_PLANE_H