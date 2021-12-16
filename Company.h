//
// Created by Aulas FEUP on 15/12/2021.
//

#ifndef PROJECTAED_COMPANY_H
#define PROJECTAED_COMPANY_H
#include <vector>
#include "Airport.h"

class Company {
public:
    vector<Airport> airports;
    vector<Plane> planes;
    Company();

    vector<Airport> getAirports();
    vector<Plane> getPlanes();

    void setAirports(vector<Airport> a);
    void setPlanes(vector<Plane> p);

    void addAirport(Airport a);
    void addPlane (Plane p);
};



#endif //PROJECTAED_COMPANY_H
