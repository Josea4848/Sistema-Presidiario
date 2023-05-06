#include "../include/Cell.h"

//Construtor
Cell::Cell() {}

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
  for(Prisoner *prisoner: prisoners) {
      cout << "| Nome: " << prisoner->getName() << " | CPF: " << prisoner->getCPF() << " | Idade: " << prisoner->getAge() << " | Crime: " << prisoner->getCrime() << endl << endl;
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
      cout << "Prisioneiro cadastrado com sucesso!\n";
    } 
  }
  //Se estiver, uma mensagem será disparada na saída de erro
  else { 
    cerr << "A cela está cheia! [" << prisoners.size() << "/" << n_LIMITE << "]\n"; 
  }
}

//Update
  //Name
void Cell::modifyName(string cpf, string name) {
  for(int i = 0; i < prisoners.size(); i++) {
    if(prisoners[i]->getCPF() == cpf) {
      prisoners[i]->setName(name);
      cout << "Nome atualizado com sucesso!\n";
      break;
    }
  }
}
  //Age
void Cell::modifyAge(string cpf, int age) {
  if(age >= MIN_AGE) {
    for(int i = 0; i < prisoners.size(); i++) {
      if(prisoners[i]->getCPF() == cpf) {
        prisoners[i]->setAge(age);
        cout << "Idade atualizada com sucesso!\n";
        break;
      }
    }
  } else {
    cerr << "Idade inválida!\n";
  } 
} 
  //Crime
void Cell::modifyCrime(string cpf, string crime) {
  for(int i = 0; i < prisoners.size(); i++) {
    if(prisoners[i]->getCPF() == cpf) {
      prisoners[i]->setCrime(crime);
      cout << "Crime(s) atualizado(s) com sucesso!\n";
      break;
    }
  }
}

//Remove prisoner
void Cell::removePrisoner(string cpf) {
  //Verifica se o prisioneiro está contido
  bool isContained = isPrisonerContained(cpf);

  if(isContained) {
    for(int i = 0; i < prisoners.size(); i++) {
      if(prisoners[i]->getCPF() == cpf) {
        prisoners.erase(prisoners.begin() + i);
        cout << "Prisioneiro removido com sucesso!\n";
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
Cell::~Cell() {
  for(Prisoner *prisoner: prisoners) {
    delete prisoner;
  }
}