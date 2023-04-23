#include <iostream>
#include <fstream>
#include "Person.h"
#include "Prisoner.h"
#include "Employee.h"
#include "Penitentiary.h"
using namespace std;

int main(){
    Penitentiary *penitentiary = new Penitentiary();

    //Variáveis de controle para o funcionamento do programa
    fstream arquivo;
    bool running = true;
    int option;

    // Necessário para utilização de acentuação gráfica
    setlocale(LC_ALL, "portuguese");
    cout << "\n\t\t\t\t******* Sistema de Controle da Penitenciária *******\n" << endl;

    while(running){
    //Menu de opções 
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
            //Inserir dados
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
            //Alterar dado
            arquivo.open("baseDeDados.txt", ios::out | ios::app);
            while(){
                    
                }
            
                else
                    cout << "Não foi possível abrir o arquivo";
                }
            arquivo.close();
            break;
        case 3:
            //Pesquisar por meio do nome
            arquivo.open("baseDeDados.txt", ios::in);
            while(){
                    
                }
            
                else
                    cout << "Não foi possível abrir o arquivo";
                }
            arquivo.close();
            break;
        case 4:
            //Remover dado
            arquivo.open("baseDeDados.txt", ios::out | ios::app);
            while(){
                    
                }
            
                else
                    cout << "Não foi possível abrir o arquivo";
                }
            arquivo.close();
            break;
        case 5:
            //Exibir dado
            arquivo.open("baseDeDados.txt", ios::in);
            while(){
                    
                }
            
                else
                    cout << "Não foi possível abrir o arquivo";
                }
            arquivo.close();
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
