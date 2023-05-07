#include "../include/Penitentiary.h"

//Construtor
Penitentiary::Penitentiary(){
  //Inicializa todas as celas
  for(int i = 0; i < n_CELLS; i++) {
    cells[i] = new Cell();
  }
}

//Get Employee
Employee Penitentiary::getEmployee(int emplIndex){
  if(emplIndex < employees.size())
    return *employees[emplIndex];
  else 
    return Employee();
}
//Get Prisoner
Cell* Penitentiary::getCell(int cellsIndex){
    return cells[cellsIndex];
}

//Register employee
void Penitentiary::registerEmployeeCSV(string data) {
  stringstream linhaStream(data);
  string name, cpf, skinColor, office;
  string sex;
  string age, workLoad;
  string wage;
  string pdl;

  //Name
  getline(linhaStream, name, ';');
  //CPF
  getline(linhaStream, cpf, ';');
  //SkinColor
  getline(linhaStream, skinColor, ';');
  //Sex
  getline(linhaStream, sex, ';');
  //Age
  getline(linhaStream, age, ';');
  //pdl
  getline(linhaStream, pdl, ';');
  //office
  getline(linhaStream, office, ';');
  //workLoad
  getline(linhaStream, workLoad, ';');
  //Wage
  getline(linhaStream, wage);

  registerEmployee(Employee(name, cpf, skinColor, sex[0], stoi(age), (pdl == "1") ? true : false, office, stod(wage), stoi(workLoad)));
}

void Penitentiary::registerPrisonerCSV(string data) {
  stringstream linhaStream(data);
  string name, cpf, skinColor, crime, sex, age, pdl, cell;

  //Name
  getline(linhaStream, name, ';');
  //CPF
  getline(linhaStream, cpf, ';');
  //SkinColor
  getline(linhaStream, skinColor, ';');
  //Sex
  getline(linhaStream, sex, ';');
  //Age
  getline(linhaStream, age, ';');
  //pdl
  getline(linhaStream, pdl, ';');
  //Crime
  getline(linhaStream, crime, ';');
  //Cell
  getline(linhaStream, cell);

  registerPrisoner(Prisoner(name, cpf, skinColor, sex[0], stoi(age), (pdl == "1") ? true : false, crime), stoi(cell));
}

void Penitentiary::registerEmployee(Employee employee) {
  if(employee.getAge() < MIN_AGE) {
    cerr << "Idade mínima é de " << MIN_AGE << " anos, não é possível realizar o cadastro!\n";
  }
  //Se for prisioneiro
  else if(isPrisoner(employee.getCPF())) {
    cerr << "O usuário é um prisioneiro!\n";
  }
  //Se não está contido nos funcionários e nem é prisioneiro, um novo funcionário é cadastrado
  else if(!isEmployeeContained(employee.getCPF())) {
    employees.push_back(new Employee(employee.getName(), employee.getCPF(), employee.getSkinColor(), employee.getSex(), employee.getAge(), employee.isPDL(), employee.getOffice(), employee.getWage(), employee.getWorkLoad()));

    cout << "Funcionário(a) cadastrado(a) com sucesso!\n";
  } else {
    cerr << "O Funcionário(a) com CPF: " << employee.getCPF() <<" já está cadastrado, insira um CPF válido!\n";
  }
}

//Register prisoner
//Recebe dados do prisioneiro e o índice da cela que será cadastrado
void Penitentiary::registerPrisoner(Prisoner prisoner, int indexCell) {
  if(indexCell >= n_CELLS || indexCell < 0) {
    cerr << "Número de cela inválida! Não foi possível realizar o cadastro!\n";
  }
  else if(prisoner.getAge() < MIN_AGE) {
    cerr << "Idade mínima é de " << MIN_AGE << " anos, não é possível realizar o cadastro!\n";
  }
  else if(isEmployeeContained(prisoner.getCPF())) {
    cerr << "O usuário é um funcionário, não é possível cadastrar!\n";
  }  
  //Verifica se o prisioneiro já está em alguma cela (verifica todas as celas)
  else if(isPrisoner(prisoner.getCPF())) {
    cerr << "Já é prisioneiro!\n";
  }
  //Se o prisoneiro não está em nenhuma cela e nem é funcionário, então será registrado
  else {
    cells[indexCell]->addPrisoner(prisoner);
  }
} 

//Update employee
  //Name  
void Penitentiary::updateEmployeeName(string cpf, string name) {
  for(int i = 0; i < employees.size(); i++) {
    if(employees[i]->getCPF() == cpf) 
      employees[i]->setName(name);
      cout << "Nome atualizado com sucesso!\n";
      break;
  }
}
  //Office
void Penitentiary::updateEmployeeOffice(string cpf, string office) {
  for(int i = 0; i < employees.size(); i++) {
    if(employees[i]->getCPF() == cpf) {
      employees[i]->setOffice(office);
      cout << "Função atualizada com sucesso!\n";
      break;
    }
  }
}
  //Age
void Penitentiary::updateEmployeeAge(string cpf, int age) {
  if(age >= MIN_AGE) {
    for(int i = 0; i < employees.size(); i++) {
      if(employees[i]->getCPF() == cpf) {
        employees[i]->setAge(age);
        cout << "Idade atualizada com sucesso!\n";
        break;
      }
    }
  } else {
    cerr << "Idade inválida!\n";
  }
}
  //Wage
