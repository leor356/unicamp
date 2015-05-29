/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#define NMAX 100

int main() {
  /* N eh o numero de guardioes
     contador[i] conta quantos intervalos continham o valor i
     a[i] e b[i] sao os valores do inicio e final do intervalo do i-esimo guardiao
     i, j, k, l, m sao contadores para o for
     numsincero eh o numero de guardioes sinceros
     primguardiao eh o numero do primeiro guardiao que disse a verdade */
  int N, contador[NMAX], a[NMAX], b[NMAX], i, j, numsincero, primguardiao=-1;
  
  scanf("%d", &N);
  
  /* Calcula quantas vezes o numero i estava dentro dos intevalos dados */
  for(i=0; i<N;i++)
    contador[i] = 0;
  for(i=0;i<N;i++){
    scanf("%d %d", &a[i], &b[i]);
    for (j=(a[i]-1); j<=(b[i]-1);j++)
      contador[j]++;
  }
  
  /* Verifica se o numero de guardioes sinceros bate com o contador e armazena o maior deles em numsincero */
  numsincero = contador[0];
  for(i=0;i<N;i++)
    if(contador[i] > numsincero && i + 1 == contador[i])
      numsincero = contador[i];

  printf("Numero de guardioes sinceros = %d\n", numsincero);
  
  /* verifica qual eh o primeiro guardiao a falar a verdade e para quando acha*/
  for(i=0;i<N && primguardiao == -1 ;i++)
    if(numsincero>=a[i] && numsincero<=b[i])
      primguardiao = i + 1;

  printf("Guardiao %d\n", primguardiao);
  
  return 0;
}
