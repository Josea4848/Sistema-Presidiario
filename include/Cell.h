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

    //Exibe prisioneiros
    void printPrisoners();
    
    //Get prisoner by index
    Prisoner* getPrisoner(int index);

    //IsFull
    bool isFull();

    //Numero de prisioneiros atual
    int numberPrisoners();

    //Registrar prisioneiro
    void addPrisoner(Prisoner prisoner);

    //Update Prisioneiro
    void modifyName(string cpf, string name);
    void modifyAge(string cpf, int age);
    void modifyCrime(string cpf, string crime);

    //Remove prisioneiro
    void removePrisoner(string cpf);

    //isPrisonerContained
    bool isPrisonerContained(string cpf);

    //Destrutor
    ~Cell();

private:
    vector<Prisoner*> prisoners;
};

#endif