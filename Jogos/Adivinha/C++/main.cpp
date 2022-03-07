#include "main.h"
#include "mensagens.h"
#include "funcoes.h"

int main(){ // Modos: Jogar sozinho (utilizar: chances) ou nao (sistema de pontuacao com x players)
    const int NUMERO_SECRETO = 47, chances = 3;
    int acertou, tentativa = 0, modo;
    modo = saudacao();
    switch(modo){
        case 1:
            do{
                acertou = verificar_chute(novo_chute(tentativa), NUMERO_SECRETO, tentativa);
                tentativa++;
            }while(!acertou && tentativa < chances);
            break;
        case 2:
            // Solicitar quantidade de players
            // loop com o loop principal, a o concluir atribui os pontos ao nome e player para exibir no fim.
            break;
        case 0:
            cout << "O programa esta sendo encerado!" << endl;
            break;
    }
    programa_finalizado();
}
