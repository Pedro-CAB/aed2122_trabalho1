#include <iostream>
#include <fstream>
#include <sstream>
#include "Company.h"

using namespace std;
void main_menu(Company& company), go_back(Company company);
string sizeRegularizer(string str, int n);



void povoar(Company& company){
    Service s1 = Service("Limpeza", "22-12-2021","Joao Pereira");
    Service s2 = Service("Manutencao", "22-12-2021","Miguel Sousa");
    Service s3 = Service("Vistoria", "22-12-2021","Marta Lima");

    Passenger p1 = Passenger("Carlos Silva",2);
    Passenger p2 = Passenger("Luis Miguel",1);
    Passenger p3 = Passenger("Simao Rodrigues",3);
    Passenger p4 = Passenger("Ana Marques",2);
    Passenger p5 = Passenger("Guilherme Moreira",1);
    Passenger p6 = Passenger("Antonio Marques",3);
    Passenger p7 = Passenger("Jose Nunes",1);
    Passenger p8 = Passenger("Lucia Pereira",3);
    Passenger p9 = Passenger("Carla Ferreira",2);
    Passenger p10 = Passenger("Fernanda Paiva",1);


    vector<string> schedule = {"08:00","22:00"};
    TTLocation t1 = TTLocation("Estacao de Sa Carneiro","Metro",100,schedule);
    TTLocation t2 = TTLocation("Paragem de Sa Carneiro","Autocarro",200,schedule);
    TTLocation t3 = TTLocation("Paragem de Sa Carneiro","Taxi",200,schedule);
    TTLocation t4 = TTLocation("Estacao de Humberto Delgado","Metro",500,schedule);
    TTLocation t5 = TTLocation("Paragem de Humberto Delgado","Autocarro",200,schedule);
    TTLocation t6 = TTLocation("Praca de Humberto Delgado","Taxi",200,schedule);
    TTLocation t7 = TTLocation("Paragem CR7","Autocarro",200,schedule);
    TTLocation t8 = TTLocation("Praca do Funchal","Taxi",200,schedule);
    string name = "Aeroporto Sa Carneiro", city = "Porto";
    int c = 3, n = 3, m = 3;
    Airport a1 = Airport(name,city,c,n,m);
    name = "Aeroporto Humberto Delgado", city = "Lisboa";
    c = 4, n = 3, m = 2;
    Airport a2 = Airport(name,city,c,n,m);
    name = "Aeroporto Cristiano Ronaldo",city="Funchal";
    c = 2, n= 2, m = 5;
    Airport a3 = Airport(name,city,c,n,m);


    Flight f1 = Flight(1,"22:00","20:00","22-12-2021",a1,a2);
    Flight f2 = Flight(2,"12:00","10:00","22-12-2021",a1,a2);
    Flight f3 = Flight(3,"00:30","22:30","22-12-2021",a2,a1);
    Flight f4 = Flight(4,"14:30","12:30","22-12-2021",a2,a1);
    Flight f5 = Flight(5,"00:00","20:00","22-12-2021",a1,a3);
    Flight f6 = Flight(6,"14:00","10:00","22-12-2021",a2,a3);
    Flight f7 = Flight(7,"00:00","20:00","22-12-2021",a3,a1);
    Flight f8 = Flight(8,"14:00","10:00","22-12-2021",a3,a1);

    Plane P1 = Plane("A001",250);
    Plane P2 = Plane("A002",300);
    Plane P3 = Plane("A003",320);
    Plane P4 = Plane("A004",400);
    Plane P5 = Plane("A005",250);
    Plane P6 = Plane("A006",300);
    P1.addTask_to_do(s1), P1.addTask_to_do(s2);
    P2.addTask_to_do(s3), P2.addTask_to_do(s2);
    P3.addTask_to_do(s2), P3.addTask_to_do(s3);
    P4.addTask_to_do(s1), P4.addTask_to_do(s3);
    P5.addTask_to_do(s1);
    P6.addTask_to_do(s1), P6.addTask_to_do(s2),P6.addTask_to_do(s3);
    f1.addPassenger(p1),f1.addPassenger(p2),f1.addPassenger(p3),
            f2.addPassenger(p2),f2.addPassenger(p3),f2.addPassenger(p4),
            f3.addPassenger(p3),f3.addPassenger(p4),f3.addPassenger(p5);
    P1.addFlight(f1),P1.addFlight(f6),P1.addFlight(f8);
    P2.addFlight(f3),P2.addFlight(f1);
    P3.addFlight(f7),P3.addFlight(f2),P3.addFlight(f6);
    company.addFlight(f1),company.addFlight(f2),company.addFlight(f3),company.addFlight(f4),company.addFlight(f5),company.addFlight(f6),company.addFlight(f7),company.addFlight(f8);
    company.addPassenger(p1),company.addPassenger(p2),company.addPassenger(p3),company.addPassenger(p4),company.addPassenger(p5),company.addPassenger(p6),company.addPassenger(p7),company.addPassenger(p8),company.addPassenger(p9),company.addPassenger(p10);
    company.addAirport(a1),company.addAirport(a2),company.addAirport(a3);
    company.addPlane(P1),company.addPlane(P2),company.addPlane(P3),company.addPlane(P4),company.addPlane(P5),company.addPlane(P6);
}
void readAirports(Company &company, string name_file) {

    ifstream i_file_airport;
    i_file_airport.open(name_file);

    if (i_file_airport.is_open()){

        while (!i_file_airport.eof()) {

            // Trata da primeira linha -> separa a o nome da cidade
            string name, city;
            getline(i_file_airport, name, ';'); //cout << "Name: " << name << endl;
            getline(i_file_airport, city); //cout << "City: " << city << endl;

            // Trata da segunda linha -> separa os 3 números
            string s_n, s_c, s_m;
            getline(i_file_airport, s_n, ';');
            getline(i_file_airport, s_c, ';');
            getline(i_file_airport, s_m);
            int c=stoi(s_c);
            int n= stoi(s_n);
            int m= stoi(s_m);
            //cout << "N1: " << n << " N2: " << c << " N3: " << m << endl;

            // Constroi o objecto
            Airport a(name, city, c, n, m);

            string infotransports, transport;
            getline(i_file_airport, infotransports);
            stringstream trans(infotransports);

            // Lê a terceira linha completa
            while (getline(trans, transport, '-')) { // separa pelos '-'
                stringstream t(transport);
                string name, type, dist, hour;
                int distance;
                getline(t, name, ';');
                getline(t, type, ';');
                getline(t, dist, ';');
                distance = stoi(dist);
                getline(t, hour);
                //cout << "Nome: " << name << " type: " << type << " distance: " << distance << " all hours: " << hour << endl;

                stringstream h(hour);
                string r;
                vector<string> hours;
                while (getline(h, r, ';')) {         //um transporte pode ter muitos horários
                    hours.push_back(r);
                }

                for (int i = 0; i < hours.size(); i++){
                    //cout << hours.at(i) << " ";
                }
                //cout << endl;

                TTLocation ttl(name, type, distance, hours);
                a.addLocation(ttl);
            }

            company.addAirport(a);
        }
    }
    i_file_airport.close();
}
/*
void readPlanes(Company &company, string name_file){
    ifstream i_file_planes;
    i_file_planes.open(name_file);
    if (i_file_planes.is_open()){
        while (!i_file_planes.eof()){
            string info_plane, info_services_to_do, info_services_done, info_done, info_planes;
            string info_flight, info_passenger;
            getline(i_file_planes, info_plane);
            string matricula, ocup_max;
            stringstream s_plane(info_plane);
            getline(s_plane, matricula, ';');
            getline(s_plane, ocup_max, ';');
            int o_max = stoi(ocup_max);
            Plane p(matricula, o_max);
            getline(i_file_planes,info_services_to_do);
            stringstream s_services(info_services_to_do);
            string service;
            while (getline(s_services, service, '-')){   //tipo, data e empregado VER A CONDIÇÃO DE TERMINAR
                stringstream s(service);
                string type, date, employee;
                getline(s, type, ';');
                getline(s, date, ';');
                getline(s, employee, ';');
                Service c(type, date, employee);
                p.getToDo().push(c);
            }
            getline(i_file_planes, info_services_done);
            stringstream s_services_done(info_services_done);
            string service_done;
            while (getline(s_services_done, service_done, '-')){
                stringstream s_d(service_done);
                string type, date, employee;
                getline(s_d, type, ';');
                getline(s_d, date, ';');
                getline(s_d, employee, ';');
                Service c(type, date, employee);
                p.getDone().push(c);
            }
            //company.addPlane(p);    //estamos a guardar os aviões na companhia
            //passamos para criar os voos
            getline(i_file_planes, info_flight);
            stringstream str_flight(info_flight);
            string flight;
            while (getline(str_flight, flight, '-')){
                stringstream f(flight);
                string s_number, date, arrival, departure, origin, destination;
                getline(f, s_number, ';');
                int number = stoi(s_number);
                getline(f, date, ';');
                getline(f, arrival, ';');
                getline(f, departure, ';');
                getline(f, origin, ';');
                Airport a1, a2;     //porque o flight recebe dois objetos airport como parametro
                for (auto airport:company.airports){
                    if (airport.getCity() == origin)
                        a1 =airport;
                    if (airport.getCity() == destination)
                        a2 = airport;
                    break;
                }
                Flight flight1(number, date, arrival, departure, a1, a2);
                string passenger;
                while (getline(f, passenger, '+')){
                    stringstream pas(passenger);
                    string name, bag;
                    getline(pas, name, ';');
                    getline(pas, bag,';');
                    int b = stoi(bag);
                    Passenger passenger1(name, b);
                    company.addPassenger(passenger1);
                    flight1.passengers.push_back(passenger1);   //adiciona o passageiro à lista
                }
                company.addFlight(flight1);
                p.addFlight(flight1);
            }
            company.addPlane(p);
        }
    }
} */

