#include "telas.h"

int menu_principal(){
    int opcao = 0, valido;
    do{
        cout << "|-----------------------------|" << endl;
        cout << "|     Bem vindo ao jogo,      |" << endl;
        cout << "|  informe a opcao desejada:  |" << endl;
        cout << "+-----------------------------+" << endl;
        cout << "|                             |" << endl;
        cout << "|  1) Jogar;                  |" << endl;
        cout << "|  2) sobre;                  |" << endl;
        cout << "|                             |" << endl;
        cout << "|                             |" << endl;
        cout << "|  0) Sair.                   |" << endl;
        cout << "|                             |" << endl;
        cout << "|-----------------------------|" << endl;
        cout << "|>> ";
        cin >> opcao;
        if(opcao == 0 || opcao == 1 || opcao == 2){
            valido = false;
        }else{
            limpar_tela();
            cout << endl << "Opcao informada e invalida, tente novamente." << endl << endl;
            valido = true;
        }
    }while(valido);
    return opcao;
}
