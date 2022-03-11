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
    cout << "|  2) Jogar em Grupo;                |" << endl;
    cout << "|                                    |" << endl;
    cout << "|                                    |" << endl;
    cout << "|  0) Encerrar programa.             |" << endl;
    cout << "|                                    |" << endl;
    cout << "|====================================|" << endl;
    cout << "|  ==> ";
    cin >> modo;
    return modo;
}

int nivel_dificuldade(){
    int nivel, valido = 1;
    do{
        system("clear");
        cout << "|==================================|" << endl;
        cout << "|  Jogar Sozinho > Dificuldade <   |" << endl;
        cout << "+----------------------------------+" << endl;
        cout << "|                                  |" << endl;
        cout << "|  Nivel de dificuldade desejada:  |" << endl;
        cout << "|                                  |" << endl;
        cout << "|  1) Facil (10 - Tentativas);     |" << endl;
        cout << "|  2) Medio (5 - Tentativas);      |" << endl;
        cout << "|  3) Dificil (3 - Tentativas);    |" << endl;
        cout << "|                                  |" << endl;
        cout << "|                                  |" << endl;
        cout << "|  0) Sair do jogo.                |" << endl;
        cout << "|                                  |" << endl;
        cout << "|==================================|" << endl;
        cout << "|  ==> ";
        cin >> nivel;
        switch(nivel){
            case 0:
                exit(1);
                valido = 0;
                break;
            case 1:
                nivel = 10;
                valido = 0;
                break;
            case 2:
                nivel = 5;
                valido = 0;
                break;
            case 3:
                nivel = 3;
                valido = 0;
                break;
        }
    }while(valido);
    return nivel;
}

void programa_finalizado(){
    cout << "Programa encerrado!" << endl;
}
