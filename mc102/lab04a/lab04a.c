/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>

int main() {
  
  /* Flag eh a variavel que guarda o estado da garra */
  int X, Y, qtdcaixas[10], i, posicao=0, flag=0, capotou=0;
  char seta;
  
  scanf("%d %d",&X ,&Y);
  
  for(i=0; i<X; i++){
    scanf("%d", &qtdcaixas[i]);
  }
  
  do{
    scanf(" %c", &seta);
    
    /* Pegar e soltar da garra (movimento para baixo) */
    if(seta == 'D' && flag == 0 && qtdcaixas[posicao] > 0){
      qtdcaixas[posicao]--;
      flag = 1;
    }else if(seta == 'D' && flag == 1 && qtdcaixas[posicao] < Y){
      qtdcaixas[posicao]++;
      flag = 0;
    }
    
    /* Movimento para a direita */
    else if(seta == 'R' && posicao + 1 <   X){
      if(qtdcaixas[posicao + 1] >= Y && flag == 1){
	capotou=1;
      }
      posicao++;
    }
    /* Movimento para a esquerda */
    else if(seta == 'L' && posicao > 0){
      if(qtdcaixas[posicao - 1] >= Y && flag == 1){
	capotou=1;
      }
      posicao--;
    }
  }while(seta != '*');
  
  /* Impressao */
  if(capotou == 1){
    printf("Um acidente ocorreu\n");
  }else{
    printf("%d", qtdcaixas[0]);
    for(i=1;i<X;i++){
      printf(" %d", qtdcaixas[i]);
    }
    printf("\n");
  }
  
  return 0;
}