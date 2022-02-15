#include <stdio.h>
#include <string.h>

#define TAM 26

char palavraSecreta[20], chutes[TAM];
int tentativas = 0;

void apresentacao();
void novoChute(char chutes[TAM], int tentativas);
int analisarChute(char letra);
void dica();
void definirPalavraSecreta();

int main(){
    int acertou = 0, enforcou = 0;
    apresentacao();
    definirPalavraSecreta();
    do{
        dica();
        novoChute(chutes, tentativas);
        tentativas++;
    }while(!acertou && !enforcou);
}

void apresentacao(){
    printf("===============================\n");
    printf("=        Jogo da Forca        =\n");
    printf("===============================\n\n");
}

void novoChute(char chutes[TAM], int tentativas){
    char chute;
    printf("\nInforme uma letra: ");
    scanf(" %c", &chute);
    chutes[tentativas] = chute; // Salvar letras já informadas.
}

int analisarChute(char letra){
    int achou = 0; // Verificar se a lista de letras já informadas, consta na lista de letras da palavra secreta.
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
            printf("%c ", palavraSecreta[i]); // Exibir letra que consta já informada.
        }else{
            printf("_ "); // Suprimir letra ainda não encontrada.
        }
    }
    printf("\n");
}

void definirPalavraSecreta(){
    sprintf(palavraSecreta, "Morango"); // Problema -> Resolver entrada de caractere maiusculo e minusculo ao fim.
}
