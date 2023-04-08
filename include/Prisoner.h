#ifndef PRISONER_H
#define PRISONER_H

#include "Person.h"

class Prisoner  : public Person
{
    public:
        Prisoner();

        Prisoner(string);

        Prisoner(string name, string cpf, string skinColor, char sex, int age, bool pdl);

        void setCrime(string);

        string getCrime();

        virtual ~Detento();

    private:
        string crime;
};

#endif // DETENTO_H