void DoneList(Company &company){
    string LPlate;
    cin.clear();
    getline(cin,LPlate);
    Plane p = Plane("0000",0);
    for (auto plane : company.getPlanes()){
        if (LPlate==plane.getLPlate()){
            p = plane;
            break;
        }
    }
    queue<Service> todo = p.getDone();
    cout << "||"<< sizeRegularizer( "Servico",15)<<"||"<<sizeRegularizer("Data",10)<<"||"<<sizeRegularizer("Funcionario",20)<<endl;
    while (todo.empty()){
        cout << "||"<<sizeRegularizer(todo.front().getType(),15)<<"||"<<todo.front().getDate()<<"||"<<sizeRegularizer(todo.front().getEmployee(),20)<<endl;
        todo.pop();
    }
}

void ToDoList(Company &company){
    string LPlate;
    cin.clear();
    getline(cin,LPlate);
    Plane p = Plane("0000",0);
    for (auto plane : company.getPlanes()){
        if (LPlate==plane.getLPlate()){
            p = plane;
            break;
        }
    }
    queue<Service> todo = p.getToDo();
    cout << "||"<< sizeRegularizer( "Servico",15)<<"||"<<sizeRegularizer("Data",10)<<"||"<<sizeRegularizer("Funcionario",20)<<endl;
    while (!todo.empty()){
        cout << "||"<<sizeRegularizer(todo.front().getType(),15)<<"||"<<todo.front().getDate()<<"||"<<sizeRegularizer(todo.front().getEmployee(),20)<<endl;
        todo.pop();
    }
}

