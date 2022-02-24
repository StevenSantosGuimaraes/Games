#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
#include "ui.h"

char desenhoParede[LINHA_DESENHO][COLUNA_DESENHO] = {
    {"====="},
    {"====="},
    {"====="},
    {"====="}
};

char desenhoFantasma[LINHA_DESENHO][COLUNA_DESENHO] = {
    {".---."},
    {"|o o|"},
    {"|   |"},
    {"|^^^|"}
};

char desenhoPrincipal[LINHA_DESENHO][COLUNA_DESENHO] = {
    {"  o  "},
    {" /|\\ "},
    {"  |  "},
    {" / \\ "}
};

char desenhoPoder[LINHA_DESENHO][COLUNA_DESENHO] = {
    {"     "},
    {" .-. "},
    {" ._. "},
    {"     "}
};

char desenhoVazio[LINHA_DESENHO][COLUNA_DESENHO] = {
    {"     "},
    {"     "},
    {"     "},
    {"     "}
};

void imprimeParte(char desenho[LINHA_DESENHO][COLUNA_DESENHO], int parte){
    printf("%s", desenho[parte]);
}

void imprimirMapa(MAPA* m){
    int i, j, parte;
    for(i = 0; i < m->linhas; i++){
        for(parte = 0; parte < LINHA_DESENHO; parte++){ // Novo tamanho e 4x maior.
            for(j = 0; j < m->colunas; j++){
                switch(m->matriz[i][j]){
                    case PERSONAGEM_PRINCIPAL:
                        imprimeParte(desenhoPrincipal, parte);
                        break;
                    case PERSONAGEM_FANTASMA:
                        imprimeParte(desenhoFantasma, parte);
                        break;
                    case ESPACO_PODER:
                        imprimeParte(desenhoPoder, parte);
                        break;
                    case ESPACO_VAZIO:
                        imprimeParte(desenhoVazio, parte);
                        break;
                    case PAREDE_VERTICAL:
                        imprimeParte(desenhoParede, parte);
                        break;
                    case PAREDE_HORIZONTAL:
                        imprimeParte(desenhoParede, parte);
                        break;
                }
            }
            printf("\n");
        }
    }
}
