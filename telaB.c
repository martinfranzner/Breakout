/* telaB.c */

#include <stdio.h>
#include "telaB.h"

void inicializa (char tela[ALTURA][LARGURA], Ponto* p, Raquete* r) {
  int i, j;
  for (i = 0; i < ALTURA; i += (ALTURA - 1)) {
    for (j = 0; j < LARGURA; j++) {
      tela[i][j] = TETO_E_CHAO;
    }
  }
  for (i = 1; i < ALTURA - 1; i++) {
    for (j = 0; j < LARGURA; j += (LARGURA - 1)) {
      tela[i][j] = PAREDE;
    }
  }
  for (i = 1; i < ALTURA - 1; i++) {
    for (j = 1; j < LARGURA - 1; j++) {
      tela[i][j] = ESPACO;
    }
  }
  for (i = 1; i < 5 - 1; i++) {
    for (j = 1; j < LARGURA - 1; j++) {
      tela[i][j] = TIJOLO;
    }
  }
  
  
  
  
  i = 8;
  j = 12;
  tela[i][j] = PONTO;
  p->x = i;
  p->y = j;
  p->d = DIAGONALSUPDIREITA;
  
  r->x = 8;
  r->y1 = 15;
  r->y2 = 16;
  r->y3 = 17;
  tela[r->x][r->y1] = RAQUETE;
  tela[r->x][r->y2] = RAQUETE;
  tela[r->x][r->y3] = RAQUETE;
  r->b = DIREITA;
  
  
}
/*funcao que reinicia os tijolos, 
botei para quando nao esta totalmente sem pq eh impossivel vencer o jogo*/
void reinicia(char tela[ALTURA][LARGURA], Ponto* p, Raquete* r){
    if(tela[p->x-2][p->y] == TETO_E_CHAO){
        inicializa(tela, p, r);
    }
    
} 

void desenha (char tela[ALTURA][LARGURA], int *vidda, int *score) {
  int i, j;
  for (i = 0; i < ALTURA; i++) {
    for (j = 0; j < LARGURA; j++) {
      printf("%c", tela[i][j]);
    }
    printf("\n");
  }
  
  printf("Score: %d ", *score);
  printf("Vida: %d\n", *vidda);
}

void move (char tela[ALTURA][LARGURA], Ponto* p, Raquete* r, int *vidda, int *score) {
 //(*vidda)--;
      if (p->d == DIAGONALSUPDIREITA) {
        if (p->x > 1 && p->y < LARGURA - 2) {
          diagonalSupDireita(tela, p);
          if(tela[p->x-1][p->y+1] == TIJOLO){
              tela[p->x-1][p->y+1] = ESPACO;
              p->d = DIAGONALINFDIREITA;
              diagonalInfDireita(tela, p);
              (*score)++;
    
          }
          else if(tela[p->x-1][p->y+2] == TIJOLO){
              tela[p->x-1][p->y+2] = ESPACO;
              p->d = DIAGONALSUPESQUERDA;
              diagonalSupEsquerda(tela, p);
              (*score)++;
    
          }
          
        }
        else if (p->x > 1 && p->y > 2) {
          p->d = DIAGONALSUPESQUERDA;
          diagonalSupEsquerda(tela, p);
        }
        else {
          p->d = DIAGONALINFDIREITA;
          diagonalInfDireita(tela, p);
        } 
      }
      else if (p->d == DIAGONALSUPESQUERDA) {
        if (p->x > 1 && p->y > 2) {
          diagonalSupEsquerda(tela, p);
          if(tela[p->x-1][p->y-1] == TIJOLO){
              tela[p->x-1][p->y-1] = ESPACO;
              p->d = DIAGONALINFESQUERDA;
              diagonalInfEsquerda(tela, p);
              (*score)++;
              
          }
          else if(tela[p->x-1][p->y-2] == TIJOLO){
              tela[p->x-1][p->y-2] = ESPACO;
              p->d = DIAGONALSUPDIREITA;
              diagonalSupDireita(tela, p);
              (*score)++;
    
          }
        }
        else if (p->x > 1 && p->y < LARGURA - 2) {
          p->d = DIAGONALSUPDIREITA;
          diagonalSupDireita(tela, p);
        }
        else {
          p->d = DIAGONALINFESQUERDA;
          diagonalInfEsquerda(tela, p);
        }
      }
      //ifs diagonais inferiores
      else if (p->d == DIAGONALINFDIREITA) {
        if (p->x < ALTURA - 2 && p->y < LARGURA -2) {
          diagonalInfDireita(tela, p);
          if((tela[p->x+1][p->y] == RAQUETE) || (tela[p->x+1][p->y+1] == TIJOLO)){
              p->d = DIAGONALSUPDIREITA;
              diagonalSupDireita(tela, p);
          }
          else if(tela[p->x+1][p->y+1] == TIJOLO){
              tela[p->x+1][p->y+1] = ESPACO;
              p->d = DIAGONALSUPDIREITA;
              diagonalSupDireita(tela, p);
              (*score)++;
              
          }
          else if(tela[p->x+2][p->y+2] == TIJOLO){
              tela[p->x+2][p->y+2] = ESPACO;
              p->d = DIAGONALINFESQUERDA;
              diagonalInfEsquerda(tela, p);
              (*score)++;
    
          }
          else if(p->x >= 8){
              (*vidda)--;
              
              p->x = 8;
              p->y = 12;
          }
          
        }
        else if (p->x < ALTURA - 2 && p->y > 2) {
          p->d = DIAGONALINFESQUERDA;
          diagonalInfEsquerda(tela, p);
        }
        else  {   
        p->d = DIAGONALSUPDIREITA;
        diagonalSupDireita(tela, p);     
        }
        //(p->x < 8 && ((p->y > r->y1) && (p->y > r->y2) && (p->y > r->y3)))
      }
      else if (p->d == DIAGONALINFESQUERDA) {
        if (p->x < ALTURA - 2 && p->y > 2) {
          diagonalInfEsquerda(tela, p);
          if((tela[p->x+1][p->y] == RAQUETE) || (tela[p->x+1][p->y] == TIJOLO)){
              p->d = DIAGONALSUPESQUERDA;
              diagonalSupEsquerda(tela, p);
          }
          else if(tela[p->x+1][p->y-1] == TIJOLO){
              tela[p->x+1][p->y-1] = ESPACO;
              p->d = DIAGONALSUPESQUERDA;
              diagonalSupEsquerda(tela, p);
              (*score)++;
              
          }
          else if(tela[p->x+2][p->y-2] == TIJOLO){
              tela[p->x+2][p->y-2] = ESPACO;
              p->d = DIAGONALINFDIREITA;
              diagonalInfDireita(tela, p);
              (*score)++;
    
          }
          else if(p->x >= 8){
              (*vidda)--;
              p->x = 8;
              p->y = 12;
              
          }
        }
        else if (p->x < ALTURA - 2 && p->y < LARGURA - 2) {
          p->d = DIAGONALINFDIREITA;
          diagonalInfDireita(tela, p);
        }
        else  {
          p->d = DIAGONALSUPESQUERDA;
          diagonalSupEsquerda(tela, p);
        }
      }
      

}

