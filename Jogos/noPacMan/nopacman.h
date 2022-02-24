#ifndef _NOPACMAN_H_
#define _NOPACMAN_H_

#define ESQUERDA 'a'
#define DIREITA 'd'
#define CIMA 'w'
#define BAIXO 's'
#define BOMBA 'b'
#define RAIO_BOMBA 3

void mover(char direcao);
void fantasmas();
void explodir();
void explodindo(int x, int y, int raio, int xSoma, int ySoma);
int venceu();
int verificarTecla(char tecla);

#endif
