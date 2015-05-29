/*
Leonardo de Oliveira Ramos
RA: 171941
Professor: Zanoni Dias

*/

#include <stdio.h>
#include <math.h>

int main(){
  
  int cons_anterior, cons_atual;
  float valor_final, valor_orig, correcao;
  
  scanf("%i %i", &cons_anterior, &cons_atual);
  
  /*Calculo do preco de acordo com o consumo*/
  if(cons_atual >= 1 && cons_atual <= 10){
    valor_orig = 17.34;
  }
  else if(cons_atual >= 11 && cons_atual <= 20){
    valor_orig = ((cons_atual - 10) * 2.41) + 17.34;
  }
  else if(cons_atual >= 21 && cons_atual <= 50){
    valor_orig = ((cons_atual - 20) * 3.70) + 41.44;
  }
  else if(cons_atual > 50){
    valor_orig = ((cons_atual - 50) * 4.43) + 152.44;
  }
    
  /*Condicional que ajusta a correcao que aplica a multa */
  if(cons_atual > cons_anterior){
    if(cons_atual/(float)cons_anterior >= 1.2){
      correcao = 2;
    }
    else if(cons_atual/(float)cons_anterior < 1.2){
      correcao = 1.4;
    }
  } 
  
  /*Condicional que ajusta a correcao que aplica o desconto */
  if(cons_atual <= cons_anterior){
    if(cons_atual/(double)cons_anterior > 0.9){
      correcao = 1;
    }
    else if(cons_atual/(double)cons_anterior > 0.85){
      correcao = 0.9;
    }
    else if(cons_atual/(double)cons_anterior > 0.8){
      correcao = 0.8;
    }
    else if(cons_atual/(double)cons_anterior <= 0.8){
      correcao = 0.7;
    }
  } 
  
  
  /*aplicacao da correcao e envio de resultados*/
  valor_final = valor_orig * correcao;
  printf("Valor original = %.2f\nValor final = %.2f\n", valor_orig, valor_final);
  
  return 0;
}
