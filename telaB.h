/* 
 * File:   telaB.h
 * Author: martinfranzner
 *
 * Created on September 20, 2016, 5:49 PM
 */
/* telaB.h */

#ifndef TELA_H
#define TELA_H

#define ALTURA 10
#define LARGURA 25

#define RAQUETE '_'


#define TIJOLO 'X'


#define PONTO '.'
#define ESPACO ' '
#define TETO_E_CHAO '-'
#define PAREDE '|'


typedef enum direcao {
  SOBE,
  DESCE,
  ESQUERDA,
  DIREITA,
  DIAGONALSUPDIREITA,
  DIAGONALSUPESQUERDA,
  DIAGONALINFDIREITA,
  DIAGONALINFESQUERDA,
  STOP
} Direcao;

typedef struct ponto {
  int x, y;
  Direcao d;
} Ponto;

typedef struct raquete {
    int x,y1,y2,y3;
    Direcao b;
} Raquete;

void inicializa (char tela[ALTURA][LARGURA], Ponto* p, Raquete* r);

void reinicia(char tela[ALTURA][LARGURA], Ponto* p, Raquete* r);
void desenha (char tela[ALTURA][LARGURA], int *vidda, int *score);



void move (char tela[ALTURA][LARGURA], Ponto* p, Raquete* r, int *vidda, int *score);
void sobe (char tela[ALTURA][LARGURA], Ponto* p);
void desce (char tela[ALTURA][LARGURA], Ponto* p);

void diagonalSupDireita (char tela[ALTURA][LARGURA], Ponto* p);
void diagonalSupEsquerda (char tela[ALTURA][LARGURA], Ponto* p);
void diagonalInfDireita (char tela[ALTURA][LARGURA], Ponto* p);
void diagonalInfEsquerda (char tela[ALTURA][LARGURA], Ponto* p);

void esquerda (char tela[ALTURA][LARGURA], Ponto* p);
void direita (char tela[ALTURA][LARGURA], Ponto* p);


void moveRaquete (char tela[ALTURA][LARGURA], Raquete* r);
void esquerdaRaquete (char tela[ALTURA][LARGURA], Raquete* r);

void direitaRaquete (char tela[ALTURA][LARGURA], Raquete* r);
void muda_direcaoRaquete (Raquete* r, int b);

#endif
