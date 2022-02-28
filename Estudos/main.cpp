#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int tamanho, matriz_adjacencia[TAM][TAM];

int main(){
    int opcao;
    do{
        opcao = tela_Menu_Principal();
        switch(opcao){
            case 1:
                tela_Menu_Iniciar();
                break;
            case 2:
                tela_Menu_Imprimir();
                break;
            case 3:
                tela_Menu_Informa_Dados();
                break;
            case 4:
                tela_Menu_Limpar_Dados();
                break;
        }
    }while(opcao != 0);
    printf("\nPrograma encerrado com sucesso!\n\n");
}


// Menus (n1):
int tela_Menu_Principal(){
    int resposta;
    printf("\n");
    printf("|=============================|\n");
    printf("|  > Menu Principal <         |\n");
    printf("|-----------------------------|\n");
    printf("|                             |\n");
    printf("|  O que deseja realizar com  |\n");
    printf("|  uma estrutura de dados?    |\n");
    printf("|                             |\n");
    printf("|  1) Iniciar;                |\n");
    printf("|  2) Imprimir;               |\n");
    printf("|  3) Informar Dados;         |\n");
    printf("|  4) Limpar Dados;           |\n");
    printf("|                             |\n");
    printf("|                             |\n");
    printf("|  0) Encerrar Programa.      |\n");
    printf("|                             |\n");
    printf("|=============================|\n");
    printf("|>>> ");
    scanf("%d", &resposta);
    return resposta;
}


// Menus (n2):
void tela_Menu_Iniciar(){
    int resposta;
    do{
        printf("\n");
        printf("|================================|\n");
        printf("|  > Menu Principal > Iniciar <  |\n");
        printf("|--------------------------------|\n");
        printf("|                                |\n");
        printf("|  O que deseja iniciar?         |\n");
        printf("|                                |\n");
        printf("|  1) Matriz de Adjacencia;      |\n");
        printf("|                                |\n");
        printf("|                                |\n");
        printf("|  0) Voltar.                    |\n");
        printf("|                                |\n");
        printf("|================================|\n");
        printf("|>>> ");
        scanf("%d", &resposta);
        switch(resposta){
            case 1:
                printf("\nInicializando matriz de adjacencia, informe o tamanho desejado: ");
                scanf("%d", &tamanho);
                limpar_Matriz_Adjacencia();
                printf("\nMatriz de adjacencia com %d vertices inicializada com sucesso!\n", tamanho);
                break;
        }
    }while(resposta != 0);
}

void tela_Menu_Imprimir(){
    int resposta;
    do{
        printf("\n");
        printf("|=================================|\n");
        printf("|  > Menu Principal > Imprimir <  |\n");
        printf("|---------------------------------|\n");
        printf("|                                 |\n");
        printf("|  O que deseja imprimir?         |\n");
        printf("|                                 |\n");
        printf("|  1) Matriz de Adjacencia;       |\n");
        printf("|                                 |\n");
        printf("|                                 |\n");
        printf("|  0) Voltar.                     |\n");
        printf("|                                 |\n");
        printf("|=================================|\n");
        printf("|>>> ");
        scanf("%d", &resposta);
        switch(resposta){
            case 1:
                imprimir_Matriz_Adjacencia();
                break;
        }
    }while(resposta != 0);
}

void tela_Menu_Informa_Dados(){
    int resposta;
    do{
        printf("\n");
        printf("|======================================|\n");
        printf("|  > Menu Principal > Informa Dados <  |\n");
        printf("|--------------------------------------|\n");
        printf("|                                      |\n");
        printf("|  Onde deseja informa?                |\n");
        printf("|                                      |\n");
        printf("|  1) Matriz de Adjacencia;            |\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|  0) Voltar.                          |\n");
        printf("|                                      |\n");
        printf("|======================================|\n");
        printf("|>>> ");
        scanf("%d", &resposta);
        switch(resposta){
            case 1:
                dados_Matriz_Adjacencia();
                break;
        }
    }while(resposta != 0);
}

