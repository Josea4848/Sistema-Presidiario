#ifndef Penitentiary_h
#define Penitentiary_h

#pragma once
#include <vector>
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

        //Gets
        Employee* getEmployee(int emplIndex);
        Cell* getCell(int cellsIndex);

        //Register
        void registerEmployee(Employee employee);
        void registerPrisoner(Prisoner prisoner, int indexCell);

        //Update
        //void updateEmployee(Employee Employee, string cpf);

        //Delete
        void deleteEmployee(string cpf);
        void deletePrisoner(string cpf);

        //Destrutor
        virtual ~Penitentiary();

        //Is employee contained
        bool isEmployeeContained(string cpf);
    
    private:
        vector<Employee*> employees;
        Cell cells[n_CELLS];
};

#endif