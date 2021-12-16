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
/**
 * Adiciona 1 mala ao carrinho
 * @return true se a adição for bem sucedida ou false se o carrinho estiver cheio
 */
bool LuggageCar::addLuggage() {
    for (auto wagon : car){
        for (auto pile : wagon) {
            if (pile.size() == m)
                continue;
            else
                pile.push(true);
            return true;
        }
    }
    return false;
}
/**
 * Verifica se o carrinho está cheio
 * @return True se está cheio ou False se houver pelo menos um espaço no carrinho
 */
bool LuggageCar::isFull() {
    for (auto wagon : car){
        for (auto pile : wagon){
            if (pile.size() != m)
                return false;
        }
    }
    return true;
}