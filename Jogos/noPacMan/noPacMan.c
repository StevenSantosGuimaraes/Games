#include <stdio.h>
#include <stdlib.h>
#include "nopacman.h"
#include "mapa.h"

MAPA m; // Formato do mapa: 5x10
POSICAO personagem;

int main(){
    carregarMapa(&m);
    encontrarPersonagem(&m, &personagem, '@'); // Personagem principal: '@'
    do{
        char direcao;
        imprimirMapa(&m);
        scanf(" %c", &direcao);
        mover(direcao);
    }while(!venceu());
    liberarMapa(&m);
}

void mover(char direcao){
    system("clear");
    switch(direcao){ // LEMBRETE: personagem principal e o simbolo:'@'.
        case 'a': // Esquerda
            m.matriz[personagem.x][personagem.y - 1] = '@';
            m.matriz[personagem.x][personagem.y] = '.';
            personagem.y--;
            break;
        case 'd': // Direita
            m.matriz[personagem.x][personagem.y + 1] = '@';
            m.matriz[personagem.x][personagem.y] = '.';
            personagem.y++;
            break;
        case 'w': // Subir
            m.matriz[personagem.x - 1][personagem.y] = '@';
            m.matriz[personagem.x][personagem.y] = '.';
            personagem.x--;
            break;
        case 's': // Descer
            m.matriz[personagem.x + 1][personagem.y] = '@';
            m.matriz[personagem.x][personagem.y] = '.';
            personagem.x++;
            break;
        default:
            printf("\nComando invalido, utilize as teclas abaixo para se movimentar:\n");
            printf("A->Esquerda, ");
            printf("D->Direita, ");
            printf("W-> Subir, ");
            printf("S->Descer.\n");
            break;
    }
}

int venceu(){
    return 0;
}
