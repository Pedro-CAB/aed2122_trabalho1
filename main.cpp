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
    cout << "==============================    Airline Database    =============================="<<endl;
    cout << "Type 'help' for a list of commands"<<endl;
    cout << ">";
    main_menu();
}
