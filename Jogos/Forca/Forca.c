#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "forca.h"

char chutes[TAMANHO_MAXIMO_ALFABETO], palavraSecreta[TAMANHO_MAXIMO_PALAVRA];
int chutesDados = 0, nivel = 5; // Verificar troca por: letrasInformadas

int main(){
    apresentacao(); //abertura();
    palavraAleatoria(); //void escolhepalavra();
    do{
        imprimirForca();
        novaLetra();
    }while(!verificarVenceu() && !verificarPerdeu());
    if(verificarVenceu()){
        printf("\nParabens voce acertou!!!\n");
        printf("\nA palavra secreta era ==> %s.\n", palavraSecreta);
    }else{
        printf("\nQue pena, voce foi perdeu!\n");
        printf("\nA palavra era ==> %s <==\n", palavraSecreta);
    }
    inserirPalavraDicionario();
}

// Funcoes:
bool verificarPerdeu(){
    return contarLetrasErradas() >= nivel;
}

int verificarVenceu(){
	int i;
    for(i = 0; i < strlen(palavraSecreta); i++){
        if(!imprimirPalavra(palavraSecreta[i])){
            return 0;
        }
    }
    return 1;
}

void novaLetra(){
    char palpite;
    printf("\nInforme uma letra MAIUSCULA ==> ");
    scanf(" %c", &palpite);
    if(varrerPalavra(palpite)){
        printf("\nA palavra secreta tem a letra: %c.\n", palpite);
    }else{
        printf("\nA palavra secreta nao tem a letra: %c.\n", palpite);
    }
    chutes[chutesDados] = palpite;
    chutesDados++;
}

int imprimirPalavra(char letra){
    int j, achou = 0;
    for(j = 0; j < chutesDados; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }
    return achou;
}

int varrerPalavra(char letra){
	int j;
    for(j = 0; j < strlen(palavraSecreta); j++){
        if(letra == palavraSecreta[j]){
            return 1;
        }
    }
    return 0;
}

int contarLetrasErradas(){
    int i, quantidadeErros = 0;
    for(i = 0; i < chutesDados; i++){
        if(!varrerPalavra(chutes[i])){
            quantidadeErros++;
        }
    }
    return quantidadeErros;
}

void imprimirForca(){
    system("clear");
    int i, erros = contarLetrasErradas();
    printf("  |------|       \n");
    printf("  |      |       \n");
    printf("  |     %c%c%c   \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf("  |     %c%c%c   \n", (erros >= 3 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
    printf("  |      %c      \n", (erros >= 2 ? '|' : ' '));
    printf("  |     %c %c    \n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
    printf("  |              \n");
    printf("--|--            \n\n");
    for(i = 0; i < strlen(palavraSecreta); i++){
        if(imprimirPalavra(palavraSecreta[i])){
            printf("%c ", palavraSecreta[i]);
        }else{
            printf("_ ");
        }
    }
    printf("\n");
}

void palavraAleatoria(){
	int i, quantidadePalavras;
    FILE* arquivo;
    arquivo = fopen("dicionario.txt", "r");
    if(arquivo == 0){
        printf("Dicionario com as palavras nao esta disponivel!\n");
        printf("Insira o numero de palavras, na primeira linha, no arquivo '.txt' e em sequencia as palavras a serem adivinhadas em cada linha!\n");
        exit(1);
    }
    fscanf(arquivo, "%d", &quantidadePalavras);
    srand(time(0));
    int aleatorio = rand() % quantidadePalavras;
    for(i = 0; i <= aleatorio; i++){
        fscanf(arquivo, "%s", palavraSecreta);
    }
    fclose(arquivo);
}

void inserirPalavraDicionario(){
    char resposta;
    printf("\nDeseja contribuir com uma nova palavra para jogo (S/N)? ");
    scanf(" %c", &resposta);
    if(resposta == 'S' || resposta == 's'){
        char novaPalavra[TAMANHO_MAXIMO_PALAVRA];
        int quantidade;
        printf("Informe a nova palavra APENAS COM LETRAS MAIUSCULAS: ");
        scanf("%s", novaPalavra);
        FILE* arquivo;
        arquivo = fopen("dicionario.txt", "r+");
        if(arquivo == 0){
            printf("Dicionario com as palavras nao esta disponivel!\n");
            printf("Insira o numero de palavras, na primeira linha, no arquivo '.txt' e em sequencia as palavras a serem adivinhadas em cada linha!\n");
            exit(1);
        }
        fscanf(arquivo, "%d", &quantidade);
        quantidade++;
        fseek(arquivo, 0, SEEK_SET);
        fprintf(arquivo, "%d", quantidade);
        fseek(arquivo, 0, SEEK_END);
        fprintf(arquivo, "\n%s", novaPalavra);
        fclose(arquivo);
    }
}

void apresentacao(){
    system("cls");
    printf("|----------------|\n");
    printf("|  Bem vindo ao  |\n");
    printf("| Jogo da Forca! |\n");
    printf("|----------------|\n");
}
