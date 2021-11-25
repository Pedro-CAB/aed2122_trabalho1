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


#endif //UNTITLED1_TICKET_H
