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

void Prisoner::printAttributes(){
  cout << getName() << " " << getSex()<< " " << getCPF() << " " << getAge() << " " << getSkinColor() << " " << isPDL() << " " << getCrime() << endl;
}
        
Prisoner::~Prisoner(){}