void ListFLightPassengers(Company& company){
    string number;
    Flight f;
    cin.clear();
    getline(cin,number);
    int num = stoi(number);
    for (auto flight : company.getFlights()){
        if (flight.getNumber() == num){
            f = flight;
            break;
        }
        else if (f.getNumber()!= num && f.getNumber()== company.getFlights().size()){
            cout << "ERRO: Voo nao existe. Por favor tente novamente.";
            ListFLightPassengers(company);
        }
    }
    cout <<"||"<<sizeRegularizer("Nome",20)<<"||Bagagem Automatica?||"<<endl;
    for (auto passenger : f.getPassengers()){
        if (passenger.getLuggage()>0)
            cout << "||"<<sizeRegularizer(passenger.getName(),20)<<"||"<<sizeRegularizer("Sim",19)<<"||"<<endl;
        else
            cout << "||"<<sizeRegularizer(passenger.getName(),20)<<"||"<<sizeRegularizer("Nao",19)<<"||"<<endl;
    }
    cout << "Insira 0 para voltar ao menu principal."<<endl;
    string str;
    cin.clear();
    getline(cin,str);
    while (true) {
        if (str == "0"){
            break;
        }
        else
            cout<< "ERRO: Input Invalido. Tente novamente."<<endl;
    }
}
void ListAllPassengers(Company& company) {
    cout << "||" << sizeRegularizer("Nome", 20) << "||Bagagem Automatica?||" << endl;
    for (auto passenger: company.getPassengers()) {
        if (passenger.getLuggage() > 0)
            cout << "||" << sizeRegularizer(passenger.getName(), 20) << "||" << sizeRegularizer("Sim", 19) << "||"
                 << endl;
        else
            cout << "||" << sizeRegularizer(passenger.getName(), 20) << "||" << sizeRegularizer("Nao", 19) << "||"
                 << endl;
    }
    cout << "Insira 0 para voltar ao menu principal."<<endl;
    string str;
    cin.clear();
    getline(cin,str);
}
void ListPassengers (Company& company){
    string input;
    char choice;
    cin.clear();
    getline(cin,input);
    choice = input.at(0);
    switch (choice) {
        case 'A':
        case 'a':
            ListAllPassengers(company);
            break;
        case 'B':
        case 'b':
            cout << "Selecione o Voo:" << endl;
            cout << "||" << sizeRegularizer("n#", 5) << "||" << sizeRegularizer("Data", 10) << "||"
                 << sizeRegularizer("Origem", 30) << "||" << sizeRegularizer("Destino", 30) << "||" << endl;
            for (auto flight: company.getFlights()) {
                cout << "||" << sizeRegularizer(to_string(flight.getNumber()), 5) << "||" << flight.getDate() << "||"
                     << sizeRegularizer(flight.getOrigin().getCity(), 30) << "||"
                     << sizeRegularizer(flight.getDestination().getCity(), 30) << "||" << endl;
            }
            ListFLightPassengers(company);
            break;
        default:
            cout << "ERRO: Input Invalido. Tente novamente."<<endl;
    }
}

