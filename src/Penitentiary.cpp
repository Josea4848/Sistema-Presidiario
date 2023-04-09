#include "Penitentiary.h"

Penitentiary::Penitentiary(){}

Penitentiary::Penitentiary(string name, string cpf, string skinColor, char sex, int age, bool pdl,
                      string office, double wage, int workLoad, string crime){
  
for(int i = 0; i < n_EMPLOYERS; i++){
  employers[i] = new Employee(name,cpf,skinColor,sex,age,
                      pdl,office,wage,workLoad);
        }
for(int j = 0; j < n_PRISONERS; j++){
   prisoners[j] = new Prisoner(name,cpf,skinColor,sex,age
                       ,pdl,crime);
    }  
}

Penitentiary::~Penitentiary(){}
