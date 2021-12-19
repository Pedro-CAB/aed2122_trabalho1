//
// Created by Utilizador on 14/12/2021.
//

#include "TTransportL.h"

TTLocation::TTLocation(){
    name = "NULLNAME";
    type = "NULLTYPE";
    distance = -1;
    vector<string> emptyVector;
    schedule = emptyVector;
};

TTLocation::TTLocation(string name, string type, int distance, vector<string>& schedule) {
    this->name = name;
    this->type = type;
    this->distance = distance;
    this->schedule = schedule;
}

string TTLocation::getName() {
    return name;
}

string TTLocation::getType() {
    return type;
}

string TTLocation::getDistance() {
    return distance;
}

vector<string> TTLocation::getSchedule() {
    return schedule;
}
bool TTLocation::operator < (const TTLocation &t1) const {
    return (distance < t1.distance);
}

bool TTLocation::operator==(const TTLocation &t1) const {
    return (name == t1.name && type == t1.type);
}
