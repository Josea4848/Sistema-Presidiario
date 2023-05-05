#include "../include/DataBase.h"

//Constructor
//Caso não seja passado diretório nem o nome, a base referência será uma base genérica
DataBase::DataBase() : DataBase("", "base.csv") {}
DataBase::DataBase(string dir, string baseName) {
  setDirName(dir + baseName);
}

//dirName
void DataBase::setDirName(string dirName) {
  this->dirName = dirName;
}

//ClearData
void DataBase::clearData() {
  file.open(dirName);
  file.close();
}

//insertData
void DataBase::insertData(string data) {  
  if(!file.is_open()) {
    file.open(dirName, fstream::app);
    //Insertind data
    file << data << endl;
    file.close();
  }
  else
    cerr << "Arquivo já aberto para leitura!\n";
}

//getData
string DataBase::getData() {
  if(!file.is_open()) {
    file.open(dirName, fstream::in);
  }

  string data;
  getline(file, data);

  if(file.eof()) {
    file.close();
    data = "EOF";
  }
  
  return data;
}

//Destructor
DataBase::~DataBase() {}