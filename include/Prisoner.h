#ifndef Prisoner_H
#define Prisoner_H

#pragma once
#include "Person.h"

class Prisoner  : public Person
{
    public:
       
        Prisoner();
        Prisoner(string crime);
        Prisoner(string name, string cpf, string skinColor, char sex, int age, bool pdl, string crime);
        
        //Crime
        void setCrime(string);
        string getCrime();
        
        virtual ~Prisoner();

    protected:
        string crime;
};

#endif 
