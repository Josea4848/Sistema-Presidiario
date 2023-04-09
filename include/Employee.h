#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include "../include/Person.h"

using namespace std;

//Carga horária padrão (Mínima)
const int cargaPadrao = 40;

class Employee : public Person
{
public:
    //Construtores
    Employee();
    Employee(string office, double wage, int workLoad);
    Employee(string name, string cpf, string skinColor, char sexo, int age, bool pdl, string office, double wage, int workLoad);

    //Function
    void setOffice(string office);
    string getOffice();

    //Wage
    void setWage(double wage);
    double getWage();

    //Word Load
    void setWorkLoad(int workLoad);
    int getWorkLoad();  

private:
    string office;
    double wage;
    int workLoad;
};

#endif