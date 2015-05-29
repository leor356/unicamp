/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#define MAX 50

int main() {
  
  /*
    nLinhas eh o numero de nLinhas
    nColunas eh o numero de nColunas
    matriz[i][j] eh a matriz de entrada
    nPessoas eh o numero de pessoas atingidas pelo raio
    maiorNum eh o valor do maior nPessoas
    limitek e limitel sao os valores limite para fazer a varredura da matriz (os limites servem para nao haver testes desnecessarios de soma)
    i, j, k, l sao contadores
  */
  int nLinhas, nColunas, matriz[MAX][MAX], raio, nPessoas, maiorNum = 0, i, j, k, l, limitek, limitel;
  
  scanf("%d %d %d", &nLinhas, &nColunas, &raio);
  
  /* Entrada da matriz */
  for(i=0;i<nLinhas;i++){
    for(j=0;j<nColunas;j++){
      scanf("%d", &matriz[i][j]);
    }
  }
  
  /* raio se transforma no diametro e calculo dos limites da varredura */
  raio = (2*raio)+1;
  limitek = nLinhas - raio + 1;
  limitel = nColunas - raio + 1;
  
  /* Calculo do maior numero de pessoas que podem ser atingidas pelo raio */
  for(k=0;k<limitek;k++){
    for(l=0;l<limitel;l++){
      nPessoas = 0;
      for(i=k;i<(raio+k);i++){
	for(j=l;j<(raio+l);j++){
	  nPessoas += matriz[i][j];
	}
      }
      if(nPessoas > maiorNum){
	maiorNum = nPessoas;
      }
    }
  }
  
  printf("%d\n", maiorNum);
  
  return 0;
}