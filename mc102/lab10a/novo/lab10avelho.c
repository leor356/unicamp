/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Compara a entrada com as palavras na matriz texto
   retorna a posicao se encontrar ou retorna uma posicao nao possivel (-1) se nao encontrar */
int comparastring(char *palavra, char **texto, int tamPalavra, int qtdPalavras){
  int i;
  for(i=0;i<qtdPalavras;i++)
    if(strcmp(palavra, texto[i]) == 0)
      return i;
  return -1;
}
void copiaString(char *str1, char *str2){
  int i=0;
  do{
    str1[i] = str2[i];
  }while(str2[i++] != '\0');
}

/* Troca os valores de vet1 pelos de vet 1 assim como os de bucketPalavras1 por bucketPalavras2 */
void troca(char *vet1,char *vet2, int M, int *bucketPalavras1, int *bucketPalavras2){
  char *vetAux;
  int numAux;
  vetAux = malloc(M*sizeof(char));
  copiaString(vetAux, vet1);
  copiaString(vet1, vet2);
  copiaString(vet2, vetAux);
  free(vetAux);
  numAux = *bucketPalavras1;
  *bucketPalavras1 = *bucketPalavras2;
  *bucketPalavras2 = numAux;
}

/* Ordena a matriz vet em ordem lexicografica */
void ordenaLex(char **vet, int n, int M, int *bucketPalavras) {
  int i, j;
  for(i=n-1;i>0;i--)
    for(j=0;j<i;j++)
      if(strcmp(vet[j], vet[j+1])>0)
        troca(vet[j], vet[j+1], M, &bucketPalavras[j], &bucketPalavras[j+1]);
}


int main(){
  /*
    D eh o numero maximo de palavras diferentes
    F eh o numero minimo de ocorrencias para aparecer na saida
    L eh o menor tamanho da palavra a considerar
    M eh o tamanho maximo da palavra a considerar
    texto eh a matriz que contem as palavras diferentes
    palavra eh o vetor que contem a palavra lida
    i, j, k sao contadores
    tamPalavra eh tamanho da palavra lida
    palavrasNoTexto eh o numero de palavras incluidas na matriz texto
    maiorRepeticaoDasPalavras eh o maior valor de bucketPalavras
    iDaPalavra guarda o valor de i de texto que bate com o vetor palavra
    bucketPalavras[i] guarda em i o numero de recorrencias da palavra em texto[i]
  */
  int D, F, L, M, i, j, k;
  int tamPalavra, iDaPalavra, *bucketPalavras;
  int palavrasNoTexto=0, maiorRepeticaoDasPalavras=0;
  char **texto, *palavra;

  scanf("%d %d %d %d", &D, &F, &L, &M);
  
   /* Aloca espaco para os vetores e inicializa texto[i][j] */
  bucketPalavras = malloc((D+1) * sizeof(int));
  palavra = malloc((M+1) * sizeof(char));
  texto = malloc((D+1) * sizeof(char *));
  for(i=0;i<(D+1);i++)
    texto[i] = malloc((M) * sizeof(char));
  for(i=0;i<D;i++){
    bucketPalavras[i] = 0;
  }

  scanf(" ");

  /* Le palavra por palavra e coloca na matriz texto caso entre na condicao */
  do{
    scanf("%s", palavra);
    tamPalavra = strlen(palavra);
    if (tamPalavra>=L){
      iDaPalavra = comparastring(palavra, texto, tamPalavra, D);
      if(iDaPalavra == -1){
        copiaString(texto[palavrasNoTexto], palavra);
        bucketPalavras[palavrasNoTexto]++;
        palavrasNoTexto++;
      }else{
        bucketPalavras[iDaPalavra]++;
      }
    }
  }while(palavra[tamPalavra - 1] != '*');  

  /* Ordena a matriz texto */
  ordenaLex(texto, palavrasNoTexto, M+1, bucketPalavras);

  /* Procura a maior recorrencia de palavras */
  for(i=0;i<D;i++)
    if(maiorRepeticaoDasPalavras < bucketPalavras[i])
          maiorRepeticaoDasPalavras = bucketPalavras[i];

  /* Imprime em ordem decrescente de recorrencia */
  for (i=maiorRepeticaoDasPalavras;i>=F;i--){
    for(j=0;j<palavrasNoTexto;j++){
      if(bucketPalavras[j] == i){
        k=0;
        while(texto[j][k] != '\0'){
          printf("%c",texto[j][k]);
          k++;
        }
        printf(" %d\n", bucketPalavras[j]);
      }
    }
  }

  /* Libera os espacos utilizados */
  free(bucketPalavras);
  free(palavra);
  free(texto);
  return 0;
}
