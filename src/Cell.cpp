#include "../include/Cell.h"

//Construtor
Cell::Cell() {}

//Register prisoner
void Cell::addPrisoner(Prisoner prisoner) {
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

//number of prisoners
int Cell::numberPrisoners() {
  return prisoners.size();
}

//is Full
bool Cell::isFull() {
  if(numberPrisoners() == n_LIMITE) 
    return true;
  else 
    return false;
}

//Remove prisoner
void Cell::removePrisoner(string cpf) {
  //Verifica se o prisioneiro está contido
  bool isContained = isPrisonerContained(cpf);

  if(isContained) {
    for(int i = 0; i < prisoners.size(); i++) {
      if(prisoners[i]->getCPF() == cpf) {
        prisoners.erase(prisoners.begin() + i);
        break;
      }
    }
  }
}

//isPrisonerContained
bool Cell::isPrisonerContained(string cpf) {
  bool isContained = false;

  for(Prisoner *prisoner: prisoners) {
    if(prisoner->getCPF() == cpf) {
      isContained = true;
      break;
    }
  }

  return isContained;
}

//Destrutor
Cell::~Cell() {}