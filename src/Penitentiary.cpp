#include "../include/Penitentiary.h"

//Construtor
Penitentiary::Penitentiary(){}

//Register employee
void Penitentiary::registerEmployee(Employee employee) {
  bool possui = false;

  //Verifica se já está contido
  for(Employee *employeeRegistered: employees) {
    if(employeeRegistered->getCPF() == employee.getCPF()) 
      possui = true;
  } 

  //Se não está contido, um novo funcionário é cadastrado
  if(!possui) {
    employees.push_back(new Employee(employee.getName(), employee.getCPF(), employee.getSkinColor(), employee.getSex(), employee.getAge(), employee.isPDL(), employee.getOffice(), employee.getWage(), employee.getWorkLoad()));
  }
}
//Get Employee
Employee* Penitentiary::getEmployee(int emplIndex){
  return employees[emplIndex];
}

//Get Prisoner
Cell* Penitentiary::getCell(int cellsIndex){
  return &cells[cellsIndex];
}

/* //Register prisoner
void Penitentiary::registerPrisoner(Prisoner prisoner, int indexCell) {

} */

//Destrutor
Penitentiary::~Penitentiary(){}