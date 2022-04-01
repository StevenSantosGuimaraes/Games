#include "funcoes.h"

void limpar_tela(){
    system("clear");
}

void informacoes_sobre(){
    limpar_tela();
    cout << "Jogo desenvolvido em C++." << endl;
    cout << "Como jogar: Informe o quadrante a ser marcado pelo: 'X' ou 'O'." << endl;
    cout << " 1 | 2 | 3 " << endl;
    cout << "---+---+---" << endl;
    cout << " 4 | 5 | 6 " << endl;
    cout << "---+---+---" << endl;
    cout << " 7 | 8 | 9 " << endl;
    cout << endl;
    cout << "Seu jogo sera finalizado, reinicie o programa para jogar." << endl;
}

void mensagem_encerrar(){
    limpar_tela();
    cout << "O jogo foi encerrado com sucesso. Volte sempre!" << endl;
}
