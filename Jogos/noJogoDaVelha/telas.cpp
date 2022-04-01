#include "telas.h"

int menu_inicial(){
    bool opcao_invalida;
    int opcao;
    do{
        cout << "Escolha uma opcao:" << endl;
        cout << endl;
        cout << "1) Jogar;" << endl;
        cout << "2) Sobre;" << endl;
        cout << "0) Sair." << endl;
        cout << endl;
        cout << "=> ";
        cin >> opcao;
        if(opcao == 0 || opcao == 1 || opcao == 2){
            opcao_invalida = false;
        }else{
            cout << "Opcao informada e invalida, tente novamente!" << endl;
            opcao_invalida = true;
        }
    }while(opcao_invalida);
    return opcao;
}
