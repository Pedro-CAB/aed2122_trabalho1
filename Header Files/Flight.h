#ifndef UNTITLED1_FLIGHT_H
#define UNTITLED1_FLIGHT_H

#endif //UNTITLED1_FLIGHT_H

#include <string>
using namespace std;

class Flight{
public:
    int number;
    float duration;
    string date, origin, destination;
    Flight (int number, float duration, string date, string origin, string destination);
    int getNumber();
    float getDuration();
    string getDate();
    string getOrigin();
    string getDestination();
    void setNumber(int number);
    void setDuration(float duration);
    void setDate(string date);
    void setOrigin(string origin);
    void setDestination(string destination);
};
