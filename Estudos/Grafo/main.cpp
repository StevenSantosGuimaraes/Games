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
                tela_Menu_Informar_Dados();
                break;
            case 4:
                tela_Menu_Limpar_Dados();
                break;
            default:
                printf("\nOpcao informada e invalida, tente novamente.\n");
                break;
        }
    }while(opcao != 0);
    printf("\nPrograma encerrado com sucesso!\n\n");
}

// Funcoes:
void limpar_Matriz_Adjacencia(){
	int linha, coluna;
	for(linha = 0; linha <= tamanho; linha++){
		for(coluna = 1; coluna <= tamanho; coluna++){
			matriz_adjacencia[linha][coluna] = 0;
		}
	}
}

void imprimir_Matriz_Adjacencia(){
    int coluna, linha;
    printf("\n M.A. ");
    for(linha = 1; linha <= tamanho; linha++){
		if(linha < 10){
			printf("|--0%d--", linha);
		}else{
			printf("|--%d--", linha);
		}
	}
    printf("|\n");
    for(linha = 1; linha <= tamanho; linha++){
		for(coluna = 1; coluna <= tamanho; coluna++){
			if(coluna == 1 && linha < 10){
				printf("  0%d--|", linha);
			}else if(coluna == 1){
				printf("  %d--|", linha);
			}
			if(linha == coluna){
				printf("  xx  |");
			}else if(matriz_adjacencia[linha][coluna] == 0){
				printf("      |"); // Criterio para facilitar a leitura.
			}else{
				if(matriz_adjacencia[linha][coluna] >= 0 && matriz_adjacencia[linha][coluna] <= 9){
					printf("   %d  |", matriz_adjacencia[linha][coluna]);
				}else if(matriz_adjacencia[linha][coluna] >= -9 && matriz_adjacencia[linha][coluna] < 0){
					printf("  %d  |", matriz_adjacencia[linha][coluna]);
				}else if(matriz_adjacencia[linha][coluna] < -9){
					printf(" %d  |", matriz_adjacencia[linha][coluna]);
				}else{
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
    int coluna, linha, valor;
    char resposta;
    do{
        printf("\nInforme os vertices e em seguida a qual o valor (0 ou 1) na relacao (Ex: 1 3 0 - 'Um para Tres Ligado.'):\n");
        scanf("%d %d %d", &linha, &coluna, &valor);
        if(linha == coluna){
            printf("\nAtencao, nao e possivel informa na posicao: %d para %d, pois e um laco. Tente novamente outra posicao.\n", linha, coluna);
        }else if(valor == 1 || valor == 0){
            matriz_adjacencia[linha][coluna] = 1;
            imprimir_Matriz_Adjacencia();
        }else{
            printf("\nAtencao, para confirma que ou nao relacao deve ser informado 0 para nao, e 1 para sim. Tente novamente.\n");
        }
        printf("\nDeseja encerrar o programa? (S/N)\n");
    }while(resposta == 'N' || resposta == 'n');
    return;
}

// Menus:
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
                printf("\nInicializando matriz de adjacencia zerada, informe o tamanho desejado: ");
                scanf("%d", &tamanho);
                limpar_Matriz_Adjacencia();
                printf("\nMatriz de adjacencia com %d vertices inicializada com sucesso!\n", tamanho);
                break;
        }
    }while(resposta != 0);
    system("clear");
    return;
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
    system("clear");
    return;
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
    system("clear");
    return;
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
                printf("\nVerificando matriz de adjacencia ja criada...");
                limpar_Matriz_Adjacencia();
                printf("\nMatriz de adjacencia limpa com sucesso!");
                break;
        }
    }while(resposta != 0);
    system("clear");
    return;
}

int tela_Menu_Pencipal(){
    int resposta;
    printf("\n");
    printf("|=============================|\n");
    printf("|  > Menu Principal <         |\n");
    printf("|-----------------------------|\n");
    printf("|                             |\n");
    printf("|  Informe a opcao desejada:  |\n");
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
    system("clear");
    return resposta;
}