string sizeRegularizer(string str, int n){
    if (str.size() > n){
        return str.substr(0,n-3) + "...";
    }
    else if (str.size() == n){
        return str;
    }
    else{
        while (str.size() + 2 <=n){
            str = " " + str.append(" ");
        }
        if (str.size() < n){
            str = str + " ";
        }
        return str;
    }
}
void flightByDestination(Company& company) {
    while (true) {
        string name, city;
        getline(cin, name);
        if (company.airportExists(name)) {
            cout << "||" << sizeRegularizer("n#", 5) << "||" << sizeRegularizer("Data", 10) << "||"
                 << sizeRegularizer("Origem", 30) << "||" << "Chegada" << "||" << endl;
            for (auto flight: company.flightsByDestination(name)) {
                cout << "||" << sizeRegularizer(to_string(flight.getNumber()), 5) << "||" << flight.getDate() << "||"
                     << sizeRegularizer(flight.getOrigin().getCity(), 30) << "||"
                     << sizeRegularizer(flight.getArrivalT(), 7) << "||" << endl;
            }
            cout << "Insira 0 para voltar ao menu principal" << endl;
            cin.clear();
            string a;
            getline(cin, a);
            while (true) {
                if (a == "0") {
                    break;
                } else {
                    cout << "ERRO: Input Invalido. Tente novamente." << endl;
                }
            }
        } else {
            cout << "ERRO: O aeroporto inserido nao existe. Tente novamente." << endl;
            flightByDestination(company);
        }
    }
}
void flightByOrigin(Company& company){
    while(true) {
        string name, city;
        cin.clear();
        getline(cin, name);
        if (company.airportExists(name)) {
            cout << "||" << sizeRegularizer("n#", 5) << "||" << sizeRegularizer("Data", 10) << "||" << "Partida" << "||"
                 << sizeRegularizer("Destino", 30) << "||" << endl;
            for (auto flight: company.flightsByOrigin(name)) {
                cout << "||" << sizeRegularizer(to_string(flight.getNumber()), 5) << "||" << flight.getDate() << "||"
                     << sizeRegularizer(flight.getDepartureT(), 7) << "||"
                     << sizeRegularizer(flight.getDestination().getCity(), 30) << "||" << endl;
            }
            cout << "Insira 0 para voltar ao menu principal" << endl;
            cin.clear();
            string a;
            getline(cin, a);
            while (true) {
                if (a == "0") {
                    break;
                } else {
                    cout << "ERRO: Input Invalido. Tente novamente." << endl;
                }
            }
        } else {
            cout << "ERRO: O aeroporto inserido nao existe. Tente novamente." << endl;
        }
    }
}
void flight_menu(Company& company){
    string input;
    char choice;
    cin.clear();
    getline(cin,input);
    choice = input.at(0);
    string a;
    switch (choice) {
        case 'A':
        case 'a':
            cout << "||" << sizeRegularizer("n#", 5) << "||" << sizeRegularizer("Data", 10) << "||"
                 << sizeRegularizer("Origem", 30) << "||" << sizeRegularizer("Destino", 30) << "||" << endl;
            for (auto flight: company.getFlights()) {
                cout << "||" << sizeRegularizer(to_string(flight.getNumber()), 5) << "||" << flight.getDate() << "||"
                     << sizeRegularizer(flight.getOrigin().getCity(), 30) << "||"
                     << sizeRegularizer(flight.getDestination().getCity(), 30) << "||" << endl;
            }
            cout << "Insira 0 para voltar ao menu principal"<<endl;
            cin.clear();
            getline(cin,a);
            while(true) {
                if (a =="0"){
                    break;
                }
                else{
                    cout << "ERRO: Input Invalido. Tente novamente."<<endl;
                }
            }
            break;
        case 'B':
        case 'b':
            cout << "Selecione o Aeroporto de Origem a partir dos da tabela:" << endl;
            cout << "||" << sizeRegularizer("Nome", 30) << "||" << sizeRegularizer("Cidade", 20) << "||" << endl;
            for (auto airport: company.getAirports()) {
                cout << "||" << sizeRegularizer(airport.getName(), 30) << "||" << sizeRegularizer(airport.getCity(), 20)
                     << "||" << endl;
            }
            cout << "Digite o nome do aeroporto selecionado abaixo:"<<endl;
            flightByOrigin(company);
            break;
        case 'C':
        case 'c':
            cout << "Selecione o Aeroporto de Destino a partir dos da tabela:" << endl;
            cout << "||" << sizeRegularizer("Nome", 30) << "||" << sizeRegularizer("Cidade", 20) << "||" << endl;
            for (auto airport: company.getAirports()) {
                cout << "||" << sizeRegularizer(airport.getName(), 30) << "||" << sizeRegularizer(airport.getCity(), 20)
                     << "||" << endl;
            }
            cout << "Digite o nome do aeroporto selecionado abaixo:"<<endl;
            flightByDestination(company);
            break;
        case '0':
        default:
            cout << "ERRO: Input Invalido. Tente novamente" << endl;
            flight_menu(company);
    }
}
void buy_ticket(Company& company) {
    cout << "Selecione o aeroporto de origem:"<<endl;
    cout << "||" << sizeRegularizer("Nome", 30) << "||" << sizeRegularizer("Cidade", 20) << "||" << endl;
    for (auto airport: company.getAirports()) {
        cout << "||" << sizeRegularizer(airport.getName(), 30) << "||"
             << sizeRegularizer(airport.getCity(), 20) << "||" << endl;
    }
    string airportOpt;
    while(true) {
        cin.clear();
        getline(cin, airportOpt);
        if (company.airportExists(airportOpt)) {
            Airport chosenAP;
            for (auto airport: company.getAirports()) {
                if (airport.getName() == airportOpt) {
                    chosenAP = airport;
                    break;
                }
            }
            cout << "Selecione o voo para o qual deseja comprar bilhetes:" << endl;
            cout << "||" << sizeRegularizer("n#", 5) << "||" << sizeRegularizer("Data", 10) << "||" << sizeRegularizer("Partida",30) << "||"
                 << sizeRegularizer("Destino", 30) << "||" << endl;
            for (auto flight: company.flightsByOrigin(airportOpt)) {
                cout << "||" << sizeRegularizer(to_string(flight.getNumber()), 5) << "||" << flight.getDate() << "||"
                     << sizeRegularizer(flight.getOrigin().getCity(), 30) << "||"
                     << sizeRegularizer(flight.getDestination().getCity(), 30) << "||" << endl;
            }
            string flightOpt;
            while (true) {
                cin.clear();
                getline(cin, flightOpt);
                if (company.flightExists(stoi(flightOpt))) {
                    auto itFlight = company.flights.begin();
                    for ( itFlight = company.flights.begin(); itFlight != company.flights.begin(); ++itFlight) {
                        if (itFlight->getNumber() == stoi(flightOpt)) {
                            break;
                        }
                    }
                    Plane flightPlane = company.getPlaneForFlight(itFlight->getNumber());
                    if (flightPlane.getMaxOccupation() == itFlight->getPassengers().size()) {
                        cout << "Este voo está cheio. Por favor, selecione outro." << endl;
                    } else {
                        int available = flightPlane.getMaxOccupation() - itFlight->getPassengers().size();
                        cout << "Este voo tem " << available << " lugares disponiveis." << endl;
                        cout << "Quantos bilhetes deseja comprar?" << endl;
                        cin.clear();
                        string amount;
                        while (true) {
                            getline(cin, amount);
                            int a = stoi(amount);
                            if (a <= available) {
                                while (a > 0) {
                                    cout << "Bilhete " << stoi(amount) - a + 1 << " :" << endl;
                                    string name, lugOpt;
                                    cout << "Insira o nome do passageiro para este bilhete." << endl;
                                    cin.clear();
                                    getline(cin, name);
                                    int capacity = itFlight->getCarCapacity();
                                    cout << "Insira quantas malas levara para o servico de bagagem automatica." << endl;
                                    cout << "(insira 0 se nao desejar usar o servico de bagagem automatica)" << endl;
                                    cout << "Espaco disponivel: " << capacity << " malas." << endl;
                                    while (true) {
                                        cin.clear();
                                        getline(cin, lugOpt);
                                        int lug = stoi(lugOpt);
                                        if (lug <= capacity) {
                                            Passenger p(name, lug);
                                            itFlight->addPassenger(p);
                                            company.passengers.push_back(p);
                                            break;
                                        } else {
                                            cout
                                                    << "ERRO:Nao existe espaco suficiente para levar tantas malas. Por favor tente novamente."
                                                    << endl;
                                            cout
                                                    << "(insira 0 se deseja cancelar o servico de bagagem automatica no seu bilhete)"
                                                    << endl;
                                        }
                                    }
                                    a--;
                                }
                                break;
                            } else {
                                cout << "ERRO:Temos " << available
                                     << " bilhetes disponiveis. Por favor insira um numero igual ou inferior a esse."
                                     << endl;
                            }
                        }
                        break;
                    }
                    break;
                } else {
                    cout << "ERRO: O voo inserido nao existe. Tente novamente." << endl;
                }
            }
            break;
        } else {
            cout << "ERRO: Aeroporto inserido nao existe. Tente novamente." << endl;
        }
    }
    cout << "Obrigado pela sua compra!"<<endl;
    cout << "Insira 0 para voltar ao menu principal." << endl;
    string choice;
    cin.clear();
    getline(cin, choice);
}
void update_flight(Company& company) {
    string input;
    if(!company.flights.empty()) {
        bool exists = false;
        auto it = company.flights.begin();
        auto itFlight = it;
        cout << "||" << sizeRegularizer("n#", 5) << "||" << sizeRegularizer("Data", 10) << "||" << "Partida"
             << "||" << sizeRegularizer("Destino", 30) << "||" << endl;
        for (auto plane: company.planes) {
            if (plane.hasFlights()) {
                Flight nextFlight = plane.nextFlight();
                cout << "||" << sizeRegularizer(to_string(nextFlight.getNumber()), 5) << "||" << nextFlight.getDate()
                     << "||"
                     << sizeRegularizer(nextFlight.getDepartureT(), 7) << "||"
                     << sizeRegularizer(nextFlight.getDestination().getCity(), 30) << "||" << endl;
            }
        }
        cout << "Insira o numero do voo que quer realizar:" << endl;
        int flightN;
        cin.clear();
        getline(cin, input);
        flightN = stoi(input);
        while (!exists) {
            for (it = company.flights.begin(); it != company.flights.end(); it++) {
                if (it->getNumber() == flightN) {
                    itFlight = it;
                    exists = true;
                } else if (it == company.flights.end()) {
                    cout << "Voo de numero nao existente" << endl;
                    cout << "Por favor introduza outro numero de voo ou insira 0 para voltar ao menu anterior" << endl;
                    cin.clear();
                    getline(cin, input);
                    flightN = stoi(input);
                }
            }
            if (flightN == 0)
                exists = true;
        }
        cout << itFlight->getNumber() << endl;
        if (flightN != 0) {
            for (auto itPlane = company.planes.begin(); itPlane != company.planes.end(); ++itPlane) {
                queue<Flight> flightPlan = itPlane->getFlightPlan();
                while (!flightPlan.empty()) {
                    if (flightPlan.front().getNumber() == flightN) {
                        cout << itPlane->flightPlan.front().number << endl;
                        itPlane->flightPlan.pop();
                        cout << itPlane->flightPlan.front().number << endl;
                        break;
                    } else
                        flightPlan.pop();
                }
            }
            itFlight = company.flights.erase(itFlight);
            cout << "Voo realizado com sucesso" << endl;
        }
    }
    else {
        cout << "Nao existem voos por realizar. Insira 0 para voltar ao menu anterior" << endl;
        cin.clear();
        getline(cin, input);
    }
}

