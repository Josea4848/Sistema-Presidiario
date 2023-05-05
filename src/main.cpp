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

                
                break;
            case 2:
                //Alterar dado
                
                break;
            case 3:
                //Pesquisar por meio do nome
                
                break;
            case 4:
                //Remover dado
                
                break;
            case 5:
                //Exibir dado
                
                break;
            case 6:
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
