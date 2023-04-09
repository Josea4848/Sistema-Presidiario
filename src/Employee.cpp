#include "../include/Employee.h"
#include <iostream>

//Construtores
Employee::Employee() : Employee(campoInvalido, 0, cargaPadrao) {}
Employee::Employee(string office, double wage, int workLoad) {
  setOffice(office);
  setWage(wage);
  setWorkLoad(workLoad);
}

Employee::Employee(string name, string cpf, string skinColor, char sexo, int age, bool pdl, string office, double wage, int workLoad) : Person(name, cpf, skinColor, sexo, age, pdl){
  setOffice(office);
  setWage(wage);
  setWorkLoad(workLoad);
}

//Function
void Employee::setOffice(string office) {
  if(office == "") {
    this->office = campoInvalido;
  } else {
    this->office = office;
  }
}

string Employee::getOffice() {
  return office;
}

//Wage
void Employee::setWage(double wage) {
  if(wage < 0) {
    this->wage = 0;
  } else {
    this->wage = wage;
  }
}

double Employee::getWage() {
  return wage;
}

//Work Load
void Employee::setWorkLoad(int workLoad) {
  if(workLoad < 0) {
    this->workLoad = cargaPadrao;
  } else {
    this->workLoad = workLoad;
  }
}
int Employee::getWorkLoad() {
  return workLoad;
}

//Exibe atributos
void Employee::printAttributes(){
  cout << getName() << " " << getCPF() << " "  << getSex() << " " << getAge() << " " << isPDL() << " " << getWage() << " " << getWorkLoad() << endl;
}

Employee::~Employee(){}






