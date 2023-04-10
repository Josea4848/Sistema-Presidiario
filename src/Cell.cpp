#include "../include/Cell.h"

//Construtor
Cell::Cell() {
  index = 0;
  for(int i = 0; i < LIMITE; i++) {
    //Medida de segurança de código, garante que não haverá "espaços vazios"
    prisoners[i] = new Prisoner();
  }
}

//Register prisoner
void Cell::registerPrisoner(Prisoner prisoner) {
  bool possui = false;
  //Verifica se o CPF já está contido no vetor
  for(int i = 0; i < LIMITE; i++) {
    if(prisoners[i]->getCPF() == prisoner.getCPF()) 
      possui = true;
  }
  
  //Caso não esteja contido, será criado um novo objeto no vetor
  if(!possui) {
    prisoners[index++] = new Prisoner(prisoner.getName(), prisoner.getCPF(), prisoner.getSkinColor(), prisoner.getSex(), prisoner.getAge(), prisoner.isPDL(), prisoner.getCrime());
  } 
}

//Get prisoner
Prisoner Cell::getPrisoner(int index) {
  return *prisoners[--index];
}

//Print prisoners
void Cell::printPrisoners() {
  for(int i = 0; i < LIMITE; i++) {
    if(prisoners[i]->getName() != desconhecido) {
      prisoners[i]->printAttributes();
    }
  }
}

//is Full
bool Cell::isFull() {
  for(int i = 0; i < LIMITE; i++) {
    if(prisoners[i]->getName() == desconhecido)
      return false;
  }
}

//Destrutor
Cell::~Cell() {}

