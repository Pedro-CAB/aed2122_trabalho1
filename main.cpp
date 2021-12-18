#include <iostream>
#include <fstream>
#include <sstream>
#include "Company.h"

using namespace std;

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
            int n=stoi(s_n);
            int c=stoi(s_c);
            int m=stoi(s_m);
            //cout << "N1: " << n << " N2: " << c << " N3: " << m << endl;

            // Constroi o objecto
            Airport a(name, city, n, c, m);

            string infotransports, transport;
            getline(i_file_airport, infotransports);
            stringstream trans(infotransports);

            // Lê a terceira linha completa
            while (getline(trans, transport, '-')) { // separa pelos '-'
                stringstream t(transport);
                string name, type, distance, hour;
                getline(t, name, ';');
                getline(t, type, ';');
                getline(t, distance, ';');
                getline(t, hour);
                cout << "Nome: " << name << " type: " << type << " distance: " << distance << " all hours: " << hour << endl;

                stringstream h(hour);
                string r;
                vector<string> hours;
                while (getline(h, r, ';')) {         //um transporte pode ter muitos horários
                    hours.push_back(r);
                }

                for (int i = 0; i < hours.size(); i++){
                    cout << hours.at(i) << " ";
                }
                cout << endl;

                //float d = 0.2;
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

void main_menu(Company company), go_back(Company company);
string sizeRegularizer(string str, int n);

void DoneList(Company company){
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
    cout << "||"<< sizeRegularizer("Tarefa",15)<<"||"<<sizeRegularizer("Data",10)<<"||"<<sizeRegularizer("Funcionario",20)<<endl;
    while (todo.empty()){
        cout << "||"<<sizeRegularizer(todo.front().getType(),15)<<"||"<<todo.front().getDate()<<"||"<<sizeRegularizer(todo.front().getEmployee(),20)<<endl;
        todo.pop();
    }
    cout << "Insira 0 para voltar ao menu principal"<<endl;
    go_back(company);
}

void ToDoList(Company company){
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
    cout << "||"<< sizeRegularizer("Tarefa",15)<<"||"<<sizeRegularizer("Data",10)<<"||"<<sizeRegularizer("Funcionario",20)<<endl;
    while (todo.empty()){
        cout << "||"<<sizeRegularizer(todo.front().getType(),15)<<"||"<<todo.front().getDate()<<"||"<<sizeRegularizer(todo.front().getEmployee(),20)<<endl;
        todo.pop();
    }
    cout << "Insira 0 para voltar ao menu principal"<<endl;
    go_back(company);
}

void ListFLightPassengers(Company company){
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
    go_back(company);
}
void ListAllPassengers(Company company){
    cout <<"||"<<sizeRegularizer("Nome",20)<<"||Bagagem Automatica?||"<<endl;
    for (auto passenger : company.getPassengers()){
        if (passenger.getLuggage()>0)
            cout << "||"<<sizeRegularizer(passenger.getName(),20)<<"||"<<sizeRegularizer("Sim",19)<<"||"<<endl;
        else
            cout << "||"<<sizeRegularizer(passenger.getName(),20)<<"||"<<sizeRegularizer("Nao",19)<<"||"<<endl;
    }
    cout << "Insira 0 para voltar ao menu principal."<<endl;
    go_back(company);
}
void ListPassengers (Company company){
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

void go_back(Company company) {
    string input;
    char choice;
    cin.clear();
    getline(cin, input);
    choice = input.at(0);
    switch (choice) {
        case '0':
            cout << "====================Agência Voe Connosco=====================" << endl;
            cout << "-Bem vindo!" << endl;
            cout << "-Selecione a operacao desejada inserindo a letra respetiva." << endl;
            cout << "A)Tabelas de Voos" << endl;
            cout << "B)Tabela de Aeroportos" << endl;
            cout << "C)Comprar Bilhetes" << endl;
            cout << "D)Listas de Passageiros" << endl;
            cout << "E)Listas de Locais de Transporte Proximos" << endl;
            cout << "F)Tarefas a Realizar" << endl;
            cout << "G)Tarefas Realizadas" << endl;
            cout << "H)Atualizar Viagem" << endl;
            main_menu(company);
            break;
        default:
            cout << "ERRO: Input Invalido. Tente novamente." << endl;
            go_back(company);
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
void flightByDestination(Company company){
    string name, city;
    cout << "Insira o nome do aeroporto abaixo:"<<endl;
    getline(cin,name);
    if (company.airportExists(name)) {
        cout << "||" << sizeRegularizer("n#", 5) << "||" << sizeRegularizer("Data", 10) << "||"
             << sizeRegularizer("Origem", 30) << "||" << "Chegada" << "||" << endl;
        for (auto flight: company.flightsByDestination(name)) {
            cout << "||" << sizeRegularizer(to_string(flight.getNumber()), 5) << "||" << flight.getDate() << "||"
                 << sizeRegularizer(flight.getOrigin().getCity(), 30) << "||"
                 << sizeRegularizer(flight.getArrivalT(), 7) << "||" << endl;
        }
        cout<< "Insira 0 para voltar ao menu principal."<<endl;
        go_back(company);
    }
    else{
        cout << "ERRO: O aeroporto inserido nao existe. Tente novamente."<<endl;
        flightByDestination(company);
    }
}
void flightByOrigin(Company company){
    string name, city;
    cout << "Insira o nome do aeroporto abaixo:"<<endl;
    cin.clear();
    getline(cin,name);
    if (company.airportExists(name)) {
        cout << "||" << sizeRegularizer("n#", 5) << "||" << sizeRegularizer("Data", 10) <<"||"<<"Partida"<< "||" << sizeRegularizer("Destino", 30) << "||" << endl;
        for (auto flight: company.flightsByOrigin(name)) {
            cout << "||" << sizeRegularizer(to_string(flight.getNumber()), 5) << "||" << flight.getDate() << "||"
                 << sizeRegularizer(flight.getDepartureT(), 7) << "||"
                 << sizeRegularizer(flight.getDestination().getCity(), 30) << "||" << endl;
        }
        cout<<"Insira 0 para voltar ao menu principal."<<endl;
        go_back(company);
    }
    else{
        cout << "ERRO: Input Invalido. Tente novamente."<<endl;
        flightByOrigin(company);
    }
}
void flight_menu(Company company){
    string input;
    char choice;
    cin.clear();
    getline(cin,input);
    choice = input.at(0);
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
            cout << "Insira 0 para voltar ao menu principal." << endl;
            go_back(company);
            break;
        case 'B':
        case 'b':
            cout << "Selecione o Aeroporto de Origem:" << endl;
            cout << "||" << sizeRegularizer("Nome", 30) << "||" << sizeRegularizer("Cidade", 20) << "||" << endl;
            for (auto airport: company.getAirports()) {
                cout << "||" << sizeRegularizer(airport.getName(), 30) << "||" << sizeRegularizer(airport.getCity(), 20)
                     << "||" << endl;
            }
            flightByOrigin(company);
            break;
        case 'C':
        case 'c':
            cout << "Selecione o Aeroporto de Destino:" << endl;
            cout << "||" << sizeRegularizer("Nome", 30) << "||" << sizeRegularizer("Cidade", 20) << "||" << endl;
            for (auto airport: company.getAirports()) {
                cout << "||" << sizeRegularizer(airport.getName(), 30) << "||" << sizeRegularizer(airport.getCity(), 20)
                     << "||" << endl;
            }
            flightByDestination(company);
            break;
        case '0':
            cout << "====================Agencia Voe Connosco=====================" << endl;
            cout << "-Bem vindo!" << endl;
            cout << "-Selecione a operacao desejada inserindo a letra respetiva." << endl;
            cout << "A)Tabelas de Voos" << endl;
            cout << "B)Tabela de Aeroportos" << endl;
            cout << "C)Comprar Bilhetes" << endl;
            cout << "D)Listas de Passageiros" << endl;
            cout << "E)Listas de Locais de Transporte Proximos" << endl;
            cout << "F)Tarefas a Realizar" << endl;
            cout << "G)Tarefas Realizadas" << endl;
            cout << "H)Atualizar Viagem" << endl;
            main_menu(company);
        default:
            cout << "ERRO: Input Invalido. Tente novamente" << endl;
            flight_menu(company);
    }
}

void buy_ticket(Company company) {
    bool control = true;
    while (control) {
        string input;
        char choice;
        getline(cin,input);
        choice = input.at(0);
        switch (choice) {
            case '0':
                control = false;
                break;
            case 'A':
                cout << "||  n# ||          ||                              ||                              ||" << endl;
                for (auto flight: company.getFlights()) {
                    cout << "||" << sizeRegularizer(to_string(flight.getNumber()), 5) << "||" << flight.getDate()
                         << "||" << sizeRegularizer(flight.getOrigin().getCity(), 30) << "||"
                         << sizeRegularizer(flight.getDestination().getCity(), 30) << "||" << endl;
                }
                break;
            case 'B':
                bool exists = false;
                cout << "Insira o numero do voo para qual quer comprar bilhetes" << endl;
                int flightN;
                auto itFlight = company.flights.begin();
                cin >> flightN;
                while (!exists) {
                    for (auto it = company.flights.begin(); it != company.flights.end(); it++) {
                        if (it == company.flights.end()) {
                            cout << "Voo de numero nao existente" << endl;
                            cout << "Por favor introduza outro numero de vôo ou 0 para voltar ao menu anterior" << endl;
                            cin >> flightN;
                        } else if (it->getNumber() == flightN) {
                            itFlight = it;
                            exists = true;
                        }
                        if (flightN == 0)
                            exists = true;
                    }
                }
                if (flightN != 0) {
                    try {
                        Plane plane = company.getPLane(flightN);

                        if (company.isFull(*itFlight, plane)) {
                            cout << "Infelizmente o voo numero(" << flightN << ") nao tem mais lugares disponiveis"
                                 << endl;
                        } else {
                            cout << "Introduza o numero de bilhetes que deseja comprar:" << endl;
                            int ticketN;
                            cin >> ticketN;
                            if (ticketN > company.emptySeats(*itFlight, plane)) {
                                cout << "Infelizmente o voo numero(" << flightN << ") só tem mais "
                                     << company.emptySeats(*itFlight, plane) << " lugares disponiveis" << endl;
                            } else {
                                for (int i = 0; i < ticketN; ++i) {
                                    string nome;
                                    char autoL;
                                    bool autoLug = false;
                                    cout << "Introduza o nome do titular deste bilhete:" << endl;
                                    getline(cin, nome);
                                    getline(cin, nome);
                                    cout<< "Vai desejar utilizar o servico de bagagem automatica? Introduza uma das seguintes opcoes:"<<endl<<"Y)Sim"<<endl<<" N)Nao;" << endl;  //Por enquanto está a assumir q o carrinho já tem conteu
                                    cin >> autoL;                                                                                                                //Ainda não decidimos como implementar o carrinho
                                    if (autoL == 'Y') {
                                        if (!itFlight->getOrigin().getCar().addLuggage()) {
                                            cout
                                                    << "Infelizmente o servico de bagagem automatica ja nao se encontra disponivel. Tera que processar a sua bagagem manualmente"
                                                    << endl;
                                        } else
                                            autoLug = true;
                                    }
                                    itFlight->passengers.emplace_back(Passenger(nome, autoLug));
                                }
                                cout << "Obrigado por viajar com a Voe Connosco!" <<endl;
                            }
                        }
                    } catch (const char* msg) {
                        cerr << msg << endl;
                    }
                }
                break;
        }
    }
}
/*
void updatetasks(Company company){
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
            cout << '||' << sizeRegularizer(itr.retrieve().name, 30) << "||" << sizeRegularizer(itr.retrieve().type, 20) << " " <<
            sizeRegularizer(to_string(itr.retrieve().distance), 5) << " ";
            for (auto v:itr.retrieve().schedule){
                cout << v << " ";
            }
            cout << endl;
        }
    }
}
*/
void main_menu(Company company){
    char choice;
    string input;
    getline(cin,input);
    choice = input.at(0);

    switch (choice) {
        case 'a':
        case 'A':
            cout << "-Selecione uma opcao:" << endl;
            cout << "A)Ver todos os voos da companhia" << endl;
            cout << "B)Ver todos os voos que partem de um aeroporto" << endl;
            cout << "C)Ver todos os voos que chegam a um aeroporto" << endl;
            cout << "Insira 0 para voltar ao menu principal." << endl;
            flight_menu(company);
            break;
        case 'b':
        case 'B':
            cout << "||" << sizeRegularizer("Nome", 30) << "||" << sizeRegularizer("Cidade", 20) << "||" << endl;
            for (auto airport: company.getAirports()) {
                cout << "||" << sizeRegularizer(airport.getName(), 30) << "||"
                     << sizeRegularizer(airport.getCity(), 20) << "||" << endl;
            }
            cout << "-Insira 0 para voltar ao menu principal" << endl;
            go_back(company);
            break;
        case 'c':
        case 'C':
            cout << "-Selecione uma opcao:" << endl;
            cout << "A)Ver todos os voos da companhia" << endl;
            cout << "B)Comprar bilhetes" << endl;
            cout << "-Insira 0 para voltar ao menu principal" << endl;
            buy_ticket(company);
            break;
        case 'd':
        case 'D':
            cout<<"Selecione uma opcao abaixo:"<<endl;
            cout<<"A)Listar todos os passageiros da companhia"<<endl;
            cout<<"B)Listar todos os passageiros de um voo"<<endl;
            ListPassengers(company);
            break;
        case 'e':
        case 'E':
            cout << "<IMPLEMENTAR TABELA DE LOCAIS DE TRANSPORTE>" << endl;
            //VER SE ESTÁ BEM

            for (auto airport:company.getAirports()){
                BSTItrIn<TTLocation> itr(airport.getLocations());
                while (!itr.isAtEnd()){
                    cout << itr.retrieve().name << " " << itr.retrieve().type << " " <<
                    itr.retrieve().distance << " ";
                    for (auto v:itr.retrieve().schedule){
                        cout << v << " ";
                    }
                    cout << endl;
                    itr.advance();
                }
            }
            break;
        case 'f':
        case 'F':
            cout << "Selecione o aviao cujas tarefas deseja consultar:" << endl;
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
            ToDoList(company);
            break;
        case 'g':
        case 'G':
            cout << "Selecione o aviao cujas tarefas deseja consultar:" << endl;
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
            cout << "<IMPLEMENTAR ATUALIZACAO DE VIAGEM>" << endl;
            break;
        case 'i':
        case 'I':
            cout << "<IMPLEMENTAR ATUALIZACAO DE TAREFAS"<<endl;
            cout << "Qual é o avião que deseja alterar? " << endl;
            break;
        default :
            cout << "ERRO: Input Invalido. Tente novamente." << endl;
            main_menu(company);

    }
}

int main() {

    Company company;

    //AEROPORTO
    string file_airport = "../aeroporto.txt";
    readAirports(company, file_airport);

    cout << company.getAirports().size() << endl;
    cout << "Bem-vindo a Agencia Voa Connosco! :)" << endl;

    cout << "Escolhe um dos nossos aeroportos para poderes prosseguir: " << endl;

    for (auto airport: company.getAirports()){
        cout << airport.getName() << " " << airport.getCity();  //lista todos os aeroportos que estão no ficheiro
        cout << endl;
    }

    string op_airport, op_city;
    getline(cin, op_airport);

    Airport a1;
    for (auto airport:company.getAirports()){
        if (airport.getName() == op_airport)
            a1 = airport;
    }

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

    cout << "====================Agencia Voe Connosco====================="<<endl;
    cout<<"-Bem vindo!"<<endl;
    cout<<"-Selecione a operacao desejada inserindo a letra respetiva."<<endl;
    cout<<"A)Tabelas de Voos"<<endl;
    cout<<"B)Tabela de Aeroportos"<<endl;
    cout<<"C)Comprar Bilhetes"<<endl;
    cout<<"D)Listas de Passageiros"<<endl;
    cout<<"E)Listas de Locais de Transporte Proximos"<<endl;
    cout<<"F)Tarefas a Realizar"<<endl;
    cout<<"G)Tarefas Realizadas"<<endl;
    cout<<"H)Atualizar Viagem"<<endl;
    main_menu(company);

    return 0;
}
