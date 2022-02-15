#include <stdio.h>
#include <string.h>

#define TAM 26
#define NIVEL 10

char palavraSecreta[NIVEL], chutes[TAM];
int tentativas = 0;

void apresentacao();
void novoChute();
int analisarChute(char letra);
void dica();
void definirPalavraSecreta();

int main(){
    int acertou = 0, enforcou = 0;
    apresentacao();
    definirPalavraSecreta();
    do{
        dica();
        novoChute();
    }while(!acertou && !enforcou);
}

void apresentacao(){
    printf("===============================\n");
    printf("=        Jogo da Forca        =\n");
    printf("===============================\n\n");
}

void novoChute(){
    char chute;
    printf("\nInforme uma letra: ");
    scanf(" %c", &chute);
    chutes[tentativas] = chute;
    tentativas++; // Ponto frágil.
}

int analisarChute(char letra){
    int achou = 0;
    for(int j = 0; j < tentativas; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }
    return achou;
}

void dica(){
    printf("Voce ja informou: %d letras.\n", tentativas);
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
