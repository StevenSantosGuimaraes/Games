#include "main.h"
#include "mensagens.h"
#include "funcoes.h"


int main(){
    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;
    int acertou, tentativa = 0, modo, chute, chances = 3;
    double pontos = 1000, pontos_perdidos;
    char continuar = 's';
    modo = saudacao();
    switch(modo){
        case 1:
            chances = nivel_dificuldade();
            do{
                acertou = verificar_chute(novo_chute(tentativa), NUMERO_SECRETO, tentativa);
                tentativa++;
            }while(!acertou && tentativa < chances);
            break;
        case 2:
            while(continuar == 's' || continuar == 'S'){
                do{
                    chute = novo_chute(tentativa);
                    acertou = verificar_chute(chute, NUMERO_SECRETO, tentativa);
                    tentativa++;
                    pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;
                    pontos -= pontos_perdidos;
                }while(!acertou);
                if(acertou){
                    cout.precision(2);
                    cout << fixed;
                    cout << "Voce marcou: " << pontos << " pontos." << endl;
                }
                cout << "Outro jogador vai jogar? (S/N) " << endl;
                cin >> continuar;
            }
            break;
        case 0:
            cout << "O programa esta sendo encerado!" << endl;
            break;
    }
    programa_finalizado();
}
