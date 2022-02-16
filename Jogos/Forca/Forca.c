#include <stdio.h>
#include <string.h>
//#include "forca.h"

#define TAM 26
#define NIVEL 5

char palavraSecreta[TAM], chutes[TAM];
int chutesDados = 0;

void apresentacao();
void conclusao(int ganhou);
void novoChute();
int analisarChute(char letra);
void dica();
void definirPalavraSecreta();
int enforcou();
int acertou();

int main(){
    apresentacao();
    definirPalavraSecreta();
    do{
        dica();
        novoChute();
    }while(!acertou() && !enforcou());
}

void apresentacao(){
    printf("===============================\n");
    printf("=        Jogo da Forca        =\n");
    printf("===============================\n\n");
}

void conclusao(int ganhou){
    if(ganhou){
        printf("\n\n");
        printf("=================================\n");
        printf("=          Fim de jogo          =\n");
        printf("= Voce VENCEU, jogue novamente! =\n");
        printf("=================================\n\n");
    }else{
        printf("\n\n");
        printf("===============================\n");
        printf("=         Fim de jogo         =\n");
        printf("=       Voce NAO VENCEU,      =\n");
        printf("=   mais sorte na proxima!    =\n");
        printf("===============================\n\n");
    }
}

void novoChute(){
    char chute;
    printf("\nInforme uma letra: ");
    scanf(" %c", &chute);
    chutes[chutesDados] = chute;
    chutesDados++; // Ponto frágil.
}

int analisarChute(char letra){
    int achou = 0;
    for(int j = 0; j < chutesDados; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }
    return achou;
}

void dica(){
    printf("Voce ja informou: %d letras.\n", chutesDados);
    printf("Palavra --> ");
    for(int i = 0; i < strlen(palavraSecreta); i++){
        if(analisarChute(palavraSecreta[i])){
            printf("%c ", palavraSecreta[i]);
        }else{
            printf("_ ");
        }
    }
    printf("\n");
}

void definirPalavraSecreta(){ // Adicionar menu para informa palavra antes de iniciar jogo.
    sprintf(palavraSecreta, "Morango"); // Problema -> Resolver entrada de caractere maiusculo e minusculo ao fim.
}

int enforcou(){
    int erros = 0;
    for(int i = 0; i < chutesDados; i++){
        int existe = 0;
        for(int j = 0; j < strlen(palavraSecreta); j++){
            if (chutes[i] == palavraSecreta[j]){
                existe = 1;
                break;
            }
        }
        if(!existe){
            erros++;
        }
        return erros >= NIVEL;
    }
}

int acertou(){
    for(int i = 0; i < strlen(palavraSecreta); i++){
        if(!analisarChute(palavraSecreta[i])){
            return 0;
        }
    }
    return 1;
}
