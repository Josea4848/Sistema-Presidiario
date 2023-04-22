#include "../include/Cell.h"

//Construtor
Cell::Cell() {}

//Register prisoner
void Cell::registerPrisoner(Prisoner prisoner) {
  //Caso a cela não esteja cheia
  if(!isFull()) { 
    bool possui = false;
    //Verifica se o CPF já está contido no vetor
    for(Prisoner *prisonerRegistered: prisoners) {
      if(prisonerRegistered->getCPF() == prisoner.getCPF()) 
        possui = true;
    }
    
    //Caso não esteja contido, será criado um novo objeto no vetor
    if(!possui) {
      prisoners.push_back(new Prisoner(prisoner.getName(), prisoner.getCPF(), prisoner.getSkinColor(), prisoner.getSex(), prisoner.getAge(), prisoner.isPDL(), prisoner.getCrime()));
    } 
  }
  //Se estiver, uma mensagem será disparada na saída de erro
  else { 
    cerr << "A cela está cheia! [" << prisoners.size() << "/" << n_LIMITE << "]\n"; 
  }
}

//Get prisoner
Prisoner* Cell::getPrisoner(int index) {
  //Se o index for maior ou igual que 0 e menor que o tamanho, será retornado o prisoner
  if(index < prisoners.size() && index >= 0)
    return prisoners[index];
  else 
    return nullptr;
}

//Print prisoners
void Cell::printPrisoners() {
  for(Prisoner *prisonerRegistered: prisoners) {
      prisonerRegistered->printAttributes();
  }
}

//is Full
bool Cell::isFull() {
  if(prisoners.size() == n_LIMITE) 
    return true;
  else 
    return false;
}

//Destrutor
Cell::~Cell() {}

