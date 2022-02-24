#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

void andou(MAPA* m, int xOrigem, int xDestino, int yOrigem, int yDestino){
    char personagem = m->matriz[xOrigem][yOrigem];
    m->matriz[xDestino][yDestino] = personagem;
    m->matriz[xOrigem][yOrigem] = ESPACO_VAZIO;
}

void liberarMapa(MAPA* m){
    int i;
    for(i = 0; i < m->linhas; i++){
        free(m->matriz[i]);
    }
    free(m->matriz);
}

void clonarMapa(MAPA* destino, MAPA* origem){
    int i;
    destino->colunas = origem->colunas;
    destino->linhas = origem->linhas;
    alocarMapa(destino);
    for(i = 0; i < origem->linhas; i++){
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}

void alocarMapa(MAPA* m){
    int i;
    m->matriz = malloc(sizeof(char*) * m->linhas);
    for(i = 0; i < m->linhas; i++){
        m->matriz[i] = malloc(sizeof(char) * m->colunas + 1);
    }
}

void carregarMapa(MAPA* m){
    int i;
    FILE* arquivo;
    arquivo = fopen("mapa.txt", "r");
    if(arquivo == 0){
        printf("Erro de execusao no arquivo: 'mapa.txt'!\n");
        exit(1);
    }
    fscanf(arquivo, "%d %d", &(m->linhas), &(m->colunas));
    alocarMapa(m);
    for(i = 0; i < m->linhas; i++){
        fscanf(arquivo, "%s", m->matriz[i]);
    }
    fclose(arquivo);
}

int limitesMapa(MAPA* m, int x, int y){
    return x >= m->linhas || y >= m->colunas;
}

int encontreiParede(MAPA* m, int x, int y){
    return m->matriz[x][y] == PAREDE_HORIZONTAL || m->matriz[x][y] == PAREDE_VERTICAL;
}

int buscarPersonagem(MAPA* m, int x, int y, char cPersonagem){
    return m->matriz[x][y] == cPersonagem;
}

int podeAndar(MAPA* m, int x, int y, char personagem){
    return
        limitesMapa(m, x, y) &&
        !encontreiParede(m, x, y) &&
        !buscarPersonagem(m, x, y, personagem);
}

int encontrarPersonagem(MAPA* m, POSICAO* p, char c){
    int i, j;
    for(i = 0; i < m->linhas; i++){
        for(j = 0; j < m->colunas; j++){
            if(m->matriz[i][j] == c){ // Personagem encontrado (true)
                p->x = i; // linha(p)
                p->y = j; // coluna(p)
                return 1;
            }
        }
    }
    return 0;
}
