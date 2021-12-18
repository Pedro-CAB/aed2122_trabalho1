//
// Created by Aulas FEUP on 16/12/2021.
//

#ifndef PROJECTAED_LUGGAGECAR_H
#define PROJECTAED_LUGGAGECAR_H
#include <stack>
#include <vector>

using namespace std;

class LuggageCar {
public:
    int c,n,m;
    vector<vector<stack<bool>>> car;
    LuggageCar(int c, int n, int m);

    int getC(),getN(),getM();
    bool addLuggage ();
};

#endif //PROJECTAED_LUGGAGECAR_H
