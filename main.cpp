#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Company.h"

using namespace std;
void main_menu(), go_back();



void flight_menu(){
    cout<< "<MENU DE VOOS COM OPCOES POR IMPLEMENTAR>"<<endl;
}

void main_menu(){
    string choice;
    cin>>choice;
    if (choice == "A"){
        cout << "-Selecione uma opcao:"<<endl;
        cout << "A)Ver todos os voos da companhia"<<endl;
        cout << "B)Ver todos os voos que partem de um aeroporto"<<endl;
        cout << "C)Ver todos os voos que chegam a um aeroporto"<<endl;
        flight_menu();
    }
    else if (choice == "B"){
        cout << "<DEVE MOSTRAR TABELA DE TODOS OS AEROPORTOS DA COMPANHIA>"<<endl;
        cout << "-Insira 0 para voltar ao menu principal"<<endl;
    }
    else if (choice == "C"){
        cout << "<IMPLEMENTAR FUNÇÃO DE COMPRA DE BILHETES>"<<endl;
    }
    else if (choice == "D"){
        cout << "<IMPLEMENTAR TABELA DE PASSAGEIROS>"<<endl;
    }
    else if (choice == "E"){
        cout << "<IMPLEMENTAR TABELA DE LOCAIS DE TRANSPORTE>"<<endl;
    }
    else if (choice == "F"){
        cout << "<IMPLEMENTAR TABELA DE TAREFAS A REALIZAR>"<<endl;
    }
    else if (choice == "G"){
        cout << "<IMPLEMENTAR TABELA DE TAREFAS REALIZADAS>"<<endl;
    }
    else if (choice == "H"){
        cout << "<IMPLEMENTAR ATUALIZAÇÃO DE VIAGEM>"<<endl;
    }
    else{
        cout << "ERRO: Input Inválido. Tente novamente."<<endl;
        main_menu();
    }
}
int main() {
    Company company = Company();
    //TODOS OS OBJETOS CARREGADOS DEVEM SER INSERIDOS NOS VETORES DA COMPANY E DENTRO DOS OBJETOS QUE OS CONTÊM
    /*
    ifstream i_file_planes, i_file_passengers, i_file_flight, i_file_airport;
    ofstream o_file_planes, o_file_passengers, o_file_flight, o_file_airport;
    vector<Airport> airports;
    int op;

    //O FICHEIRO DO AEROPORTO SÓ VAI TER O NOME DO AEROPORTO
     Nome, sitio, Tipo, Distância ao aeroporto, Horário
    if (i_file_airport.is_open()){
        while (!i_file_airport.eof()){
            string info_airport, info_transp, info_bag;       //contém o nome, tipo, distância, horário
            getline(i_file_airport, info_airport);

            string name, city;
            stringstream s_airport(info_airport);
            getline(s_airport, name);
            getline(s_airport, city);

            Airport a(name, city);

            stringstream s_transp(info_transp);

            while (s_transp.good()){
                string name_t, type, distance, s;
                vector<string> schedule;

                //enquanto o caracter delimitar for diferente de -
                getline(s_transp, name_t);
                getline(s_transp, type);
                getline(s_transp, distance);
                float d = stof(distance);
                while (getline(s_transp, s, ',')){  //temos que acrescentar restrição

                }
            }


            airports.push_back(a);  //no final de tudo adicionamos a ao vector
        }
    }
    sort(airports.begin(), airports.end()); //ordenou os aeroportos por ordem alfabética

    cout << "Bem-vindo a Agencia Voa Connosco! :)" << endl;

    cout << "Escolhe um dos nossos aeroportos para poderes prosseguir: " << endl;
    for (auto airport: airports)
        cout << airport.getName() << " " << airport.getCity();  //lista todos os aeroportos que estão no ficheiro

    string op_airport, op_city;
    getline(cin, op_airport);   //utilizador coloca o nome do aeroporto
    Airport a;                          //precisamos de ter a cidade lara conseguir construir um Airport
    for (auto airport:airports){
        if (airport.getName() == op_airport)
            a = airport;
    }
    //com o nome do aeroporto temos que criar o nome dos ficheiros dos voos e dos passageiros

    //AVIÃO


     * Matrícula, Ocupação Máxima, lista de tarefas a fazer, lista de
     * tarefas realizadas, plano de voo

    string name_file_plane = a.getName() + "plane.txt";
    i_file_planes.open(name_file_plane);

    if (i_file_planes.is_open()){
        while (!i_file_planes.eof()){
            string info_plane, info_services_to_do, info_services_done, info_done, info_planes;
            getline(i_file_planes, info_plane);
            string matricula, ocup_max;
            stringstream s_plane(info_plane);
            getline(s_plane, matricula);
            getline(s_plane, ocup_max);
            int o_max = stoi(ocup_max);
            Plane p(matricula, o_max);

            getline(i_file_planes,info_services_to_do);
            stringstream s_services(info_services_to_do);
            //VER ISTO PORQUE SE CALHAR NEM É PRECISO DOIS DELIMITADORES
            //TEMOS SÓ UM, MAS COMO SABEMOS QUANTAS VARIÁVEIS TEM, NÃO É PRECISO
            while (getline()){   //tipo, data e empregado VER A CONDIÇÃO DE TERMINAR
                string type, date, employee;
                getline(s_services, type, ',');
                getline(s_services, date, ',');
                getline(s_services, employee, ',');
                Service c(type, date, employee);
                p.getToDo().push(c);
            }

            getline(i_file_planes, info_services_done);
            stringstream s_services_done(info_services_done);
            while (true){
                string type, date, employee;
                getline(s_services_done, type, ',');
                getline(s_services_done, date, ',');
                getline(s_services_done, employee, ',');
                Service c(type, date, employee);
                p.getDone().push(c);

            }


        }
    }


    //VOOS
    string name_file_flight = a.getName() + "flight.txt";
    i_file_flight.open(name_file_flight);   //tenta abrir o ficheiro

    if (i_file_flight.is_open()){
        while (i_file_flight.eof()){
            string line_flight;
            getline(i_file_flight, line_flight);


            stringstream str_flight(line_flight);
            string snumber, date, arrival, departure, origin, destination;
            getline(str_flight, snumber, ',');
            int number = stoi(snumber);
            getline(str_flight, date, ',');
            getline(str_flight, arrival, ',');
            getline(str_flight, departure, ',');
            getline(str_flight, origin, ',');

            Airport a1, a2; //porque o flight recebe dois objetos airport como parametro
            for (auto airport:airports){
                if (airport.getCity() == origin)
                    a1 = airport;
                if (airport.getCity() == destination)
                    a2 = airport;
                break;
            }

            Flight f(number, date, arrival, departure, a1, a2);

        }
    }

    cout << "Menu das operacoes:" << endl;
    cout << "1 - Mostrar os voos" << endl;
    cout << "2 - Comprar bilhete e registar-se como passageiro" << endl;
    cout << "3 - Registar-se como passageiro " << endl;
    cout << "4 - Mostra a lista de passageiros " << endl;
    cout << "5 - Sair" << endl;

    cout << "Escolha a opcao do menu que pretende " << endl;
    cin >> op;



    return 0; */
    //Amostra de Dados para testar
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
    TTLocation t6 = TTLocation("Praça de Humberto Delgado","Taxi",0.2,schedule);
    TTLocation t7 = TTLocation("Paragem CR7","Autocarro",0.2,schedule);
    TTLocation t8 = TTLocation("Praça do Funchal","Taxi",0.2,schedule);

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





    cout << "====================Agência Voe Connosco====================="<<endl;
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
    main_menu();
}
