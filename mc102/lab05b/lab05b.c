/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#define NUM 100
#define NCAR 27

int main() {
  
  /*
    distTchon eh a distancia Tchonsky
    caracteres[i] eh o vetor que guarda as informacoes do caractere i referente ao abecedario
    tamA eh o tamanho da stringA
    tamB eh o tamanho da stringB
    i eh um contador
    stringA eh a primeira string enviada
    stringB eh a segunda string enviada
  */
  int distTchon = 0, caracteres[NCAR], tamA = 0, tamB = 0, i;
  char stringA[NUM + 1], stringB[NUM + 1];
  
  /* inicializando o vetor 'caracteres' */
  for(i=0;i<NCAR;i++)
    caracteres[i] = 0;
  
  scanf("%s %s", stringA, stringB);
  
  /* Calculando o tamanho das strings */
  while(stringA[tamA])
    tamA++;
  while(stringB[tamB])
    tamB++;
  
  /* Conversao de caixa alta para caixa baixa */
  for(i=0;i<tamA;i++)
    if(stringA[i] >= 'A' && stringA[i] <= 'Z')
      stringA[i] = stringA[i] + 'a' - 'A';
  for(i=0;i<tamB;i++)
    if(stringB[i] >= 'A' && stringB[i] <= 'Z')
      stringB[i] = stringB[i] + 'a' - 'A';
  
  /* Encontrando a diferenca entre as 2 strings */
  for(i=0;i<tamA;i++)
    caracteres[stringA[i] - 'a']++;
  for(i=0;i<tamB;i++)
    caracteres[stringB[i] - 'a']--;
  for(i=0;i < NCAR;i++){
    if(caracteres[i]<0)
      caracteres[i] = -caracteres[i];
    distTchon += caracteres[i];
  }
  
  printf( "Distancia de Tchonsky = %d\n", distTchon);
  
  return 0;
}