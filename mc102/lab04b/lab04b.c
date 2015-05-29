/*
  Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>

int main() {
  
  int D, C, P, maiorP, sobra1, sobra2, i, j, k, l, X[100];
  
  scanf("%d %d", &D, &C);
  
  for(i=0;i<D;i++){
    scanf("%d",  &X[i]);
  }
  
  /* Inicializa maiorP com um possivel valor de P */
  sobra1 = C % X[0];
  maiorP = C/X[0];
  maiorP = (maiorP * X[1]) + sobra1;
  sobra2 = maiorP % X[2];
  maiorP = maiorP / X[2];
  maiorP = (maiorP * X[3]) + sobra2;
  
  /* Acha o maior soma de 2 intervalos */
  for(i=0;i<D;i++){
    for(j=i+1;j<D;j++){
      for(k=j+1;k<D;k++){
	for(l=k+1;l<D;l++){
	  if(X[l]>X[k]){
	    sobra1 = C % X[i];
	    P = (C / X[i]);
	    P = (P * X[j]) + sobra1;
	    sobra2 = P % X[k];
	    P = P / X[k];
	    P = (P * X[l]) + sobra2;
	  } else{
	    P = C / X[i];	    
	    sobra1 = C % X[i];
	    P = (P * X[j])+ sobra1;
	  }
	  if(P>maiorP){
	    maiorP = P;
	  }	  
	}
      }
    }
  }
  
  /* Verifica se houve lucro e volta a resposta */
  if(maiorP <= C){
    printf("Melhor nao investir agora, cara!\n");
  }else{
    printf("Capital final = R$%d\n", maiorP);
  }
  return 0;
}