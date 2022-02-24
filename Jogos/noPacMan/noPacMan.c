#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nopacman.h"
#include "mapa.h"
#include "ui.h"

MAPA m;
POSICAO pPrincipal;
int poder = 0;

int main(){
    carregarMapa(&m);
    encontrarPersonagem(&m, &pPrincipal, PERSONAGEM_PRINCIPAL); // Personagem principal: '@'
    do{
        char direcao;
        printf("Super poder disponivel: %s\n", (poder ? "SIM" : "NAO"));
        imprimirMapa(&m);
        scanf(" %c", &direcao);
        if(verificarTecla(direcao)) mover(direcao);
        if(direcao == ESPACO_PODER) explodir();
        fantasmas();
    }while(!venceu());
    liberarMapa(&m);
}

void explodindo(int x, int y, int raio, int xSoma, int ySoma){
    int xNovo = x + xSoma;
    int yNovo = y + ySoma;
    if(raio == 0) return;
    if(!limitesMapa(&m, xNovo, yNovo)) return;
    if(encontreiParede(&m, xNovo, yNovo)) return;
    m.matriz[xNovo][yNovo] = ESPACO_VAZIO;
    explodindo(xNovo, yNovo, raio - 1, xSoma, ySoma);
}

void explodir(){
    if(!poder) return;
    explodindo(pPrincipal.x, pPrincipal.y, RAIO_BOMBA, 0, 1); // Direita
    explodindo(pPrincipal.x, pPrincipal.y, RAIO_BOMBA, 0, -1); // Esquerda
    explodindo(pPrincipal.x, pPrincipal.y, RAIO_BOMBA, 1, 0); // Baixo
    explodindo(pPrincipal.x, pPrincipal.y, RAIO_BOMBA, -1, 0); // Cima
    poder = 0;
}

int direcaoFantasma(int xAtual, int yAtual, int* xDestino, int* yDestino){
    int i;
    int opcoes[4][2] = { // Direcoes possiveis.
        {xAtual - 1, yAtual},
        {xAtual + 1, yAtual},
        {xAtual, yAtual - 1},
        {xAtual, yAtual + 1}
    };
    srand(time(0));
    for(i = 0; i < 10; i++){
        int sentido = rand() % 4;
        if(podeAndar(&m, opcoes[sentido][0], opcoes[sentido][1], PERSONAGEM_FANTASMA)){
            *xDestino = opcoes[sentido][0];
            *yDestino = opcoes[sentido][1];
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
    int xVerificar = pPrincipal.x, yVerificar = pPrincipal.y;
    if(!verificarTecla(direcao)) return; // Controle 1: TECLAS aceitas.
    switch(direcao){
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
    if(!podeAndar(&m, xVerificar, yVerificar, PERSONAGEM_PRINCIPAL)){ // Controle 2: Transitar dentro das dimensoes do mapa e Caminho valido e normal.
        printf("\nTransite por um caminho sem barreiras no mapa.\n");
        return;
    }
    if(buscarPersonagem(&m, xVerificar, yVerificar, ESPACO_PODER)) poder = 1;
    andou(&m, pPrincipal.x, xVerificar, pPrincipal.y, yVerificar);
    pPrincipal.x = xVerificar;
    pPrincipal.y = yVerificar;
}

int verificarTecla(char tecla){
    if(tecla == ESQUERDA || tecla == CIMA || tecla == DIREITA || tecla == BAIXO || tecla == BOMBA){
        return 1;
    }else{
        printf("\nComando invalido, utilize as teclas abaixo para se movimentar:\n");
        printf("a) Esquerda, ");
        printf("d) Direita, ");
        printf("w) Subir, ");
        printf("s) Descer, ");
        printf("b) Acionar bomba.\n");
        return 0;
    }
}

int venceu(){
    POSICAO posicao;
    return !encontrarPersonagem(&m, &posicao, PERSONAGEM_PRINCIPAL) || !encontrarPersonagem(&m, &posicao, PERSONAGEM_FANTASMA);
}
