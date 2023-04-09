#include "../include/Prisoner.h"

//Construtores
Prisoner::Prisoner(): Person(), crime(desconhecido){}
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
        
virtual Prisoner::~Prisoner(){}
