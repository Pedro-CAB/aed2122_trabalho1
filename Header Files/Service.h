#ifndef PROJECTAED_SERVICE_H
#define PROJECTAED_SERVICE_H

#endif //PROJECTAED_SERVICE_H

#include <string>

using namespace std;

class Service{
public:
    string type, date, employee;
    Service();
    Service(string type, string date, string employee);
    //Getters:
    string getType(), getDate(), getEmployee();
};
