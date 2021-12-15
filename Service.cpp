#include "Service.h"

Service::Service() {
    type = "NULL_TYPE";
    date = "NULL_DATE";
    employee = "NULL_EMPLOYEE";
}
/**
 * Constrói um novo Serviço/Tarefa
 * @param type Tipo do Serviço/Tarefa
 * @param date Data em que o Serviço será realizado
 * @param employee Empregado responsável pela realização do serviço
 */
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