/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Turma: MC102R 
*/

#include <stdio.h>

int main(){
  /* 
   res eh a somatoria ponderada;
   somaDoCredito eh o valor que dividirah a somatoria ponderada;
   definido eh uma flag que mostra que o numero foi processado pelo while que calcula a media;
   CR
   */
  int credito, somaDoCredito = 0, res = 0, definido =0;
  double CR = 0;
  char conceito;
  

  
  /*
   
   */
  
  while(scanf(" %c", &conceito) && conceito != '*') {
    
    definido = 1;
    
    
    scanf("%d", &credito);

    /* Calculo do CR de acordo com o credito e o conceito*/
    if(conceito == 'A'){
      res = res + 4 * credito;

    }else if (conceito == 'B' ){
      res = res + 3 * credito;

    }else if (conceito == 'C' ){
      res = res + 2 * credito;

    }else if (conceito == 'D' ){
      res = res + 1 * credito;

    }
    somaDoCredito = somaDoCredito + credito;
    
  }
  /* condicional para conferir se o CR eh definido ou nao */
  if(definido == 0){
    printf("CR = Indefinido\n");
  }
  else{
  CR = (double)res/somaDoCredito;
  printf("CR = %.4f\n", CR);
  }
  
  return 0;
}

