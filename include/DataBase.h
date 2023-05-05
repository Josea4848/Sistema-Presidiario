#ifndef DATABASE_H
#define DATABASE_H

#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class DataBase{
public:
    DataBase();
    DataBase(string dir, string baseName);

    //set dirName
    void setDirName(string dirName);
    //Insert data
    void insertData(string data);
    //Get data
    string getData();
    //Clear data
    void clearData();
    ~DataBase();

private:
    fstream file;
    string dirName;
};

#endif