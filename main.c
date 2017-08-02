/* 
 * File:   main.c
 * Author: martinfranzner
 *
 * Created on September 20, 2016, 1:26 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "telaB.h"

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#define limpa_tela() system("cls")
#define dorme(milis) Sleep(milis)
#else
#include <unistd.h>
#include "consoleB.h"
#define limpa_tela() system("clear")
#define dorme(milis) usleep(milis * 1000)
#endif
/*
 * 
 */
int main(int argc, char** argv) {

  char tela[ALTURA][LARGURA];
  int direcao;
  Ponto p;
  Raquete r;
  int vidda = 40;
  int score;
  while(vidda > 0){
      
  inicializa(tela, &p, &r);
  
  
    while (vidda != 0) {
      
      limpa_tela();
      desenha(tela, &vidda, &score);
      if (kbhit()) {
        direcao = getch();
        //muda_direcao(&p, direcao);
        muda_direcaoRaquete (&r, direcao);
      }
      move(tela, &p, &r, &vidda, &score);
      moveRaquete (tela, &r);
      reinicia(tela, &p, &r);
      dorme(300);
     
    }
  
  
  }
  printf("\n******************** GAME OVER ********************\n");
    return (EXIT_SUCCESS);
}

