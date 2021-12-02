#include "TTransportL.h"

TTLocation::TTLocation(){
    name = "NULLNAME";
    type = "NULLTYPE";
    distance = -1;
    vector<string> emptyVector;
    schedule = emptyVector;
};

TTLocation::TTLocation(string name, string type, float distance, vector<string>& schedule) {
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

float TTLocation::getDistance() {
    return distance;
}

vector<string> TTLocation::getSchedule() {
    return schedule;
}
