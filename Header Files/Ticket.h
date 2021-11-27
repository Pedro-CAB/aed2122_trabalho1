#ifndef PROJECTAED_TICKET_H
#define PROJECTAED_TICKET_H

#endif //PROJECTAED_TICKET_H

class Ticket {
public:
    Flight flight;
    bool AutoLug;
    Ticket();
    Ticket(Flight flight);
    //Getters:
    Flight getFlight();
    bool getAutoLug();
    //Setters:
    void setAutoLug(bool state);
};
