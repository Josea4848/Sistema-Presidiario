#include <iostream>
#include <fstream>
#include <unistd.h>
#include "../include/Person.h"
#include "../include/Prisoner.h"
#include "../include/Employee.h"
#include "../include/Penitentiary.h"

using namespace std;

const static string dirEmploy = "../DataBase/bEmployees.csv";
const static string dirPrison = "../DataBase/bPrisoners.csv";

void clearTerminal() {
    //Limpa terminal
    system("clear");
}

void exibirMenu() {
    //Menu de opções 
    cout << "\nQual operação deseja realizar?\n1 - Registrar Funcionário\n2 - Atualizar Funcionário\n3 - Deletar Funcionário\n4 - Registrar Prisioneiro\n5 - Atualizar Prisioneiro\n6 - Deletar Prisioneiro\n7 - Resumo do número de prisioneiros\n8 - Pesquisar ocorrências por nome\n9 - Listar prisioneiros de uma cela\n10 - Informações do quadro de Funcionários\n11 - Sair\n\n";
}

void prisonerUpdateMenu() {
    cout << "Qual dado deseja atualizar?\n1 - Nome\n2 - Idade\n3 - Crime\n\n";
}

void employeeUpdateMenu() {
    cout << "Qual dado deseja atualizar?\n1 - Nome\n2 - Função\n3 - Idade\n4 - Salário\n5 - Carga Horária\n\n";
}

