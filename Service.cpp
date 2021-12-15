//
// Created by Utilizador on 27/11/2021.
//

#include "Service.h"

Service::Service() {
    type = "NULL_TYPE";
    date = "NULL_DATE";
    employee = "NULL_EMPLOYEE";
}

Service::Service(string type, string date, string employee) {
    this->type = type;
    this->date = date;
    this->employee = employee;
}

string Service::getType() {
    return type;
}

string Service::getDate() {
    return date;
}

string Service::getEmployee() {
    return employee;
}
