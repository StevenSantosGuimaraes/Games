#include "funcoes.h"

void limpar_tela(){
    system("clear");
}

void jogar(){
    int linha, coluna, chute_linha, chute_coluna, pontos_marcados = 0, tentativas_feitas = 0, tentativas_maximas = 3 * TAMANHO_CAMPO;
    char campo[TAMANHO_CAMPO][TAMANHO_CAMPO], mascara[TAMANHO_CAMPO][TAMANHO_CAMPO];
    iniciar_campo(campo, mascara);
    posicionar_barcos(campo);
    while(tentativas_feitas < tentativas_maximas){
        limpar_tela();
        imprimir_matriz(mascara);
        cout << "Pontos: " << pontos_marcados << " marcados." << endl;
        cout << "Restam: " << tentativas_maximas - tentativas_feitas << " tentativas." << endl;
        cout << "Informe uma linha: ";
        cin >> chute_linha;
        cout << "Informe uma coluna: ";
        cin >> chute_coluna;
        verificar_disparo(campo, chute_linha, chute_coluna, &pontos_marcados);
        tentativas_feitas++;
        mascara[chute_linha][chute_coluna] = campo[chute_linha][chute_coluna];
    }
    if(pontos_marcados == 100){
        cout << "Parabens, voce acertou todos os objetivos." << endl;
    }else{
        cout << "Jogo finalizado, joge novamente e tente acertar mais objetivos." << endl;
    }
}

void iniciar_campo(char campo[TAMANHO_CAMPO][TAMANHO_CAMPO], char mascara[TAMANHO_CAMPO][TAMANHO_CAMPO]){
    int linha, coluna;
    for(linha = 0; linha < TAMANHO_CAMPO; linha++){
        for(coluna = 0; coluna < TAMANHO_CAMPO; coluna++){
            campo[linha][coluna] = 'A';
            mascara[linha][coluna] = '-';
        }
    }
}

void imprimir_matriz(char matriz[TAMANHO_CAMPO][TAMANHO_CAMPO]){
    int linha, coluna;
    cout << "LxC";
    for(coluna = 0; coluna < TAMANHO_CAMPO; coluna++){
        cout << "(" << coluna << ")";
    }
    cout << endl;
    for(linha = 0; linha < TAMANHO_CAMPO; linha++){
        cout << "(" << linha << ")";
        for(coluna = 0; coluna < TAMANHO_CAMPO; coluna++){
            cout << " " << matriz[linha][coluna] << " ";
        }
        cout << endl;
    }
    cout << "Legenda: (A: Agua, B: Barco)" << endl;
}

void posicionar_barcos(char matriz[TAMANHO_CAMPO][TAMANHO_CAMPO]){
    int i, quantidade_barcos;
    while(quantidade_barcos < TAMANHO_CAMPO){
        int linha = rand() % TAMANHO_CAMPO, coluna = rand() % TAMANHO_CAMPO;
        if(matriz[linha][coluna] == 'A'){
            matriz[linha][coluna] = 'B';
            quantidade_barcos++;
        }
    }
}

void verificar_disparo(char matriz[TAMANHO_CAMPO][TAMANHO_CAMPO], int linha_chute, int coluna_chute, int *pontos){
    switch(matriz[linha_chute][coluna_chute]){
        case 'A':
            break;
        case 'B':
            *pontos += 10;
            break;
    }
}
