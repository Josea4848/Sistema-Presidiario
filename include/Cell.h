#ifndef CELL_H
#define CELL_H
#define n_LIMITE 10

#pragma once

#include <iostream>
#include <vector>
#include "../include/Prisoner.h"

using namespace std;

class Cell {
public:
    //Construtor
    Cell();
    
    //Registrar prisioneiro
    void registerPrisoner(Prisoner prisoner);

    //Exibe prisioneiros
    void printPrisoners();
    
    //Get prisoner by index
    Prisoner* getPrisoner(int index);

    //IsFull
    bool isFull();

    //Destrutor
    ~Cell();

private:
    vector<Prisoner*> prisoners;
};

#endif
