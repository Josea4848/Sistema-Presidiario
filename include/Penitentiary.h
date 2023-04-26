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
        // === Construtor ===
        Penitentiary();

        // === Gets ===
        Employee getEmployee(int emplIndex);
        Cell* getCell(int cellsIndex);

        // === Register ===
        void registerEmployee(Employee employee);
        void registerPrisoner(Prisoner prisoner, int indexCell);

        // === Update === 
        //Employee
        void updateEmployeeName(string cpf, string name);
        void updateEmployeeOffice(string cpf, string office);
        void updateEmployeeAge(string cpf, int age);
        void updateEmployeeWage(string cpf, double wage);
        void updateEmployeeWorkLoad(string cpf, int workLoad);
        //Prisoner
        void updatePrisonerName(string cpf, string name);
        void updatePrisonerAge(string cpf, int age);
        void updatePrisonerCrime(string cpf, string crime);

        // === Delete === 
        void deleteEmployee(string cpf);
        void deletePrisoner(string cpf);
        
        //Is employee contained
        bool isEmployeeContained(string cpf);

        //Is prisoner
        bool isPrisoner(string cpf);

        // === Destrutor ===
        virtual ~Penitentiary();
    
    private:
        vector<Employee*> employees;
        Cell cells[n_CELLS];
};

#endif