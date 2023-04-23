#include "../include/Penitentiary.h"

//Construtor
Penitentiary::Penitentiary(){}

//Get Employee
Employee* Penitentiary::getEmployee(int emplIndex){
  if(emplIndex < employees.size())
    return employees[emplIndex];
  else 
    return nullptr;
}

//Get Prisoner
Cell* Penitentiary::getCell(int cellsIndex){
  return &cells[cellsIndex];
}

//Register employee
void Penitentiary::registerEmployee(Employee employee) {
  //Se não está contido, um novo funcionário é cadastrado
  if(!isEmployeeContained(employee.getCPF())) {
    employees.push_back(new Employee(employee.getName(), employee.getCPF(), employee.getSkinColor(), employee.getSex(), employee.getAge(), employee.isPDL(), employee.getOffice(), employee.getWage(), employee.getWorkLoad()));
  }
}

//Register prisoner
//Recebe dados do prisioneiro e o índice da cela que será cadastrado
void Penitentiary::registerPrisoner(Prisoner prisoner, int indexCell) {
  bool contained = false;  
  //Verifica se o prisioneiro já está em alguma cela (verifica todas as celas)
  for(int i = 0; i < n_CELLS; i++) {
    if(cells[i].isPrisonerContained(prisoner.getCPF())) {
      cerr << "O prisioneiro já está em cela, verifique os dados!\n";
      contained = true;
      break;
    }
  }
  //Se o prisoneiro não está em nenhuma cela, então será registrado
  if(!contained) {
    cells[indexCell].addPrisoner(prisoner);
  }
} 

//Delete Employee
void Penitentiary::deleteEmployee(string cpf) {
  //Se o funcionário existir, então a ação será executada
  if(isEmployeeContained(cpf)) { 
    for(int i = 0; i < employees.size(); i++) {
      if(employees[i]->getCPF() == cpf) {
        employees.erase(employees.begin() + i);
        break;
      }
    }
  } else {
    cerr << "Funcionário(a) não encontrado(a), verifique os dados!";
  }  
}
//Delete Prisoner
void Penitentiary::deletePrisoner(string cpf) {
  bool isContained = false;
  for(int i = 0; i < n_LIMITE; i++) {  
    //Caso o prisioneiro não esteja na cela, a ação não será executada
    if(cells[i].isPrisonerContained(cpf)) {
      cells[i].removePrisoner(cpf);
      isContained = true;
      break;
    }
  }
  //Após toda a verificação, caso não haja o prisioneiro
  if(!isContained)
    cerr << "Prisioneiro não encontrado, verifique os dados!";
}

//Is employee contained
bool Penitentiary::isEmployeeContained(string cpf) {
  for(Employee *employee: employees) {
    if(employee->getCPF() == cpf)
      return true;
  }

  //Caso não tenha funcionário com o cpf, é retornado false
  return false;
}

//Destrutor
Penitentiary::~Penitentiary(){}