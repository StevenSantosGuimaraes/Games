#include "mensagens.h"

int saudacao(){
    int modo;
    system("clear");
    cout << "|====================================|" << endl;
    cout << "|  Bem vindo ao Jogo de Adivinhacao  |" << endl;
    cout << "|------------------------------------|" << endl;
    cout << "|                                    |" << endl;
    cout << "|  Informe modo desejado:            |" << endl;
    cout << "|                                    |" << endl;
    cout << "|  1) Jogar Sozinho;                 |" << endl;
    cout << "|  2) Jogar em Dupla;                |" << endl;
    cout << "|                                    |" << endl;
    cout << "|                                    |" << endl;
    cout << "|  0) Encerrar programa.             |" << endl;
    cout << "|                                    |" << endl;
    cout << "|====================================|" << endl;
    cout << "|  ==> ";
    cin >> modo;
    return modo;
}

void programa_finalizado(){
    cout << "Programa encerrado!" << endl;
}