void update_service(Company& company){
    bool notOver = true;
    bool exists = false;
    string input, planeN;
    auto itPlane = company.getPlanes().begin();
    auto it = company.getPlanes().begin();
    queue<Service> itService;
    while (notOver) {
        cout << "Selecione o aviao cujos servicos deseja consultar:" << endl;
        cout << "||Aviao||Lugares||" << sizeRegularizer("Localizacao Atual", 30) << "||" << endl;
        for (auto itPlane = company.planes.begin(); itPlane != company.planes.end(); ++itPlane) {
            if (!itPlane->getFlightPlan().empty())
                cout << "||" << sizeRegularizer(itPlane->getLPlate(), 9) << "||"
                     << sizeRegularizer(to_string(itPlane->getMaxOccupation()), 7) << "||"
                     << sizeRegularizer(itPlane->getFlightPlan().front().getOrigin().getName(), 30) << "||"
                     << endl;
            else
                cout << "||" << sizeRegularizer(itPlane->getLPlate(), 9) << "||"
                     << sizeRegularizer(to_string(itPlane->getMaxOccupation()), 7) << "||"
                     << sizeRegularizer("Nao Operacional", 30) << "||" << endl;
        }
        cout << "Insira a matricula do aviao cujos servicos deseja consultar ou 0 para voltar ao menu anterior"<<endl;
        cin.clear();
        getline(cin, planeN);
        while (!exists){
            if (planeN == "0")
                exists = true;
            else {
                for (it = company.planes.begin(); it != company.planes.end(); ++it) {
                    if (it->getLPlate() == planeN) {
                        itPlane = it;
                        exists = true;
                    } else if (it == company.planes.end()) {
                        cout << "Matricula nao existente" << endl;
                        cout << "Por favor introduza outra matricula ou insira 0 para voltar ao menu anterior" << endl;
                        cin.clear();
                        getline(cin, planeN);
                    }
                }
            }
        }
        if (planeN != "0"){
            cout<<"O proximo servico a realizar para o aviao "<< planeN<< " sera:"<< endl;
            cout<< "||"<< sizeRegularizer( "Servico",15)<<"||"<<sizeRegularizer("Data",10)<<"||"<<sizeRegularizer("Funcionario",20)<<endl;
            cout<< "||"<<sizeRegularizer(itPlane->getToDo().front().getType(),15)<<"||"<<itPlane->getToDo().front().getDate()<<"||"<<sizeRegularizer(itPlane->getToDo().front().getEmployee(),20)<<endl;
            cout<< "Deseja realizar o servico? Insira: Y)sim; N)nao;"<<endl;
            cin.clear();
            getline(cin, input);
            if(input == "Y" || input == "y") {
                itPlane->done.push(itPlane->to_do.front());
                itPlane->to_do.pop();
                cout<< "Servico realizado com sucesso"<<endl;
            }
            cout<<"Deseja realizar outro servico? Insira: Y)sim; N)nao;"<<endl;
            cin.clear();
            getline(cin, input);
            if(input == "N" || input == "n") {
                notOver = false;
            }
        }
        else
            notOver = false;
    }
}


