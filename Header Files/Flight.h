#ifndef PROJECTAED_FLIGHT_H
#define PROJECTAED_FLIGHT_H

#endif //PROJECTAED_FLIGHT_H

#include <string>
using namespace std;

public class Flight{
public:
    int number_flight;
    float duration_flight;
    string date_flight, origin, destination;
    Flight (int number, float duration, string date, string origin, string destination);
    int getNumberFlight();
    float getFloatDurationFlight();
    string getDateFlight();
    string getOrigin();
    string getDestination();
    void setNumberFlight(int number);
    void setDurationFlight(float duration);
    void setDateFlight(string date);
    void setOrigin(string origin);
    void setDestination(string destination);
};
