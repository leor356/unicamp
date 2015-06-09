/*
  Aluno: Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
  
  int i;

  for(i=1;i<=10;i++){
    if(i<10)
      printf("./lab12a ./testes/arq0%d.in ./testes/arq0%d.out\n", i, i);
    else
      printf("./lab12a ./testes/arq%d.in ./testes/arq%d.out\n", i, i);
  }
  
  return 0;
}
