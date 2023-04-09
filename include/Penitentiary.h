#ifndef Penitentiary_h
#define Penitentiary_h

#pragma once
#include "Employee.h"
#include "Prisoner.h"

//Passível de alteração sobre os vetores
#define n_PRISONERS 10
#define n_EMPLOYERS 10


class Penitentiary
{
    public:
        Penitentiary();

        Penitentiary(string name, string cpf, string skinColor, char sexo, int age, bool pdl,
                      string office, double wage, int workLoad, string crime);

        virtual ~Penitentiary();


    private:
        Employee *employers[n_EMPLOYERS];
        Prisoner *prisoners[n_PRISONERS];

};

#endif