void tela_Menu_Limpar_Dados(){
    int resposta;
    do{
        printf("\n");
        printf("|======================================|\n");
        printf("|  > Menu Principal > Limpar Dados <   |\n");
        printf("|--------------------------------------|\n");
        printf("|                                      |\n");
        printf("|  O que deseja limpar?                |\n");
        printf("|                                      |\n");
        printf("|  1) Matriz de Adjacencia;            |\n");
        printf("|                                      |\n");
        printf("|                                      |\n");
        printf("|  0) Voltar.                          |\n");
        printf("|                                      |\n");
        printf("|======================================|\n");
        printf("|>>> ");
        scanf("%d", &resposta);
        switch(resposta){
            case 1:
                printf("\nVerificando matriz de adjacencia ja criada...\n");
                limpar_Matriz_Adjacencia();
                printf("\nMatriz de adjacencia limpa com sucesso!\n");
                break;
        }
    }while(resposta != 0);
}


// Funcoes:
void limpar_Matriz_Adjacencia(){
    int coluna, linha;
    for(linha = 0; linha <= tamanho; linha++){
        for(coluna = 1; coluna <= tamanho; coluna++){
            matriz_adjacencia[linha][coluna] = 0;
        }
    }
}

void imprimir_Matriz_Adjacencia(){
    int coluna, linha;
    printf("\nMatriz de Adjacencia:\n|      ");
    for(linha = 1; linha <= tamanho; linha++){ // Imprimir cabeçalho horizontal da matriz.
        if(linha < 10){
            printf("| <0%d> ", linha);
        }else{
            printf("| <%d> ", linha);
        }
    }
    printf("|\n");
    for(linha = 1; linha <= tamanho; linha++){
        for(coluna = 1; coluna <= tamanho; coluna++){
            if(coluna == 1 && linha < 10){ // Imprimir cabeçalho vertical da matriz.
                printf("| <0%d> |", linha);
            }else if(coluna == 1){
                printf(" <%d> |", linha);
            }
            if(coluna == linha){ // Criterio: O vertice, na matriz de adjacencia, nao possui laco.
                printf("  xx  |");
            }else if(matriz_adjacencia[linha][coluna] == 0){ // Criterio: Os sem ligacoes, FALSE, nao serao exibidos para facilitar leitura.
                printf("      |");
            }else{
                if(matriz_adjacencia[linha][coluna] >= 0 && matriz_adjacencia[linha][coluna] <= 9){
                    printf("   %d  |", matriz_adjacencia[linha][coluna]);
                }else if(matriz_adjacencia[linha][coluna] >= -9 && matriz_adjacencia[linha][coluna] < 0){
                    printf("  %d  |", matriz_adjacencia[linha][coluna]);
                }else if(matriz_adjacencia[linha][coluna] < -9){
                    printf(" %d  |", matriz_adjacencia[linha][coluna]);
                }else if(matriz_adjacencia[linha][coluna] > 9){
                    printf("  %d  |", matriz_adjacencia[linha][coluna]);
                }
            }
            if(coluna == tamanho){
                printf("\n");
            }
        }
    }
}

void dados_Matriz_Adjacencia(){
    int coluna, linha;
    char resposta;
    do{
        imprimir_Matriz_Adjacencia();
        printf("\nInforme o vertice de origem: ");
        scanf("%d", &linha);
        printf("\nInforme o vertice de destino: ");
        scanf("%d", &coluna);
        if(linha == coluna){
            printf("\nA linha: %d e Coluna: %d, nao e valido.", linha, coluna);
        }else{
            if(matriz_adjacencia[linha][coluna] == 0){
                matriz_adjacencia[linha][coluna] = 1;
            }else{
                matriz_adjacencia[linha][coluna] = 0;
            }
        }
        printf("\nDeseja informa outra adjacencia? (S/N) ==> ");
        scanf(" %c", &resposta);
    }while(resposta != 'n' || resposta != 'N');
}
