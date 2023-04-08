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
  this->name = name;
}
string Person::getName() {
  return name;
}

//CPF
void Person::setCPF(string cpf) {
  this->cpf = cpf;
}
string Person::getCPF() {
  return cpf;
}

//skinColor
void Person::setSkinColor(string skinColor) {
  this->skinColor = skinColor;
}
string Person::getSkinColor() {
  return skinColor;
}

//Sex
void Person::setSex(char sex) {
  this->sex = sex;
}
char Person::getSex() {
  return sex;
}

//Age
void Person::setAge(int age) {
  this->age = age;
}
int Person::getAge() {
  return age;
}

//PDL
void Person::setPDL(bool pdl) {
  this->pdl = pdl;
}
bool Person::isPDL() {
  return pdl;
}