void viewtransport(Company& company){
    string name;
    cout << "Insira o aeroporto que pretende" << endl;
    getline(cin, name);
    if (company.airportExists(name)) {
        Airport a1;
        cout << "||" << sizeRegularizer("n#", 5) << "||" << sizeRegularizer("Data", 10) <<"||"<<"Partida"<< "||" << sizeRegularizer("Destino", 30) << "||" << endl;
        for (auto airport:company.getAirports()){
            if (airport.getName() == name)
                a1 = airport;
        }

        BSTItrIn<TTLocation>itr(a1.getLocations());
        while (!itr.isAtEnd()){     //mostra os atributos de transportes
            cout << "||" << sizeRegularizer(itr.retrieve().name, 30) << "||" << sizeRegularizer(itr.retrieve().type, 20) << " " <<
                 sizeRegularizer(to_string(itr.retrieve().distance), 5) << " ";
            for (auto v:itr.retrieve().schedule){
                cout << v << " ";
            }
            cout << endl;
            itr.advance();
        }
    }

    else{
        cout << "ERRO: Input Invalido. Tente novamente."<<endl;
        viewtransport(company);
    }
}

void main_menu(Company& company) {
    bool notOver = true;
    cout << "====================Agencia Voe Connosco=====================" << endl;
    cout << "-Bem vindo!" << endl;
    while (notOver) {
        cout << "-Selecione a operacao desejada inserindo a letra respetiva." << endl;
        cout << "A)Tabelas de Voos" << endl;
        cout << "B)Tabela de Aeroportos" << endl;
        cout << "C)Comprar Bilhetes" << endl;
        cout << "D)Listas de Passageiros" << endl;
        cout << "E)Listas de Locais de Transporte Proximos" << endl;
        cout << "F)Servicos a Realizar" << endl;
        cout << "G)Servicos Realizados" << endl;
        cout << "H)Realizar Viagem" << endl;
        cout << "I)Realizar Servico" << endl;
        cout << "0)Exit" << endl;
        char choice;
        string input;
        cin.clear();
        getline(cin, input);
        choice = input.at(0);
        string b;
        switch (choice) {
            case 'a':
            case 'A':
                cout << "-Selecione uma opcao:" << endl;
                cout << "A)Ver todos os voos da companhia" << endl;
                cout << "B)Ver todos os voos que partem de um aeroporto" << endl;
                cout << "C)Ver todos os voos que chegam a um aeroporto" << endl;
                cout << "Insira 0 para voltar ao menu principal" << endl;
                flight_menu(company);
                break;
            case 'b':
            case 'B':
                cout << "||" << sizeRegularizer("Nome", 30) << "||" << sizeRegularizer("Cidade", 20) << "||" << endl;
                for (auto airport: company.getAirports()) {
                    cout << "||" << sizeRegularizer(airport.getName(), 30) << "||"
                         << sizeRegularizer(airport.getCity(), 20) << "||" << endl;
                }
                cout << "Insira 0 para voltar ao menu principal." << endl;
                while (true) {
                    getline(cin, b);
                    if (b == "0") {
                        break;
                    } else {
                        cout << "ERRO: Input Invalido. Tente novamente." << endl;
                    }
                }
                break;
            case 'c':
            case 'C':
                buy_ticket(company);
                break;
            case 'd':
            case 'D':
                cout << "Selecione uma opcao abaixo:" << endl;
                cout << "A)Listar todos os passageiros da companhia" << endl;
                cout << "B)Listar todos os passageiros de um voo" << endl;
                ListPassengers(company);
                break;
            case 'e':
            case 'E':
                cout << "<IMPLEMENTAR TABELA DE LOCAIS DE TRANSPORTE>" << endl;
                //VER SE ESTÁ BEM

                for (auto airport: company.getAirports()) {
                    BSTItrIn<TTLocation> itr(airport.getLocations());
                    while (!itr.isAtEnd()) {
                        cout << itr.retrieve().name << " " << itr.retrieve().type << " " <<
                             itr.retrieve().distance << " ";
                        for (auto const &v: itr.retrieve().schedule) {
                            cout << v << " ";
                        }
                        cout << endl;
                        itr.advance();
                    }
                }
                break;
            case 'f':
            case 'F':
                cout << "Selecione o aviao cujos servicos deseja consultar:" << endl;
                cout << "||Aviao||Lugares||" << sizeRegularizer("Localizacao Atual", 30) << "||" << endl;
                for (auto plane: company.getPlanes()) {
                    if (!plane.getFlightPlan().empty())
                        cout << "||" << sizeRegularizer(plane.getLPlate(), 9) << "||"
                             << sizeRegularizer(to_string(plane.getMaxOccupation()), 7) << "||"
                             << sizeRegularizer(plane.getFlightPlan().front().getOrigin().getName(), 30) << "||"
                             << endl;
                    else
                        cout << "||" << sizeRegularizer(plane.getLPlate(), 9) << "||"
                             << sizeRegularizer(to_string(plane.getMaxOccupation()), 7) << "||"
                             << sizeRegularizer("Nao Operacional", 30) << "||" << endl;
                }
                ToDoList(company);
                break;
            case 'g':
            case 'G':
                cout << "Selecione o aviao cujos servicos deseja consultar:" << endl;
                cout << "||Aviao||Lugares||" << sizeRegularizer("Localizacao Atual", 30) << "||" << endl;
                for (auto plane: company.getPlanes()) {
                    if (plane.getFlightPlan().empty())
                        cout << "||" << sizeRegularizer(plane.getLPlate(), 9) << "||"
                             << sizeRegularizer(to_string(plane.getMaxOccupation()), 7) << "||"
                             << sizeRegularizer(plane.getFlightPlan().front().getOrigin().getName(), 30) << "||"
                             << endl;
                    else
                        cout << "||" << sizeRegularizer(plane.getLPlate(), 9) << "||"
                             << sizeRegularizer(to_string(plane.getMaxOccupation()), 7) << "||"
                             << sizeRegularizer("Nao Operacional", 30) << "||" << endl;
                }
                DoneList(company);
                break;
            case 'h':
            case 'H':
                cout << "Escolha qual o voo que deseja realizar" << endl;
                update_flight(company);
                break;
            case 'i':
            case 'I':
                update_service(company);
                break;
            case '0':
                notOver = false;
                break;
            default :
                cout << "ERRO: Input Invalido. Tente novamente." << endl;

        }
    }
}

