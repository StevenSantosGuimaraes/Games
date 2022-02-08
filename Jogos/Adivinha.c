#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void apresentacao();
int nivelDoJogo();
int tentativa(int nt, int tt);

int main(){

    int chute, tentativas, segredo;
    double pontos = 1000;

    apresentacao();
    tentativas = nivelDoJogo();

    for(int i = 1; i <= tentativas; i++){
        chute = tentativa(i, tentativas);
        if(chute == segredo){
            printf("\nParabens, voce acertou o numero que pensei!\n");
            printf("\nSua pontuacao foi: %.2f pontos.\n", pontos);
            break;
        }else if(chute > segredo){
            printf("O seu chute: %d, foi MAIOR que numero que pensei. Tente novamente.\n");
        }else if(chute < segredo){
            printf("O seu chute: %d, foi MENOR que numero que pensei. Tente novamente.\n");
        }
        pontos += abs(chute - segredo) / 2.0;
    }

    if(chute != segredo){
        printf("\nQue pena, voce NAO acertou o numero que pensei!\n");
        printf("\nNao fique triste, tente novamente reiniciando o jogo com novos valores.\n");
    }

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
    int controle = 1, dificuldade = 0;
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
                dificuldade = 0;
                controle = 1;
                break;
        }
    }
    return dificuldade;
}

int tentativa(int nt, int tt){
    int c = 1, n,;
    while(c){
        printf("Tentativa %d de %d\n", nt, tt);
        printf("Informe um valor inteiro => ");
        scanf("%d", &n);
        if(n < 0){
            printf("Voce nao pode chutar valores negativos.\n");
        }
    }
    return n;
}
