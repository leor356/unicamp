/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>

int main() {
  
  
  /* Declaracao das seguintes variaveis:
     qtdtotal eh a quantidade total de pessoas
     qtdlotes quantidade de lotes
     qtdcastas quantidade de castas
     numdacasta[n] eh o indicador da n-esima casta
     j, i, k sao contadores     
     casta eh a variavel que recebe os valores das castas de cada lotes   */
  int qtdtotal=0, qtdlotes, qtdcastas, numdacasta[9], j, i, k;
  char casta;
  
  scanf("%d %d\n", &qtdlotes, &qtdcastas);
  
  /* Inicializando numdacasta[] */
  for(k=0;k<=9;k++){
    numdacasta[k] = 0;
  }
  
  /* Contador que incrementa cada vez que casta == '\n'
     Caso nao incremente, conta o numero total de pessoas e soma para sua casta */
  for (j=0;j<qtdlotes;){
    scanf("%c", &casta);
    
    if(casta=='\n'){
      j++;
    } else{
      qtdtotal++;
      numdacasta[casta-'1']++;
    }
  }
  
  /* Impressao dos valores do total de individuos e o total d individuos de cada casa */
  printf("Total: %d individuos\n",qtdtotal);
  for (i=0;i<qtdcastas;i++){
    printf("Total da casta %d: %d\n",i+1 ,numdacasta[i]);
  }
  
  /* Calcula e imprime o percentual de individuos de cada casta */
  for (i=0;i<qtdcastas;i++){
    printf("Percentual da casta %d: %.2f\n",i +1 , 100* (double)numdacasta[i]/qtdtotal);
  }
  
  
  return 0;
}