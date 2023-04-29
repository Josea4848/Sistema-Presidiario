#include "../include/Prisoner.h"
#include <iostream>

//Construtores
Prisoner::Prisoner(): crime(desconhecido){}
Prisoner::Prisoner(string crime){
  setCrime(crime);
}
Prisoner::Prisoner(string name, string cpf, string skinColor, char sex, int age, bool pdl, string crime): Person(name, cpf, skinColor, sex, age, pdl){
  setCrime(crime);
 }
        
void Prisoner::setCrime(string crime){
  if(crime == "")
        this->crime = desconhecido;
    else
        this->crime = crime;
}
string Prisoner::getCrime(){
  return crime;
}

string Prisoner::strAttributes(){
  return getName() + "," + getSex() + "," + getCPF() + "," + to_string(getAge()) + "," + getSkinColor() + "," + to_string(isPDL()) + "," + getCrime() + "\n";
}
        
Prisoner::~Prisoner(){}
