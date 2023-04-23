#include "../include/Penitentiary.h"

//Construtor
Penitentiary::Penitentiary(){}

//Get Employee
Employee Penitentiary::getEmployee(int emplIndex){
  if(emplIndex < employees.size())
    return *employees[emplIndex];
  else 
    return Employee();
}

//Get Prisoner
Cell* Penitentiary::getCell(int cellsIndex){
  return &cells[cellsIndex];
}

//Update employee
void Penitentiary::updateEmployee(Employee employeeUpdt) {
  //Se o funcionário estiver cadastrado, o dado será atualizado
  if(isEmployeeContained(employeeUpdt.getCPF())) {
    for(int i = 0; i < employees.size(); i++) {
      //Se o CPF do registro e do dado de atualização forem iguais, então a atualização será feita
      if(employees[i]->getCPF() == employeeUpdt.getCPF()) {
        employees[i]->setName(employeeUpdt.getName());
        employees[i]->setSkinColor(employeeUpdt.getSkinColor());
        employees[i]->setWage(employeeUpdt.getWage());
        employees[i]->setWorkLoad(employeeUpdt.getWorkLoad());
        employees[i]->setOffice(employeeUpdt.getOffice());
      }
    }
  }else {
    cerr << "Funcionário não encontrado!\n";
  }
    
}

//Register employee
void Penitentiary::registerEmployee(Employee employee) {
  //Se for prisioneiro
  if(isPrisoner(employee.getCPF())) {
    cerr << "O usuário é um prisioneiro!\n";
  }
  //Se não está contido nos funcionários e nem é prisioneiro, um novo funcionário é cadastrado
  else if(!isEmployeeContained(employee.getCPF())) {
    employees.push_back(new Employee(employee.getName(), employee.getCPF(), employee.getSkinColor(), employee.getSex(), employee.getAge(), employee.isPDL(), employee.getOffice(), employee.getWage(), employee.getWorkLoad()));
  } else {
    cerr << "Funcionário já está cadastrado!\n";
  }
}

//Register prisoner
//Recebe dados do prisioneiro e o índice da cela que será cadastrado
void Penitentiary::registerPrisoner(Prisoner prisoner, int indexCell) {
  if(isEmployeeContained(prisoner.getCPF())) {
    cerr << "É um funcionário!\n";
  }  
  //Verifica se o prisioneiro já está em alguma cela (verifica todas as celas)
  else if(isPrisoner(prisoner.getCPF())) {
    cerr << "Já é prisioneiro!\n";
  }
  //Se o prisoneiro não está em nenhuma cela e nem é funcionário, então será registrado
  else {
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
  }else {
    cerr << "Funcionário(a) não encontrado(a), verifique os dados!\n";
  }  
}
//Delete Prisoner
void Penitentiary::deletePrisoner(string cpf) {
  if(isPrisoner(cpf)) {
    for(int i = 0; i < n_LIMITE; i++) {  
    //Caso o prisioneiro não esteja na cela, a ação não será executada
      if(cells[i].isPrisonerContained(cpf)) {
        cells[i].removePrisoner(cpf);
        break;
      }
    }
  }
  //Após toda a verificação, caso não haja o prisioneiro
  else
    cerr << "Prisioneiro não encontrado, verifique os dados!\n";
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

//Is prisoner, verifica em todas as celas
bool Penitentiary::isPrisoner(string cpf) {
  for(int i = 0; i < n_CELLS; i++) {
    if(cells[i].isPrisonerContained(cpf)) 
      return true;
  }
  //Se o prisioneiro não estiver em nenhuma cela
  return false;
}

//Destrutor
Penitentiary::~Penitentiary(){}