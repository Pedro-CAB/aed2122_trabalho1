//
// Created by Utilizador on 14/12/2021.
//

#ifndef PROJECTAED_TTRANSPORTL_H
#define PROJECTAED_TTRANSPORTL_H

#include <string>
#include <vector>

using namespace std;

class TTLocation {
public:
    string name, type;
    float distance;
    vector<string> schedule;

    TTLocation();
    TTLocation(string name, string type, float distance, vector<string> &schedule);

    string getName(), getType();
    float getDistance();
    vector<string> getSchedule();
    bool operator < (const TTLocation &t1) const;
    bool operator == (const TTLocation &t1) const;
};

#endif //PROJECTAED_TTRANSPORTL_H
