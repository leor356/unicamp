/*
  Aluno: Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#include <stdlib.h>

int calculAltura(){
	/* alturaLocal eh o valor da altura da bomba atual 
		 altura eh a maior altura encontrada
		 subBombas eh o numero de sub bombas da bomba atual
	*/
	int alturaLocal, altura=0, subBombas;

	scanf(" %d", &subBombas);

	/* Quando a bomba nao tem sub bombas, */
	if(subBombas == 0)
		return 1;

	/* Para cada subBomba calcula a altura local eh 1 */
	while(subBombas > 0){		
		alturaLocal = calculAltura();

		/* Encontra a maior altura local*/
		if(alturaLocal > altura)
			altura = alturaLocal;
		subBombas--;
	}

	/* Retorna a altura das sub bombas somada com a proria altura */
	return altura + 1;
}

int main(){
	int altura;

  altura = calculAltura();
  
  printf("%d\n", altura);

  return 0;
}
