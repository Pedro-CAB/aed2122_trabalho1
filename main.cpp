#include <iostream>

using namespace std;

void main_menu(){
    string choice;
    cin>>choice;
    if (choice == "help"){
        cout << "This should return a list of commands for the user."<<endl;
    }
}
int main() {
    ifstream i_file_planes, i_file_passengers, i_file_flight, i_file_airport;
    ofstream o_file_planes, o_file_passengers, o_file_flight, o_file_airport;
    vector<Airport> airports;
    int op;

    //primeiro vamos começar por ler e guardar todas as informações de todos os ficheiros
    /*
    if (i_file_planes.is_open()){
        while (!i_file_planes.eof()){

        }

    } */
    //O FICHEIRO DO AEROPORTO SÓ VAI TER O NOME DO AEROPORTO
    if (i_file_airport.is_open()){
        while (!i_file_airport.eof()){
            string name;
            getline(i_file_airport, name);
            Airport a(name);
            airports.push_back(a);
            //já implementei o operador <
        }
    }
    sort(airports.begin(), airports.end()); //ordenar o vetor por ordem alfabética

    //decidir como é que vamos organizar os nossos ficheiros de voos, se fazemos um por cada cidade ou
    //todos na mesma e a primeira linha de indica a cidade de cada aeroporto ou algo do género
    if (i_file_flight.is_open()){
        while (!i_file_flight.eof()){
            string line_flight;
            getline(i_file_flight, line_flight);

            stringstream s_flight(line_flight);
            string number, duration, date, origin, destination;
            getline(s_flight, number, ',');
            int num = stoi(number);
            getline(s_flight, duration, ',');
            float d = stof(duration);
            getline(s_flight, date, ',');
            getline(s_flight, origin, ',');
            getline(s_flight, destination, ',');
            Flight f(num, d, date, origin, destination);
        }
    }

    cout << "Bem-vindo à Agência Voa Connosco! :)" << endl;

    cout << "Escolhe um dos nossos aeroportos para poderes prosseguir: " << endl;
    //Lista de aeropotos;

    if (i_file_airport.is_open()){
        while (!i_file_airport.eof()){
            string s_airport;
            getline (i_file_airport, s_airport);
            cout << s_airport << endl;
        }
    }

    string op_airport;
    getline(cin, op_airport);

    //TIVE DE ELIMINAR OS OUTROS PARÂMETROS PARA CONSEGUIR CRIAR O AEROPORTO
    Airport a(op_airport);
    //dependendo do aeroporto que o utilizador escolhe vamos ter ficheiros diferentes

    cout << "Menu das operações:" << endl;
    cout << "1 - Mostrar os voos" << endl;
    cout << "2 - Comprar bilhete e registar-se como passageiro" << endl;
    cout << "3 - Registar-se como passageiro " << endl;
    cout << "4 - Mostra a lista de passageiros " << endl;
    cout << "5 - Sair" << endl;

    cout << "Escolha a opção do menu que pretende " << endl;
    cin >> op;


    switch (op) {
        case 1:{    //mostra os voos do aeroporto op_airport
            string line_flight; //só temos que mudar o nome do ficheiro para consehir distinguir os aeroportos

            cout << "==================== Flight =================================" << endl;
            //formato do ficheiro: nvoo,duration,date,origin,destination
            if (i_file_flight.is_open()){
                while (!i_file_flight.eof()){
                    getline(i_file_flight, line_flight);

                    //separa a linha a parte do delimitador ',' os diferentes dados presentes no ficheiro
                    stringstream s(line_flight);
                    string number_i, duration, date, origin, destination;
                    getline(s, number_i, ',');
                    int number_f = stoi(number_i);
                    getline(s, duration, ',');
                    float duration_f = stof(duration);
                    getline(s, date, ',');
                    getline(s, origin, ',');
                    getline(s, destination, ',');

                    //controi um objeto voo que vai ser adicinado ao vector de voos
                    Flight f(number_f, duration_f, date, origin, destination);
                    //ASSIM, JÁ NÃO É PRECISO AQUELA FUNÇÃO DE ADICIONAR VOOS
                    //PROBLEMA AQUI PORQUE TEMOS QUE CRIAR PRIMEIRO UM OBJETO DO TIPO AIRPORT
                    a.flights.push_back(f);

                    cout << number_f << "   " << duration << "  " << date << "  " << origin << "    " << destination << endl;
                }
            }
    }

    case 2: {
        //se calhar o número do voo devia ser uma string
        int op_voo;
        string name_p;
        cout << "Por favor, coloque o seu nome para poder prosseguir com a operação" << endl;
        getline(cin, name_p);
        cout << "Escolha o número do voo para o qual pretende comprar bilhete" << endl;
        cin >> op_voo;

        for (auto f: a.flights) {
            if (f.getNumber() == op_voo) {
                Ticket t(f);
                Passenger p(name_p, t);
                //deviamos ter agora um vector pou assim de passageiros para podermos guardar estes dados
            }
        }

        //se o passegeiro conseguiu comprar o bilhete, temos que escrever no ficheiro o nome dele
        //para aparecer na lista de passageiros desse voo

    }

    case 3: {   //mostra a lista de passageiros, decidir se é só imprime só o nome ou o bilhete também
        cout << "===================== Passengers ===================";
        if (i_file_passengers.is_open()){
            while (!i_file_passengers.eof()){
                string line_passengers;
                getline (i_file_passengers, line_passengers);
                cout << line_passengers << endl;
            }
        }
    }
}



}
