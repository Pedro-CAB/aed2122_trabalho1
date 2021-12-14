
#include <string>
#include <list>
#include <queue>
#include "Service.h"
#include "Passenger.h"
#ifndef PROJECTAED_PLANE_H
#define PROJECTAED_PLANE_H

#include <string>
#include <list>
#include <queue>
#include "Service.h"
#include "Passenger.h"

using namespace std;

class Plane {
public:
    Plane(string LPlate);
    string LPlate_str, letter;
    int n, c, max_ocupation, taken_seats;
    queue<Service> to_do, done;
    list<Passenger> passengers;

    //Getters:
    string getLPlate(),getLPlateLetter();
    int getLPlateNumber(), getN(), getC(), getMaxOccupation(), getTaken_Seats(), getVacantSeats();
    queue<Service> getToDo(), getDone();
    //Setters:
    void setLPlate(string newLPlate),setN(int n),
            setC(int c), setMaxOc(int num),setTakenS(int num),
            setToDo(queue<string> q), setDone(queue<string> q);
    //Edit:
    void addPassenger(Passenger a);
    void addTask(Service a);
    void doNextNTasks(int n);
};
#endif //PROJECTAED_PLANE_H