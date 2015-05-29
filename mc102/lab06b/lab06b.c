/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#define MAX 100


int main() {
  /*
    matrizE[MAX][MAX] eh a matriz de entrada
    M x N eh o tamanho da matriz
    i e j sao contadores
    tempo eh o valor do tempo necessario para espalhar pela sala + 2 (soma-se 2 ao tempo para facilitar os testes de detectar parede e de aspersor)
    flag eh verdadeira quando o gas se espalhou, e falso quando nao conseguiu se espalhar
    jedisvivos eh outra flag que mostra que existem lugares que nao sao alcancaveis pelo gas
  */
  int matrizE[MAX][MAX], M, N, i, j, tempo=2, flag=1, jedisvivos=0;
  
  /* Entrada de dados */
  scanf("%d %d", &M, &N);
  for(i=0;i<M;i++){
    for(j=0;j<N;j++){
      scanf("%d", &matrizE[i][j]);
    }
  }

  /* Espalha o gas pela sala e incrementa o tempo */
  while (flag){
  flag = 0;
    for(i=0;i<M;i++){
      for(j=0;j<N;j++){
	if(matrizE[i][j] == tempo){
	  if(matrizE[i+1][j] == 0 && i+1<M){
	    matrizE[i+1][j] = tempo + 1;
	    flag = 1;
	  }
	  if(matrizE[i-1][j] == 0 && i>0){
	    matrizE[i-1][j] = tempo + 1;
	    flag = 1;
	  }
	  if(matrizE[i][j+1] == 0 && j+1<N){
	    matrizE[i][j+1] = tempo + 1;
	    flag = 1;
	  }
	  if(matrizE[i][j-1] == 0 && j>0){
	    matrizE[i][j-1] = tempo + 1;
	    flag = 1;
	  }
	}
      }
    }
    tempo++;
  }

  /* Verifica se tem locais nao alcancaveis pelo gas e guarda na flag jedisvivos */
  for(i=0;i<M && jedisvivos == 0;i++){
    for(j=0;j<N && jedisvivos == 0;j++){
      if(matrizE[i][j] == 0){
	jedisvivos = 1;
      }
    }
  }

  /* Imprime a saida */
  if(jedisvivos)
    printf("Perigo: Jedis podem estar vivos\n");
  else
    printf("Tempo = %d\n", tempo-2);
  
  return 0;
}