int main(){
    Penitentiary *penitentiary = new Penitentiary();

    //Variáveis de controle para o funcionamento do programa
    fstream *arquivoPrisoner = new fstream();
    fstream *arquivoEmployee = new fstream();
    bool running = true;
    unsigned short int option = 0;
    unsigned short int subOp = 0;
    string data;

    //Reading data from employees.csv
    //ignora Primeira linha
    arquivoEmployee->open(dirEmploy, fstream::in);
    getline(*arquivoEmployee, data);
    if(arquivoEmployee->is_open()) {
        while (true) {
            getline(*arquivoEmployee, data);
            if(arquivoEmployee->eof())
                break;
            penitentiary->registerEmployeeCSV(data);            
        }
        //Closing file
        arquivoEmployee->close();    
    } 
    //END Reading

    //Reading data from prisoners.csv
    arquivoPrisoner->open(dirPrison, fstream::in);
    //ignora primeira linha
    getline(*arquivoPrisoner, data);
    if(arquivoPrisoner->is_open()) {
        while (true) {
            getline(*arquivoPrisoner, data);
            if(arquivoPrisoner->eof())
                break;
            penitentiary->registerPrisonerCSV(data);
        }
        //Closing file
        arquivoPrisoner->close();    
    }
    //END Reading

    clearTerminal();

    // Necessário para utilização de acentuação gráfica
    setlocale(LC_ALL, "portuguese");
    cout << "===========================================\n Sistema de Controle da Penitenciária\n===========================================\n" << endl;

    while(running){
        //Dados gerais
        string name = "";
        string cpf = "";
        string skinColor = "";
        unsigned int age = 0;
        char sex = '\0';
        bool pdl = false;
        //Dados Funcionário
        string office = "";
        double wage = 0.0;
        unsigned int workLoad = 0;
        //Dados prisioneiro
        string crime = "";
        short int cell = -1;
        
        exibirMenu();
        cout << "Opção: ";
        cin >> option;

        //Clear buffer
        cin.ignore();

        if(option == 1 || option == 4) {
            cout << "| Nome: ";
            getline(cin, name);
            cout << "| CPF: ";
            getline(cin, cpf);
            if (cpf.size() != 11) {
                cout << "Valor de CPF inválido!\n";
                //Limpa terminal
                sleep(2);
                clearTerminal();
                continue;
            }
            else if(penitentiary->isEmployeeContained(cpf) || penitentiary->isPrisoner(cpf)) {
                cout << "Já existe usuário com CPF: " << cpf << " cadastrado, tente novamente!\n";
                sleep(2);
                clearTerminal();
                continue;
            }
            cout << "| SkinColor: ";
            getline(cin, skinColor);
            cout << "| Sexo: ";
            cin >> sex;
            cout << "| Idade: ";
            cin >> age;
            cout << "| É uma pessoa privada de liberdade [0 (não) | 1(sim)]: ";
            cin >> pdl;
            cin.ignore();
        }

        switch(option){
            case 1:
                //Registrar Funcionário
                cout << "| Função: ";
                getline(cin, office);
                cout << "| Salário: ";
                cin >> wage;
                cout << "| Carga horária: ";
                cin >> workLoad;
                penitentiary->registerEmployee(Employee(name,cpf,skinColor,sex,age,pdl,office,wage,workLoad));
                break;
            case 2:
                //Atualizar Funcionário
                cout << "CPF do Funcionário(a) que deseja atualizar o dado: ";
                getline(cin, cpf);
                //Se o funcionário existir
                if(penitentiary->isEmployeeContained(cpf)) {
                    //controla o while abaixo, quando um dado é atualizado, recebe falso e para o loop
                    bool subRun = true;
                    while (subRun) {
                        //Exibe menu
                        employeeUpdateMenu();
                        //subOption
                        cout << "Opção: ";
                        cin >> subOp;
                        cin.ignore();
                        switch (subOp) {
                        //Name
                        case 1:
                            cout << "Nome: ";
                            getline(cin, name);
                            penitentiary->updateEmployeeName(cpf, name);
                            subRun = false;
                            break;
                        case 2:
                            cout << "Função: ";
                            getline(cin, office);
                            penitentiary->updateEmployeeOffice(cpf, office);
                            subRun = false;
                            break;
                        case 3:
                            cout << "Idade: ";
                            cin >> age;
                            penitentiary->updateEmployeeAge(cpf, age);
                            subRun = false;
                            break;
                        case 4:
                            cout << "Salário: ";
                            cin >> wage;
                            penitentiary->updateEmployeeWage(cpf, wage);
                            subRun = false;
                            break;
                        case 5:
                            cout << "Carga Horária: ";
                            cin >> workLoad;
                            penitentiary->updateEmployeeWorkLoad(cpf, workLoad);
                            subRun = false;
                            break;
                        default:
                            cout << "Opção inválida, tente novamente!\n";
                            continue;
                        }
                    }
                }else {
                    cout << "Funcionário(a) não encontrado(a)!\n";
                }
                break;
            case 3:
                //Deletar Funcionário
                cout << "CPF do Funcionário(a) que deseja remover: ";
                getline(cin, cpf);
                penitentiary->deleteEmployee(cpf);
                break;
            case 4:
                //Registrar Prisioneiro
                cout << "| Crime(s) cometido(s): ";
                getline(cin, crime);
                cout << "| Número da cela [0 à " << n_CELLS - 1 << "]: ";
                cin >> cell;
                penitentiary->registerPrisoner(Prisoner(name, cpf, skinColor, sex, age, pdl, crime), cell);
                break;
            case 5:
                //Atualizar Prisioneiro
                cout << "CPF do prisioneiro que deseja atualizar o dado: ";
                getline(cin, cpf);
                if(penitentiary->isPrisoner(cpf)) {
                    bool subRun = true;
                    while (subRun) {
                        prisonerUpdateMenu();
                        cout << "Opção: ";
                        cin >> subOp;
                        cin.ignore();
                        switch(subOp) {
                        case 1:
                            cout << "Nome: ";
                            getline(cin, name);
                            penitentiary->updatePrisonerName(cpf, name);
                            subRun = false;
                            break;
                        case 2:
                            cout << "Idade: ";
                            cin >> age;
                            penitentiary->updatePrisonerAge(cpf, age);
                            subRun = false;
                            break;
                        case 3 :
                            cout << "Crime(s): ";
                            getline(cin, crime);
                            penitentiary->updatePrisonerCrime(cpf, crime);
                            subRun = false;
                            break;
                        default:
                            cout << "Opção inválida, tente novamente!\n";
                            continue;
                        }
                    }  
                } else {
                    cout << "Prisioneiro não encontrado!\n";
                }
                break;
            case 6:
                //Deletar Funcionário
                cout << "CPF do Prisioneiro que deseja remover: ";
                getline(cin, cpf);
                penitentiary->deletePrisoner(cpf);
                break;
            case 7:
                clearTerminal();
                penitentiary->prisonersNumbersSummary();
                sleep(2);
                break;
            case 8:
                //Pesquisa por nome
                cout << "Nome que deseja buscar ocorrências: ";
                getline(cin, name);
                clearTerminal();
                penitentiary->searchByName(name);
                sleep(2);
                break;
            case 9:
                cout << "Cela que deseja listar [0 à 9]: ";
                cin >> cell;
                clearTerminal();
                penitentiary->listPrisoners(cell);
                sleep(2);
                break;
            case 10:
                clearTerminal();
                penitentiary->employeesSummary();
                sleep(2);
                break;
            case 11:
                //Encerrar o programa
                cout << "Obrigado por utilizar nosso software. Bom trabalho!\n" << endl;
                running = false;
                break;
            default:
                cout << "Operação inválida. Por favor verifique as opções disponíveis\n" << endl;
                break;
            }
        sleep(2);
        clearTerminal();
    } 

    //Registro dos dados Employee
    arquivoEmployee->open(dirEmploy, fstream::out);
    *arquivoEmployee << "Nome;CPF;SkinColor;Sexo;Idade;isPDL;Função;CargaHor;Salário\n";
    if(arquivoEmployee->is_open()) {
        for(int i = 0; i < penitentiary->employeesNumber(); i++) {
            *arquivoEmployee << penitentiary->toStringEmployee(i) << endl;
        }

        arquivoEmployee->close();
    } else {
        cerr << "Não foi possível salvar as alterações feitas para os Funcionários!\n";
    }
    
    //Registro dos dados Prisoner
    arquivoPrisoner->open(dirPrison, fstream::out);
    *arquivoPrisoner << "Nome;CPF;SkinColor;Sexo;Idade;isPDL;Crime;Cela\n";
    if(arquivoPrisoner->is_open()) {
        for(int i = 0; i < n_CELLS; i++) {
            int prisonersNumber = penitentiary->getCell(i)->numberPrisoners();
            //Navega por todos prisioneiros de cada cela
            for(int j = 0; j < prisonersNumber; j++) {
                *arquivoPrisoner << penitentiary->toStringPrisoner(i, j) << endl;
            }
        } 
        //Closing
        arquivoPrisoner->close();
    } else {
        cerr << "Não foi possível salvar as alterações feitas para os Prisioneiros!\n";
    }

    //Destrutores
    delete penitentiary;
    delete arquivoEmployee;
    delete arquivoPrisoner;

    return 0;
}
