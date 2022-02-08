#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void apresentacao();
int nivelDoJogo();

int main(){

    int chute, tentativas, segredo;
    double pontos = 1000;

    apresentacao();
    tentativas = nivelDoJogo();

    printf("Teste de nivel / tentativas: %d.", tentativas);

    printf("\nPrograma finalizado!\n");

}

void apresentacao(){ // Mensagem de saudacao
    printf("\n");
    printf("========================================\n");
    printf("||  Bem vindo ao Jogo de Adivinhacao  ||\n");
    printf("========================================\n");
    printf("\n");
}

int nivelDoJogo(){
    int controle = 1, dificuldade = NULL;
    while(controle){
        printf("Informe o numero do nivel de dificuldade desejada, conforme as opcoes a baixo:\n");
        printf("(1) Facil - 20 tentativas;\n");
        printf("(2) Medio - 10 tentativas;\n");
        printf("(3) Dificil - 5 tentativas.\n");
        printf("opcao => ");
        scanf("%d", &dificuldade);
        switch(dificuldade){
            case 1:
                printf("Nivel: Facil selecionado. Voce tem 20 tentativas.\n");
                dificuldade = 20;
                controle = 0;
                break;
            case 2:
                printf("Nivel: Medio selecionado. Voce tem 10 tentativas.\n");
                dificuldade = 10;
                controle = 0;
                break;
            case 3:
                printf("Nivel: Dificil selecionado. Voce tem 5 tentativas.\n");
                dificuldade = 5;
                controle = 0;
                break;
            default:
                printf("Nivel informado esta incorreto.\n");
                dificuldade = NULL;
                controle = 1;
                break;
        }
    }
    return dificuldade;
}
