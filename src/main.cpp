#include <iostream>
#include <fstream>
#include "Person.h"
#include "Prisoner.h"
#include "Employee.h"
#include "Penitentiary.h"
using namespace std;

int main(){
    fstream arquivo;
    Penitentiary *penitentiary = new Penitentiary();

    //Variáveis de controle para o funcionamento do programa
    bool running = true;
    int option;

    // Necessário para utilização de acentuação gráfica
    setlocale(LC_ALL, "portuguese");
    cout << "\n\t\t\t\t******* Sistema de Controle da Penitenciária *******\n" << endl;

    while(running){
    cout << "Qual operação deseja realizar?\n" << endl <<
                "1 - Inserir dado" << endl <<
                "2 - Alterar dado" << endl <<
                "3 - Pesquisar por meio do nome" << endl <<
                "4 - Remover dado" << endl <<
                "5 - Exibir dado" << endl <<
                "6 - Sair\n" << endl;

    cin >> option;
    switch(option){
        case 1:
            arquivo.open("baseDeDados.txt", ios::out | ios::app);
            arquivo.is_open(){
                while(){
                    
                }
            
                else
                    cout << "Não foi possível abrir o arquivo";
                }
            
            arquivo.close();
            break;
        case 2:
            arquivo.open("baseDeDados.txt", ios::out | ios::app);
            while(){
                    
                }
            
                else
                    cout << "Não foi possível abrir o arquivo";
                }
            arquivo.close();
            break;
        case 3:
            arquivo.open("baseDeDados.txt", ios::in);
            while(){
                    
                }
            
                else
                    cout << "Não foi possível abrir o arquivo";
                }
            arquivo.close();
            break;
        case 4:
            arquivo.open("baseDeDados.txt", ios::out | ios::app);
            while(){
                    
                }
            
                else
                    cout << "Não foi possível abrir o arquivo";
                }
            arquivo.close();
            break;
        case 5:
            arquivo.open("baseDeDados.txt", ios::in);
            while(){
                    
                }
            
                else
                    cout << "Não foi possível abrir o arquivo";
                }
            arquivo.close();
            break;
        case 6:
            cout << "Obrigado por utilizar nosso software. Bom trabalho!" << endl;
            running = false;
            break;
        default:
            cout << "Operação inválida. Por favor verifique o valor digitado" << endl;
            continue;
        }

    }

    return 0;
}
