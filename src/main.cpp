#include <iostream>
#include <fstream>
#include "Person.h"
#include "Prisoner.h"
#include "Employee.h"
#include "Penitentiary.h"

using namespace std;

void exibirMenu() {
    //Menu de opções 
    cout << "Qual operação deseja realizar?\n1 - Registrar Funcionário\n2 - Atualizar Funcionário\n3 - Deletar Funcionário\n4 - Registrar Prisioneiro\n5 - Atualizar Prisioneiro\n6 - Deletar Prisioneiro\n7 - Resumo do número de prisioneiros\n8 - Sair";
}

int main(){
    Penitentiary *penitentiary = new Penitentiary();

    //Variáveis de controle para o funcionamento do programa
    fstream arquivoPrisoner, arquivoEmployee;
    bool running = true;
    unsigned short int option = 0;

    // Necessário para utilização de acentuação gráfica
    setlocale(LC_ALL, "portuguese");
    cout << "\n\t\t\t\t========= Sistema de Controle da Penitenciária =========\n" << endl;

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

        cin >> option;

        //Clear buffer
        cin.ignore();

        if(option == 1 || option == 4) {
            cout << "| Nome: ";
            getline(cin, name);
            cout << "| CPF: ";
            getline(cin, cpf);
            cout << "| SkinColor: ";
            getline(cin, skinColor);
            cout << "| Sexo: ";
            cin >> sex;
            cout << "| Idade: ";
            cin >> age;
            cout << "| É uma pessoa privada de liberdade [0(não)/1(sim)]: ";
            cin >> pdl;
        }

        switch(option){
            case 1:
                //Registrar Funcionário
                cin.ignore();
                cout << "| Função: ";
                getline(cin, office);
                cout << "| Salário: ";
                cin >> wage;
                cout << "| Carga horária: ";
                cin >> workLoad;
                break;
            case 2:
                //Atualizar Funcionário
                
                break;
            case 3:
                //Deletar Funcionário
                
                break;
            case 4:
                //Registrar Prisioneiro
                
                break;
            case 5:
                //Atualizar Prisioneiro
                
                break;
            case 6:
                //Deletar Prisioneiro
            case 7:
                //Encerrar o programa
                cout << "Obrigado por utilizar nosso software. Bom trabalho!" << endl;
                running = false;
                break;
            default:
                cout << "Operação inválida. Por favor verifique as opções disponíveis" << endl;
                continue;
            }

    }

    return 0;
}
