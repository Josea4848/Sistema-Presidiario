#ifndef Person_H
#define Person_H

#pragma once
#include <string>

using namespace std;

const string desconhecido = "Campo Não informado";
const string campoInvalido = "Campo Inválido";

//Classe abstrata

class Person
{
public:
    /*
    bool pdl -> Person deprivied of liberty (true ou false)
    */

    Person();
    Person(string name, string cpf, string skinColor, char sexo, int idade, bool pdl);

    //Name
    virtual void setName(string name);
    virtual string getName();

    //CPF
    virtual void setCPF(string cpf);
    virtual string getCPF();

    //SkinColor
    virtual void setSkinColor(string skinColor);
    virtual string getSkinColor();

    //Sex
    virtual void setSex(char sex);
    virtual char getSex();

    //Age
    virtual void setAge(int age);
    virtual int getAge();

    //PDL
    virtual void setPDL(bool pdl);
    virtual bool isPDL();

protected:
    string name, cpf, skinColor;
    char sex;
    int age;
    bool pdl;
};

#endif
