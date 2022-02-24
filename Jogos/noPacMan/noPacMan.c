#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nopacman.h"
#include "mapa.h"

MAPA m; // Formato do mapa: 5x10
POSICAO personagem;

int main(){
    carregarMapa(&m);
    encontrarPersonagem(&m, &personagem, PERSONAGEM_PRINCIPAL); // Personagem principal: '@'
    do{
        char direcao;
        imprimirMapa(&m);
        scanf(" %c", &direcao);
        mover(direcao);
        fantasmas();
    }while(!venceu());
    liberarMapa(&m);
}

int direcaoFantasma(int xAtualFantasma, int yAtualFantasma, int* xDestinoFantasma, int* yDestinoFantasma){
    int i;
    int opcoes[4][2] = { // Direcoes possiveis.
        {xAtualFantasma - 1, yAtualFantasma},
        {xAtualFantasma + 1, yAtualFantasma},
        {xAtualFantasma, yAtualFantasma - 1},
        {xAtualFantasma, yAtualFantasma + 1}
    };
    srand(time(0));
    for(i = 0; i < 10; i++){
        int sentido = rand() % 4;
        if(podeAndar(&m, opcoes[sentido][0], opcoes[sentido][1], PERSONAGEM_FANTASMA)){
            *xDestinoFantasma = opcoes[sentido][0];
            *yDestinoFantasma = opcoes[sentido][1];
            return 1;
        }
    }
    return 0;
}

void fantasmas(){
    int i, j;
    MAPA mapaComparar;
    clonarMapa(&mapaComparar, &m);
    for(i = 0; i < mapaComparar.linhas; i++){
        for(j = 0; j < mapaComparar.colunas; j++){
            if(mapaComparar.matriz[i][j] == PERSONAGEM_FANTASMA){
                int xDestino, yDestino, encontrou;
                encontrou = direcaoFantasma(i, j, &xDestino, &yDestino);
                if(encontrou){
                    andou(&m, i, j, xDestino, yDestino);
                }
            }
        }
    }
    liberarMapa(&mapaComparar);
}

void mover(char direcao){
    system("clear");
    int xVerificar = personagem.x, yVerificar = personagem.y;
    if(!verificarTecla(direcao)) return; // Controle 1: TECLAS aceitas.
    switch(direcao){ // LEMBRETE: personagem principal e o simbolo:'@'.
        case ESQUERDA: // Esquerda
            yVerificar--;
            break;
        case DIREITA: // Direita
            yVerificar++;
            break;
        case CIMA: // Subir
            xVerificar--;
            break;
        case BAIXO: // Descer
            xVerificar++;
            break;
    }
    if(!podeAndar(&m, xVerificar, yVerificar, PERSONAGEM_PRINCIPAL)){
        printf("\nTransite por um caminho valido com PONTO (.) e sem atingir as BARREIRAS no mapa ( | ou = ).\n");
        return;
    }// Controle 2: Transitar dentro das dimensoes do mapa e Caminho valido e normal.
    andou(&m, personagem.x, xVerificar, personagem.y, yVerificar);
    personagem.x = xVerificar;
    personagem.y = yVerificar;
}

int verificarTecla(char tecla){
    if(tecla == ESQUERDA || tecla == CIMA || tecla == DIREITA || tecla == BAIXO){
        return 1;
    }else{
        printf("\nComando invalido, utilize as teclas abaixo para se movimentar:\n");
        printf("a) Esquerda, ");
        printf("d) Direita, ");
        printf("w) Subir, ");
        printf("s) Descer.\n");
        return 0;
    }
}

int venceu(){
    POSICAO posicao;
    return !encontrarPersonagem(&m, &posicao, PERSONAGEM_PRINCIPAL) || !encontrarPersonagem(&m, &posicao, PERSONAGEM_FANTASMA);
}
