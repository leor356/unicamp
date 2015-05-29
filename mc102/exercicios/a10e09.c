/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>

void invstring(char vec[]);

int main(){
  
  int i=0;
  char vetor[100];
  
  do{
    scanf("%c", &vetor[i]);
  }while(vetor[i++]!='\n');
  vetor[i+1] = 0;
  
  invstring(vetor);
  
  i=0;
  while(vetor[i++]){
    printf("%c", vetor[i]);
  }
  
  return 0;
}
void invstring(char vec[]){
  char aux;
  int i, tam=0;
  while(vec[tam]){
    tam++;
  }
  tam=tam-2;
  printf("%d\n", tam);
  for(i=0;i<((tam)/2);i++){
    printf("trocando %c por %c\n", vec[i], vec[tam-i-1]);
    aux = vec[i];
    vec[i] = vec[tam-i-1];
    vec[tam-i-1] = aux;
  }
  return;
 }
