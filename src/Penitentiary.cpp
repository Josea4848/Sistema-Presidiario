#include "../include/Penitentiary.h"

//Construtor
Penitentiary::Penitentiary(){
  emplIndex = 0;
  cellsIndex = 0;

  for(int i = 0; i < n_EMPLOYERS; i++){
    employers[i] = new Employee(); 
  }

  for(int j = 0; j < n_CELLS; j++) {
    cells[j] = new Cell();
  }
}

//Register emplyee
void Penitentiary::registerEmployee(Employee employee) {
  bool possui = false;

  //Verifica se já está contido
  for(int i; i < n_EMPLOYERS; i++) {
    if(employers[i]->getCPF() == employee.getCPF()) 
      possui = true;
  } 

  if(!possui) {
    employers[emplIndex++] = new Employee(employee.getName(), employee.getCPF(), employee.getSkinColor(), employee.getSex(), employee.getAge(), employee.isPDL(), employee.getOffice(), employee.getWage(), employee.getWorkLoad());
  }
}
//Get Employee
Employee Penitentiary::getEmployee(int emplIndex){
  return *employers[emplIndex];
}

//Get Prisoner
Cell Penitentiary::getCell(int cellsIndex){
  return *cells[cellsIndex];
}

//Register prisoner
void Penitentiary::registerPrisoner(Prisoner prisoner,) {

}

//Destrutor
Penitentiary::~Penitentiary(){}
