#ifndef PROJECTAED_TTRANSPORTL_H
#define PROJECTAED_TTRANSPORTL_H

#include <string>
#include <vector>

using namespace std;

class TTLocation{
public:
    string name, type;
    float distance;
    vector<string> schedule;

    TTLocation();
    TTLocation(string name, string type, float distance, vector<string>& schedule);
    //Getters:
    string getName(), getType();
    float getDistance();
    vector<string> getSchedule();
};
#endif //PROJECTAED_TTRANSPORTL_H