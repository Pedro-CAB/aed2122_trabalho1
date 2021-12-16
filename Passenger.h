//
// Created by Utilizador on 27/11/2021.
//

#ifndef PROJECTAED_PASSENGER_H
#define PROJECTAED_PASSENGER_H

#include <string>


using namespace std;

class Passenger {
public:
    string name;
    Passenger();
    Passenger(string name, int autoLug);
    int autoLug;    // 0 se não for bagagem automática, outro valor superior se for, indicando a quantidade de malas

    //Getters:
    string getName();
    int getLuggage();
    bool operator == (Passenger p2) const;
};

#endif //PROJECTAED_PASSENGER_H