//criar funcoes para sentido diagonal da bolinha
void diagonalSupDireita (char tela[ALTURA][LARGURA], Ponto* p){
    tela[p->x][p->y] = ESPACO;
    p->x--;
    p->y++;
    tela[p->x][p->y] = PONTO;  
}
void diagonalSupEsquerda (char tela[ALTURA][LARGURA], Ponto* p){
    tela[p->x][p->y] = ESPACO;
    p->x--;
    p->y--;
    tela[p->x][p->y] = PONTO;    
}
void diagonalInfDireita (char tela[ALTURA][LARGURA], Ponto* p){
    tela[p->x][p->y] = ESPACO;
    p->x++;
    p->y++;
    tela[p->x][p->y] = PONTO;  
}
void diagonalInfEsquerda (char tela[ALTURA][LARGURA], Ponto* p){
    tela[p->x][p->y] = ESPACO;
    p->x++;
    p->y--;
    tela[p->x][p->y] = PONTO;    
}

//funcoes para sentido reto da bolinha
void sobe (char tela[ALTURA][LARGURA], Ponto* p) {
  tela[p->x][p->y] = ESPACO;
  p->x--;
  tela[p->x][p->y] = PONTO;
}

void desce (char tela[ALTURA][LARGURA], Ponto* p) {
  tela[p->x][p->y] = ESPACO;
  p->x++;
  tela[p->x][p->y] = PONTO;
}


void moveRaquete (char tela[ALTURA][LARGURA], Raquete* r) {
  
  if (r->b == ESQUERDA) {
    if (r->y1 > 1) {
      esquerdaRaquete(tela, r);
      r->b = STOP;
    }
    else {
      r->b = DIREITA;
      direitaRaquete(tela, r);
    }
  }
  else if (r->b == DIREITA) {
    if (r->y3 < LARGURA - 2) {
      direitaRaquete(tela, r);
       r->b = STOP;

    }
    else {
      r->b = ESQUERDA;
      esquerdaRaquete(tela, r);
    }
  }
}
void esquerdaRaquete (char tela[ALTURA][LARGURA], Raquete* r) {
  tela[r->x][r->y1] = ESPACO;
  tela[r->x][r->y2] = ESPACO;
  tela[r->x][r->y3] = ESPACO;
  r->y1--;
  r->y2--;
  r->y3--;
  tela[r->x][r->y1] = RAQUETE;
  tela[r->x][r->y2] = RAQUETE;
  tela[r->x][r->y3] = RAQUETE;
}

void direitaRaquete (char tela[ALTURA][LARGURA], Raquete* r) {
  tela[r->x][r->y3] = ESPACO;
  tela[r->x][r->y2] = ESPACO;
  tela[r->x][r->y1] = ESPACO;
  r->y3++;
  r->y2++;
  r->y1++;
  tela[r->x][r->y3] = RAQUETE;
  tela[r->x][r->y2] = RAQUETE;
  tela[r->x][r->y1] = RAQUETE;
}
void muda_direcaoRaquete (Raquete* r, int b) {
  if (b == 'n') {
    r->b = ESQUERDA;
  }
  
  else if (b == 'm') {
    r->b = DIREITA;
  }
  
}