int main() {
    Company company;

    Service s1 = Service("Limpeza", "22-12-2021","Joao Pereira");
    Service s2 = Service("Manutencao", "22-12-2021","Miguel Sousa");
    Service s3 = Service("Vistoria", "22-12-2021","Marta Lima");

    Passenger p1 = Passenger("Carlos Silva",2);
    Passenger p2 = Passenger("Luis Miguel",1);
    Passenger p3 = Passenger("Simao Rodrigues",3);
    Passenger p4 = Passenger("Ana Marques",2);
    Passenger p5 = Passenger("Guilherme Moreira",1);
    Passenger p6 = Passenger("Antonio Marques",3);
    Passenger p7 = Passenger("Jose Nunes",1);
    Passenger p8 = Passenger("Lucia Pereira",3);
    Passenger p9 = Passenger("Carla Ferreira",2);
    Passenger p10 = Passenger("Fernanda Paiva",1);


    vector<string> schedule = {"08:00","22:00"};
    TTLocation t1 = TTLocation("Estacao de Sa Carneiro","Metro",0.5,schedule);
    TTLocation t2 = TTLocation("Paragem de Sa Carneiro","Autocarro",0.2,schedule);
    TTLocation t3 = TTLocation("Paragem de Sa Carneiro","Taxi",0.2,schedule);
    TTLocation t4 = TTLocation("Estacao de Humberto Delgado","Metro",0.5,schedule);
    TTLocation t5 = TTLocation("Paragem de Humberto Delgado","Autocarro",0.2,schedule);
    TTLocation t6 = TTLocation("Praca de Humberto Delgado","Taxi",0.2,schedule);
    TTLocation t7 = TTLocation("Paragem CR7","Autocarro",0.2,schedule);
    TTLocation t8 = TTLocation("Praca do Funchal","Taxi",0.2,schedule);
    string name = "Aeroporto Sa Carneiro", city = "Porto";
    int c = 3, n = 3, m = 3;
    Airport a1 = Airport(name,city,c,n,m);
    name = "Aeroporto Humberto Delgado", city = "Lisboa";
    c = 4, n = 3, m = 2;
    Airport a2 = Airport(name,city,c,n,m);
    name = "Aeroporto Cristiano Ronaldo",city="Funchal";
    c = 2, n= 2, m = 5;
    Airport a3 = Airport(name,city,c,n,m);


    Flight f1 = Flight(1,"22:00","20:00","22-12-2021",a1,a2);
    Flight f2 = Flight(2,"12:00","10:00","22-12-2021",a1,a2);
    Flight f3 = Flight(3,"00:30","22:30","22-12-2021",a2,a1);
    Flight f4 = Flight(4,"14:30","12:30","22-12-2021",a2,a1);
    Flight f5 = Flight(5,"00:00","20:00","22-12-2021",a1,a3);
    Flight f6 = Flight(6,"14:00","10:00","22-12-2021",a2,a3);
    Flight f7 = Flight(7,"00:00","20:00","22-12-2021",a3,a1);
    Flight f8 = Flight(8,"14:00","10:00","22-12-2021",a3,a1);
    cout << f1.car.getC()<< endl<< f1.car.getM()<< endl<< f1.car.getN()<<endl;

    Plane P1 = Plane("A001",250);
    Plane P2 = Plane("A002",300);
    Plane P3 = Plane("A003",320);
    Plane P4 = Plane("A004",400);
    Plane P5 = Plane("A005",250);
    Plane P6 = Plane("A006",300);
    P1.addTask_to_do(s1), P1.addTask_to_do(s2);
    P2.addTask_to_do(s3), P2.addTask_to_do(s2);
    P3.addTask_to_do(s2), P3.addTask_to_do(s3);
    P4.addTask_to_do(s1), P4.addTask_to_do(s3);
    P5.addTask_to_do(s1);
    P6.addTask_to_do(s1), P6.addTask_to_do(s2),P6.addTask_to_do(s3);
    f1.addPassenger(p1),f1.addPassenger(p2),f1.addPassenger(p3),
            f2.addPassenger(p2),f2.addPassenger(p3),f2.addPassenger(p4),
            f3.addPassenger(p3),f3.addPassenger(p4),f3.addPassenger(p5);
    P1.addFlight(f1),P1.addFlight(f5),P1.addFlight(f8);
    P2.addFlight(f3),P2.addFlight(f4);
    P3.addFlight(f7),P3.addFlight(f2),P3.addFlight(f6);
    company.addFlight(f1),company.addFlight(f2),company.addFlight(f3),company.addFlight(f4),company.addFlight(f5),company.addFlight(f6),company.addFlight(f7),company.addFlight(f8);
    company.addPassenger(p1),company.addPassenger(p2),company.addPassenger(p3),company.addPassenger(p4),company.addPassenger(p5),company.addPassenger(p6),company.addPassenger(p7),company.addPassenger(p8),company.addPassenger(p9),company.addPassenger(p10);
    company.addAirport(a1),company.addAirport(a2),company.addAirport(a3);
    company.addPlane(P1),company.addPlane(P2),company.addPlane(P3),company.addPlane(P4),company.addPlane(P5),company.addPlane(P6);
    /*//AEROPORTO
    string file_airport = "../aeroporto.txt";
    readAirports(company, file_airport);
    cout << company.getAirports().size() << endl;*/
    cout << "Bem-vindo a Agencia Voa Connosco! :)" << endl;

    /*cout << "Escolhe um dos nossos aeroportos para poderes prosseguir: " << endl;
    /*
    //AEROPORTO
    string file_airport = "../aeroporto.txt";
    readAirports(company, file_airport);
    cout << "Quantidade de Aeroportos = " << company.getAirports().size() << endl;
>>>>>>> 783d3da30df7a219707618c019cb15d3c28e64e4
    for (auto airport: company.getAirports()){
        cout << airport.getName() << " " << airport.getCity()<<endl;
        cout << "Carrinho : c=" << airport.getCar().getC()<<", n="<<airport.getCar().getN()<<", m="<<airport.getCar().getM()<<endl;
        cout << "Localizacoes de Transporte:"<<endl;
        BSTItrIn<TTLocation> itr(airport.getLocations());
        while(!itr.isAtEnd()) {
            cout << itr.retrieve().name << ";" << itr.retrieve().type << ";" <<
                 itr.retrieve().distance << ";" << itr.retrieve().schedule.size();
            cout << endl;
            itr.advance();
        }
    }
    string op_airport, op_city;
    getline(cin, op_airport);
    Airport a1;
    for (auto airport:company.getAirports()){
        if (airport.getName() == op_airport)
            a1 = airport;
    }*/

    //AVIÃO
    /*
    string name_file_plane = a1.getCity() + "plane.txt";
    readPlanes(company, name_file_plane);
    for (auto airport:company.getAirports()){
        cout << airport.getName() << " " << airport.getCity();
    }
    for (auto plane:company.getPlanes()){
        cout << plane.getLPlate() << " " << plane.getMaxOccupation();
    }
    for (auto flight:company.getFlights()){
        cout << flight.getNumber() << " " << flight.getDate();
    }
    for (auto passenger:company.getPassengers()){
        cout << passenger.getName() << " " << passenger.getLuggage();
    } */

    main_menu(company);


    povoar(company);
    //main_menu(company);

    return 0;
}