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
    cerr << "O usuário é um funcionário, não é possível cadastrar!\n";
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

//Update employee
  //Name  
void Penitentiary::updateEmployeeName(string cpf, string name) {
  for(int i = 0; i < employees.size(); i++) {
    if(employees[i]->getCPF() == cpf) 
      employees[i]->setName(name);
  }
}
  //Office
void Penitentiary::updateEmployeeOffice(string cpf, string office) {
  for(int i = 0; i < employees.size(); i++) {
    if(employees[i]->getCPF() == cpf) {
      employees[i]->setOffice(office);
    }
  }
}
  //Age
void Penitentiary::updateEmployeeAge(string cpf, int age) {
  for(int i = 0; i < employees.size(); i++) {
    if(employees[i]->getCPF() == cpf) {
      employees[i]->setAge(age);
    }
  }
}
  //Wage
void Penitentiary::updateEmployeeWage(string cpf, double wage) {
  for(int i = 0; i < employees.size(); i++) {
    if(employees[i]->getCPF() == cpf) {
      employees[i]->setWage(wage);
    }
  }
}
  //WorkLoad
void Penitentiary::updateEmployeeWorkLoad(string cpf, int workLoad) {
  for(int i = 0; i < employees.size(); i++) {
    if(employees[i]->getCPF() == cpf) {
      employees[i]->setWorkLoad(workLoad);
    }
  }
}
//Update Prisoner
  //Name
void Penitentiary::updatePrisonerName(string cpf, string name) {
  //Verifica se é um prisioneiro em toda a penitênciária
  if(isPrisoner(cpf)) {
    for(int i = 0; i < n_CELLS; i++) {
      //Caso o prisioneiro esteja na cela
      if(cells[i].isPrisonerContained(cpf)) {
        cells[i].modifyName(cpf, name);
        break;
      }
    }
  } else {
    cerr << "Prisioneiro não encontrado!\n";
  }
}
  //Age
void Penitentiary::updatePrisonerAge(string cpf, int age) {
  //Verifica se é um prisioneiro em toda a penitênciária
  if(isPrisoner(cpf)) {
    for(int i = 0; i < n_CELLS; i++) {
      //Caso o prisioneiro esteja na cela
      if(cells[i].isPrisonerContained(cpf)) {
        cells[i].modifyAge(cpf, age);
        break;
      }
    }
  } else {
    cerr << "Prisioneiro não encontrado!\n";
  }
}
  //Crime
void Penitentiary::updatePrisonerCrime(string cpf,string crime) {
  //Verifica se é um prisioneiro em toda a penitênciária
  if(isPrisoner(cpf)) {
    for(int i = 0; i < n_CELLS; i++) {
      //Caso o prisioneiro esteja na cela
      if(cells[i].isPrisonerContained(cpf)) {
        cells[i].modifyCrime(cpf, crime);
        break;
      }
    }
  } else {
    cerr << "Prisioneiro não encontrado!\n";
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
//Prisoners Numbers
void Penitentiary::prisonersNumbers() {
  cout << "======== Número de presidiários =======\n";
  for(int i = 0; i < n_CELLS; i++) {
    cout << "Cela C" << i << ": ";
    //Exibe pontos para cada prisioneiro
    for(int j = 0; j < cells[i].numberPrisoners(); j++) {
      cout << "∎";
    }
    //Exibe espaços vazio
    for(int k = 0; k < n_LIMITE - cells[i].numberPrisoners(); k++) {
      cout << " ";
    }

    cout << " [" << cells[i].numberPrisoners() << "/" << n_LIMITE << "]\n";
  }
}


//Destrutor
Penitentiary::~Penitentiary(){}