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
    cout << "\nQual operação deseja realizar?\n1 - Registrar Funcionário\n2 - Atualizar Funcionário\n3 - Deletar Funcionário\n4 - Registrar Prisioneiro\n5 - Atualizar Prisioneiro\n6 - Deletar Prisioneiro\n7 - Resumo do número de prisioneiros\n8 - Sair\n\n";
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

    //Reading data from employees.csv
    arquivoEmployee->open(dirEmploy, fstream::in);
    if(arquivoEmployee->is_open()) {
        while (true) {
            string data;
            getline(*arquivoEmployee, data);
            cout << data << endl;
            penitentiary->registerEmployeeCSV(data);
            if(arquivoEmployee->eof())
                break;
        }
        //Closing file
        arquivoEmployee->close();    
    }
    //END Reading

    cout << penitentiary->employeesNumber() << endl;

    //Reading data from prisoners.csv
    arquivoPrisoner->open(dirPrison, fstream::in);
    if(arquivoPrisoner->is_open()) {
        while (true) {
            string data;
            getline(*arquivoPrisoner, data);
            if(arquivoPrisoner->eof())
                break;
            penitentiary->registerPrisonerCSV(data);
        }
        //Closing file
        arquivoPrisoner->close();    
    }
    //END Reading

    // Necessário para utilização de acentuação gráfica
    setlocale(LC_ALL, "portuguese");
    cout << "===========================================\n Sistema de Controle da Penitenciária\n===========================================\n" << endl;

    penitentiary->prisonersNumbers();

    while(running){
        //Dados gerais
        string name, cpf, skinColor;
        unsigned int age;
        char sex;
        bool pdl;
        //Dados Funcionário
        string office;
        double wage;
        unsigned int workLoad;
        //Dados prisioneiro
        string crime;
        unsigned short int cell;
        
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
            else if(penitentiary->isEmployeeContained(cpf)) {
                cout << "O funcionário(a) com CPF: " << cpf << " já está cadastrado, tente novamente!\n";
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
                        cin >> subOp;
                        cin.ignore();
                        switch (subOp) {
                        //Name
                        case 1:
                            cout << "Nome: ";
                            getline(cin, name);
                            penitentiary->updateEmployeeName(cpf, name);
                            subRun = false;
                            cout << "Nome atualizado com sucesso!\n";
                            break;
                        case 2:
                            cout << "Função: ";
                            getline(cin, office);
                            penitentiary->updateEmployeeOffice(cpf, office);
                            subRun = false;
                            cout << "Função atualizada com sucesso!\n";
                            break;
                        case 3:
                            cout << "Função: ";
                            getline(cin, office);
                            penitentiary->updateEmployeeOffice(cpf, office);
                            subRun = false;
                            cout << "Função atualizada com sucesso!\n";
                            break;
                        case 4:
                            cout << "Idade: ";
                            cin >> age;
                            penitentiary->updateEmployeeAge(cpf, age);
                            subRun = false;
                            cout << "Idade atualizada com sucesso!\n";
                            break;
                        case 5:
                            cout << "Salário: ";
                            cin >> wage;
                            penitentiary->updateEmployeeWage(cpf, wage);
                            subRun = false;
                            cout << "Salário atualizado com sucesso!\n";
                            break;
                        case 6:
                            cout << "Carga Horária: ";
                            cin >> workLoad;
                            penitentiary->updateEmployeeWorkLoad(cpf, workLoad);
                            subRun = false;
                            cout << "Carga Horária atualizada com sucesso!\n";
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
                cout << "Crime(s) cometido(s): ";
                getline(cin, crime);
                cout << "Número da cela [0 à 9]: ";
                cin >> cell;
                penitentiary->registerPrisoner(Prisoner(name, cpf, skinColor, sex, age, pdl, crime), cell);
                break;
            case 5:
                //Atualizar Prisioneiro
                cout << "CPF do prisioneiro que deseja atualizar o dado: ";
                getline(cin, cpf);
                if(penitentiary->isEmployeeContained(cpf)) {
                    bool subRun = true;
                    while (subRun) {
                        prisonerUpdateMenu();
                        cout << "Opção: ";
                        cin >> subOp;

                        switch(subOp) {
                        case 1:
                            cout << "Nome: ";
                            getline(cin, name);
                            penitentiary->updatePrisonerName(cpf, name);
                            subRun = false;
                            cout << "Nome atualizado com sucesso!\n";
                            break;
                        case 2:
                            cout << "Idade: ";
                            cin >> age;
                            penitentiary->updatePrisonerAge(cpf, age);
                            subRun = false;
                            cout << "Idade atualizada com sucesso!\n";
                            break;
                        case 3 :
                            cout << "Crime(s): ";
                            getline(cin, crime);
                            penitentiary->updatePrisonerCrime(cpf, crime);
                            subRun = false;
                            cout << "Crime(s) atualizado(s) com sucesso!\n";
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
                break;
            case 8:
                //Encerrar o programa
                cout << "Obrigado por utilizar nosso software. Bom trabalho!" << endl;
                running = false;
                break;
            default:
                cout << "Operação inválida. Por favor verifique as opções disponíveis" << endl;
                break;
            }
        sleep(2);
        clearTerminal();
    } 

    //Registro dos dados Employee
    arquivoEmployee->open(dirEmploy, fstream::out);
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
    if(arquivoPrisoner->is_open()) {
        for(int i = 0; i < n_CELLS; i++) {
            int prisonersNumber = penitentiary->getCell(0).numberPrisoners();
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

    return 0;
}
