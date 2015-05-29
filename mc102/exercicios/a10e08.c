/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>

int tamstring(char v[]);

int main(){
  char v[101];
  int i=0;
  
  do{
    scanf("%c", &v[i]);
  }while(v[i++]!='\n');
  v[i+1] = 0;
    
  printf("%d\n", tamstring(v));
  
  return 0;
}
int tamstring(char vec[]){
  int i=0;
  while(vec[i]){
    i++;
  }
  printf("\n");
  
  return i-1;
}
