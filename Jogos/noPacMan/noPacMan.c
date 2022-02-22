#include <stdio.h>
#include <stdlib.h>
#include "nopacman.h"

int linhas, colunas;
char** mapa;

int main(){
    int i;
    carregarMapa();
    for(i = 0; i < linhas; i++){
        printf("%s\n", mapa[i]);
    }
    liberarMapa();
}

void liberarMapa(){
    int i;
    for(i = 0; i < linhas; i++){
        free(mapa[i]);
    }
    free(mapa);
}

void alocarMapa(){
    int i;
    mapa = malloc(sizeof(char*) * linhas);
    for(i = 0; i < linhas; i++){
        mapa[i] = malloc(sizeof(char) * (colunas + 1));
    }
}

void carregarMapa(){
    int i;
    FILE* arquivo;
    arquivo = fopen("mapa.txt", "r");
    if(arquivo == 0){
        printf("Erro de execusao no arquivo: 'mapa.txt'!\n");
        exit(1);
    }
    fscanf(arquivo, "%d %d", &linhas, &colunas);
    alocarMapa();
    for(i = 0; i < linhas; i++){
        fscanf(arquivo, "%s", mapa[i]);
    }
    fclose(arquivo);
}
