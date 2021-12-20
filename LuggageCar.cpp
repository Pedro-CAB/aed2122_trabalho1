//
// Created by Aulas FEUP on 16/12/2021.
//

#include "LuggageCar.h"
LuggageCar::LuggageCar(int c, int n, int m) {
    this->c = c;
    this->n = n;
    this->m = m;
    vector<vector<stack<bool>>> a;
    for (int i = 0; i <c; i++){
        vector<stack<bool>> b;
        for (int j = 0; j < n; j++){
            stack<bool> c;
            b.push_back(c);
        }
        a.push_back(b);
    }
    car = a;
}

int LuggageCar::getC() {return c;}

int LuggageCar::getM() {return m;}

int LuggageCar::getN() {return n;}
/**
 * Adiciona 1 mala ao carrinho
 * @return true se a adição for bem sucedida ou false se o carrinho estiver cheio
 */
bool LuggageCar::addLuggage() {
    for (auto wagon: car) {
        for (auto pile: wagon) {
            if (pile.size() == m)
                continue;
            else {
                pile.push(true);
                return true;
            }
        }
    }
    return false;
}

vector<vector<stack<bool>>> LuggageCar::getCar() {
    return car;
}