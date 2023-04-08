#ifndef Prisoner_H
#define Prisoner_H

#pragma once
#include "Person.h"

class Prisoner  : public Person
{
    public:
       
        Prisoner();
        Prisoner(string);
        Prisoner(string name, string cpf, string skinColor, char sex, int age, bool pdl);
        
        //Crime
        void setCrime(string);
        string getCrime();
        
        virtual ~Detento();

    protected:
        string crime;
};

#endif 