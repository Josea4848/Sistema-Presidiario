#ifndef Person_H
#define Person_H

#pragma once
#include <string>

using namespace std;

//Classe abstrata

class Person
{
public:
    /*
    bool ppl -> Person privada de liberdade (true ou false)
    */

    Person();
    Person(string name, string cpf, string skinColor, char sexo, int idade, bool ppl);

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

    //PPL
    virtual void setPPL(bool ppl);
    virtual bool isPPL();

protected:
    string name, cpf, skinColor;
    char sex;
    int age;
    bool ppl;
};

#endif