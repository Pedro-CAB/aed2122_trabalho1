//
// Created by Aulas FEUP on 16/12/2021.
//

#include "LuggageCar.h"
LuggageCar::LuggageCar(int c, int n, int m) {
    this->c = c;
    this->n = n;
    this->m = m;
    car = {};
    while (car.size()<c){
        vector<stack<bool>> empty_vec = {};
        car.push_back(empty_vec);
    }
    for (vector<stack<bool>> wagon:car){
        while (wagon.size()<n){
            stack<bool> emptyPile = {};
            wagon.push_back(emptyPile);
        }
    }
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