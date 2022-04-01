#include "principal.h"

int main(){
    int opcao;
    limpar_tela();
    cout << "Bem vindo ao jogo," << endl;
    opcao = menu_inicial();
    switch(opcao){
        case 1:
            jogar();
            break;
        case 2:
            informacoes_sobre();
            break;
        case 0:
            mensagem_encerrar();
            exit(1);
            break;
    }
}

void iniciar_jogo(char matriz[TAM_MATRIZ][TAM_MATRIZ]){
    int linha, coluna;
    for(linha = 0; linha < TAM_MATRIZ; linha++){
        for(coluna = 0; coluna < TAM_MATRIZ; coluna++){
            matriz[linha][coluna] = ' ';
        }
    }
}

void imprimir_matriz(char matriz[TAM_MATRIZ][TAM_MATRIZ]){
    int linha, coluna;
    for(linha = 0; linha < TAM_MATRIZ; linha++){
        for(coluna = 0; coluna < TAM_MATRIZ; coluna++){
            cout << " " << matriz[linha][coluna] << " ";
            if(coluna == 0 || coluna == 1){
                cout << "|";
            }
        }
        if(linha == 0 || linha == 1){
            cout << endl << "---+---+---" << endl;
        }
    }
    cout << endl;
}

bool marcar_jogada(int linha, int coluna, int rodada, char matriz[TAM_MATRIZ][TAM_MATRIZ]){
    char desenho;
    if(rodada % 2 == 0){
        desenho = 'X';
    }else{
        desenho = 'O';
    }
    if(matriz[linha][coluna] == ' '){
        matriz[linha][coluna] = desenho;
        return true;
    }else{
        cout << "Jogada invalida, tente novamente.";
        return false;
    }
}

bool verificar_vencedor(char matriz[TAM_MATRIZ][TAM_MATRIZ]){
    char jogador1 = 'X', jogador2 = 'O';
    bool vencedor = true;
    char p1 = matriz[0][0], p2 = matriz[0][1], p3 = matriz[0][2];
    char p4 = matriz[1][0], p5 = matriz[1][1], p6 = matriz[1][2];
    char p7 = matriz[2][0], p8 = matriz[2][1], p9 = matriz[2][2];
    if(
        p1 == jogador1 && p2 == jogador1 && p3 == jogador1 || 
        p4 == jogador1 && p5 == jogador1 && p6 == jogador1 || 
        p7 == jogador1 && p8 == jogador1 && p9 == jogador1 ||

        p1 == jogador1 && p4 == jogador1 && p7 == jogador1 || 
        p2 == jogador1 && p5 == jogador1 && p8 == jogador1 || 
        p3 == jogador1 && p6 == jogador1 && p9 == jogador1 ||

        p1 == jogador1 && p5 == jogador1 && p9 == jogador1 || 
        p7 == jogador1 && p5 == jogador1 && p3 == jogador1
    ){
        vencedor = false;
    }else if(
        p1 == jogador2 && p2 == jogador2 && p3 == jogador2 || 
        p4 == jogador2 && p5 == jogador2 && p6 == jogador2 || 
        p7 == jogador2 && p8 == jogador2 && p9 == jogador2 ||

        p1 == jogador2 && p4 == jogador2 && p7 == jogador2 || 
        p2 == jogador2 && p5 == jogador2 && p8 == jogador2 || 
        p3 == jogador2 && p6 == jogador2 && p9 == jogador2 ||

        p1 == jogador2 && p5 == jogador2 && p9 == jogador2 || 
        p7 == jogador2 && p5 == jogador2 && p3 == jogador2
    ){
        vencedor = false;
    }
    return vencedor;
}

void jogar(){
    int linha, coluna, opcao, rodada = 0;
    char campo[TAM_MATRIZ][TAM_MATRIZ];
    iniciar_jogo(campo);
    do{
        limpar_tela();
        cout << rodada + 1 << ". Rodada:" << endl;
        imprimir_matriz(campo);
        cout << "Jogador, informe o local a marcar: ";
        cin >> opcao;
        switch(opcao){
            case 1:
                if(marcar_jogada(0, 0, rodada, campo)){
                    cout << "Jogada valida!" << endl;
                    rodada++;
                }
                break;
            case 2:
                if(marcar_jogada(0, 1, rodada, campo)){
                    cout << "Jogada valida!" << endl;
                    rodada++;
                }
                break;
            case 3:
                if(marcar_jogada(0, 2, rodada, campo)){
                    cout << "Jogada valida!" << endl;
                    rodada++;
                }
                break;
            case 4:
                if(marcar_jogada(1, 0, rodada, campo)){
                    cout << "Jogada valida!" << endl;
                    rodada++;
                }
                break;
            case 5:
                if(marcar_jogada(1, 1, rodada, campo)){
                    cout << "Jogada valida!" << endl;
                    rodada++;
                }
                break;
            case 6:
                if(marcar_jogada(1, 2, rodada, campo)){
                    cout << "Jogada valida!" << endl;
                    rodada++;
                }
                break;
            case 7:
                if(marcar_jogada(2, 0, rodada, campo)){
                    cout << "Jogada valida!" << endl;
                    rodada++;
                }
                break;
            case 8:
                if(marcar_jogada(2, 1, rodada, campo)){
                    cout << "Jogada valida!" << endl;
                    rodada++;
                }
                break;
            case 9:
                if(marcar_jogada(2, 2, rodada, campo)){
                    cout << "Jogada valida!" << endl;
                    rodada++;
                }
                break;
        }
    }while(verificar_vencedor(campo) && rodada < 10);
    if(!verificar_vencedor(campo)){
        limpar_tela();
        cout << rodada + 1 << ". Rodada:" << endl;
        imprimir_matriz(campo);
        cout << "Jogo finalizado, um jogador venceu!" << endl;
    }else{
        limpar_tela();
        cout << rodada + 1 << ". Rodada:" << endl;
        imprimir_matriz(campo);
        cout << "Jogo empatado, joge novamente!" << endl;
    }
}
