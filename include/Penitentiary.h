#ifndef Penitentiary_h
#define Penitentiary_h

#pragma once
#include "Employee.h"
#include "Prisoner.h"
#include "Cell.h"

//Passível de alteração sobre os vetores
#define n_CELLS 10
#define n_EMPLOYERS 10


class Penitentiary
{
    public:
        //Construtor
        Penitentiary();

        //Register
        void registerEmployee(Employee employee);
        void registerPrisoner(Prisoner prisoner);
      
        //Gets
        Employee getEmployee(int emplIndex);
        Cell getCell(int cellsIndex);

        //Destrutor
        virtual ~Penitentiary();

    private:
        Employee *employers[n_EMPLOYERS];
        Cell *cells[n_CELLS];
        int emplIndex;
        int cellsIndex;
};

#endif
