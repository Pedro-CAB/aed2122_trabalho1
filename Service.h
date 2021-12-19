//
// Created by Utilizador on 27/11/2021.
//

#ifndef PROJECTAED_SERVICE_H
#define PROJECTAED_SERVICE_H

#include <string>

using namespace std;

class Service{
public:
    string type, date, employee;
    Service();
    Service(string type, string date, string employee);
    //Getters:
    string getType(), getDate(), getEmployee();
    bool operator<(const Service& s) const;
};

#endif //PROJECTAED_SERVICE_H