void Penitentiary::updateEmployeeWage(string cpf, double wage) {
  if(wage > 0) {
    for(int i = 0; i < employees.size(); i++) {
      if(employees[i]->getCPF() == cpf) {
        employees[i]->setWage(wage);
        cout << "Salário atualizado com sucesso!\n";
        break;
      }
    }
  }
    
}
  //WorkLoad
void Penitentiary::updateEmployeeWorkLoad(string cpf, int workLoad) {
  for(int i = 0; i < employees.size(); i++) {
    if(employees[i]->getCPF() == cpf) {
      employees[i]->setWorkLoad(workLoad);
      cout << "Carga Horária atualizada com sucesso!\n";
      break;
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
      if(cells[i]->isPrisonerContained(cpf)) {
        cells[i]->modifyName(cpf, name);
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
      if(cells[i]->isPrisonerContained(cpf)) {
        cells[i]->modifyAge(cpf, age);
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
      if(cells[i]->isPrisonerContained(cpf)) {
        cells[i]->modifyCrime(cpf, crime);
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
        cout << "Funcionário(a) removido(a) com sucesso!\n";
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
      if(cells[i]->isPrisonerContained(cpf)) {
        cells[i]->removePrisoner(cpf);
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
    if(cells[i]->isPrisonerContained(cpf)) 
      return true;
  }
  //Se o prisioneiro não estiver em nenhuma cela
  return false;
}
//Summary
void Penitentiary::prisonersNumbersSummary() {
  cout << "======== Número de presidiários =======\n";
  for(int i = 0; i < n_CELLS; i++) {
    cout << "Cela C" << i << ": ";
    //Exibe pontos para cada prisioneiro
    for(int j = 0; j < cells[i]->numberPrisoners(); j++) {
      cout << "∎";
    }
    //Exibe espaços vazio
    for(int k = 0; k < n_LIMITE - cells[i]->numberPrisoners(); k++) {
      cout << " ";
    }

    cout << " [" << cells[i]->numberPrisoners() << "/" << n_LIMITE << "]\n";
  }

  cout << "\tTotal: " << prisonersNumber() << " de " << n_LIMITE*n_CELLS << "[" << (double)prisonersNumber()/(n_LIMITE*n_CELLS)*100 << "%]\n";
}
void Penitentiary::employeesSummary() {
  cout << "========= Informações dos funcionários =========\n\n";

  cout << "| Quantidade de funcionários: " << employees.size() << endl;
  cout << "\n| Média salarial: R$" << wageTotal()/employees.size() << endl;
  cout << "\n| Custo salarial: R$" << wageTotal() << endl; 

  int indexMaior = 0, indexMenor = 0;

  for(int i = 0; i < employeesNumber(); i++) {
    //Maior salário
    if(employees[i]->getWage() > employees[indexMaior]->getWage())
      indexMaior = i;
    //Menor salário
    if(employees[i]->getWage() < employees[indexMenor]->getWage())  
      indexMenor = i;
  }

  cout << "\n| Maior salário: R$" << employees[indexMaior]->getWage() << endl;
  cout << "\n| Menor salário: R$" << employees[indexMenor]->getWage() << endl;
}


//toString
string Penitentiary::toStringEmployee(int index) {
  if(index < employeesNumber()) {
    return employees[index]->strAttributes();
  }    
  else {
    cerr << "Funcionário(a) não existe\n";
    return "null\n";
  }
}
string Penitentiary::toStringPrisoner(int cellIndex, int index) {
  if(cellIndex < n_CELLS && index < getCell(cellIndex)->numberPrisoners()) {
    return getCell(cellIndex)->getPrisoner(index)->strAttributes() + ";" + to_string(cellIndex);
  } else {
    cerr << "Prisioneiro não existe!\n";
    return "null\n";
  }
}

//Numbers
int Penitentiary::employeesNumber() {
  return employees.size();
}
int Penitentiary::prisonersNumber() {
  int total = 0;

  for(int i = 0; i < n_CELLS; i++) {
    total += cells[i]->numberPrisoners();
  }

  return total;
}

//Search
void Penitentiary::searchByName(string name) {
  cout << "========== Procura por \"" << name << "\" ==========" << endl; 
  int total = 0;

  //Procurando nos funcionários
  for(Employee *employee: employees) {
    if(employee->getName().find(name) != string::npos) {
      cout << "• " << employee->getName() << " | CPF: " << employee->getCPF() << "| Funcionário(a)\n";
      total++;
    }
  }
  //Procurando nos prisioneiros
  for(Cell *cell: cells) {
    for(int i = 0; i < cell->numberPrisoners(); i++) {
      string namePrisoner = cell->getPrisoner(i)->getName();
      if(namePrisoner.find(name) != string::npos) {
        cout << "• " << name << " | CPF: " << cell->getPrisoner(i)->getCPF() << " | Prisioneiro\n";
        total++;
      }
    }
  }

  cout << "\n| Total de ocorrências: " << total << endl;
}

//listPrisoners
void Penitentiary::listPrisoners(int cell) {
  if(cell < n_CELLS && cell >= 0) {
    cout << "========== Cela " << cell << " ==========\n";
    cells[cell]->printPrisoners();
  } else {
    cerr << "Cela inválida\n";
  }   
}

//total Salary
double Penitentiary::wageTotal() {
  double total = 0;
  for(Employee *employee: employees) {
    total += employee->getWage();
  }

  return total;
}

//Destrutor
Penitentiary::~Penitentiary() {
  //delete employees
  for(int i = 0; i < employees.size(); i++) {
    delete employees[i];
  }
  //delete cells
  for(int i = 0; i < n_CELLS; i++) {
    delete cells[i];
  }
}