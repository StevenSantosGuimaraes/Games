#include "principal.h"

int main(){
    int opcao;
    srand((unsigned)time(NULL));
    limpar_tela();
    opcao = menu_principal();
    switch(opcao){
        case 0:
            cout << "O programa sera encerrado." << endl;
            exit(1);
            break;
        case 1:
            limpar_tela();
            jogar();
            break;
        case 2:
            sobre_jogo();
            break;
    }
}

void sobre_jogo(){
    cout << "Ola, este jogo foi desenvolvido em C++ para teste de habilidade." << endl;
    cout << "O programa sera encerrado neste momento." << endl;
}
