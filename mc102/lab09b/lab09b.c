/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#include <stdlib.h>

int indicemaiornum(double *P, int Q){
  int i, maiorI;
  double  maiorN;

  maiorN = P[0];
  maiorI = 0;
  for(i=1;i<Q;i++){
    if(P[i] > maiorN){
      maiorN = P[i];
      maiorI = i;
    }
  }
  return maiorI;
}

int main(){
  /*
    N eh a quantidade de pessoas
    T eh a quantidade de times
    i, j, k, l sao contadores
    escolhido eh o valor referente ao jogador escolhido pelo capitao
    equipe[i][j] onde i eh o time e j eh a ordem de escolha do i-esimo capitao
      onde equipe[i][j] recebe o numero do jogador
    matrizNotas[i][j] eh a matriz de entrada referente as notas dos jogadores
    media[i] eh o valor da media de notas do i-esimo jogador
  */
  int N, T, i, j, l=1, k=0, escolhido, **equipe;
  double **matrizNotas, *media;

  scanf("%d %d", &N, &T);

  /* Aloca espaco dinamicamente */
  media = malloc(N * sizeof(double));  
  matrizNotas = malloc(N * sizeof(double *));
  for(i=0;i<N;i++)
    matrizNotas[i] = malloc(N * sizeof(double));
  equipe = malloc(T * sizeof(int *));
  for(i=0;i<T;i++)
    equipe[i] = malloc(N * sizeof(int));
  
  /* Entrada dos valores da tabela de notas*/
  for(i=0;i<N;i++){
    media[i] = 0;
    for(j=0;j<N;j++){
      scanf("%lf", &matrizNotas[i][j]);
    }
  }

  /* Calcula a media do i-esimo jogador*/
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      media[i] += matrizNotas[j][i];
    }
    media[i] = media[i]/N;
  }

  /* Encontra o capitao to i-esimo time (equipe[i][0])
     e descarta a media e as notas do jogador (pois ja foi escolhido) */
  for(i=0;i<T;i++){
    equipe[i][0] = indicemaiornum(media, N);
    media[equipe[i][0]] = -1;
    for(j=0;j<N;j++)
      matrizNotas[j][equipe[i][0]] = -1;
  }
  
  /* Encontra os escolhidos pelo capitao (equipe[k][l]) */
  for(i=0;i<(N-T);i++){
      escolhido = indicemaiornum(matrizNotas[equipe[k][0]], N);
      equipe[k][l] = escolhido;
      for(j=0;j<N;j++)
        matrizNotas[j][escolhido] = -1;
      if(k == T-1){
        k = 0;
        l++;
      }else{
        k++;
      }
  }

  /* Imprime os times*/
  for(i=0;i<T;i++){
    printf("Time %d:", i+1);
    for(j=0;j<N/T;j++){
      printf(" %d",equipe[i][j] + 1);
    }
    printf("\n");
  }

  /* Liberando espaco alocado */
  free(equipe);
  free(matrizNotas);
  free(media);
  return 0;
}
