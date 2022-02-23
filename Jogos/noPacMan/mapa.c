#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void encontrarPersonagem(MAPA* m, POSICAO* p, char c){
    int x, y, i, j;
    for(i = 0; i < m->linhas; i++){
        for(j = 0; j < m->colunas; j++){
            if(m->matriz[i][j] == c){ // Personagem encontrado (true)
                p->x = i; // linha(p)
                p->y = j; // coluna(p)
                break;
            }
        }
    }
}

void imprimirMapa(MAPA* m){
    int i;
    for(i = 0; i < m->linhas; i++){
            printf("%s\n", m->matriz[i]);
    }
}

void liberarMapa(MAPA* m){
    int i;
    for(i = 0; i < m->linhas; i++){
        free(m->matriz[i]);
    }
    free(m->matriz);
}

void alocarMapa(MAPA* m){
    int i;
    m->matriz = malloc(sizeof(char*) * m->linhas);
    for(i = 0; i < m->linhas; i++){
        m->matriz[i] = malloc(sizeof(char) * (m->colunas + 1));
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