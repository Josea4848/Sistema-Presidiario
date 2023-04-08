#include "../include/Person.h"

//Construtores
Person::Person() : Person("undefined", "undefined", "undefined", '0', 0, false) {}
Person::Person(string name, string cpf, string skinColor, char sex, int age, bool ppl) {
    setName(name);
    setCPF(cpf);
    setSkinColor(skinColor);
    setSex(sex);
    setAge(age);
    setPPL(ppl);
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

//PPL
void Person::setPPL(bool ppl) {
  this->ppl = ppl;
}
bool Person::isPPL() {
  return ppl;
}

