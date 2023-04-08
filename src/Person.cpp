#include "../include/Person.h"

//Construtores
Person::Person() : Person(desconhecido, desconhecido, desconhecido, '0', 0, false) {}
Person::Person(string name, string cpf, string skinColor, char sex, int age, bool pdl) {
    setName(name);
    setCPF(cpf);
    setSkinColor(skinColor);
    setSex(sex);
    setAge(age);
    setPDL(pdl);
}

//Name
void Person::setName(string name) {
  if(name == ""){
    this->name = campoInvalido;
  }else
    this->name = name;
}
string Person::getName() {
  return name;
}

//CPF
void Person::setCPF(string cpf) {
  if(cpf == ""){
      this->cpf = campoInvalido;
   }else
      this->cpf = cpf;
}
string Person::getCPF() {
  return cpf;
}

//skinColor
void Person::setSkinColor(string skinColor) {
    if(skinColor == "")
        skinColor = campoInvalido;
    else
        this->skinColor = skinColor;
}
string Person::getSkinColor() {
  return skinColor;
}

//Sex
void Person::setSex(char sex) {
  if(toupper(sex) != 'M' && toupper(sex) != 'F')
    this->sex = '*';
  else
    this->sex = sex;
}
char Person::getSex() {
  return sex;
}

//Age
void Person::setAge(int age) {
  if (age < 0){
      this->age = 0;
  }else
      this->age = age;
}
int Person::getAge() {
  return age;
}

//PDL
void Person::setPDL(bool pdl) {
    if(pdl == true)
        this->pdl = true;
    else
        this->pdl = false;
}
bool Person::~isPDL() {
  return pdl;
}

Person::~Person(){}

