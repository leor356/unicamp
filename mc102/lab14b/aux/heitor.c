/* Nome: Heitor Boschirolli Comel
 * R.A: 169477 */

#include <stdio.h>
#include <stdlib.h>

void combinacoes(int **matriz, int *custos, int num_parlamentares, int 
   tam_partido, int temp[], int next, int size, int *preco_total);

int verifica (int *temp, int size, int prox);

int influencias (int **matriz, int linha, int num_parlamentares, int size, int 
   *temp);

int main() {
	/* Variaveis de entrada */
	int num_parlamentares, tam_partido, *custos, **matriz;
	
	/* Variaveis de controle de laco */
	int i, j;
	
	/* Variaveis auxiliares */
	int preco_total = 0, *temp;
	
	/* Le a primeira linha da entrada */
	scanf("%d %d", &num_parlamentares, &tam_partido);
	
	/* Aloca espaco para os custos dos parlamentares , para a matrize para temp 
		*/
	custos = malloc(num_parlamentares * sizeof(int));
	
	matriz = malloc( num_parlamentares * sizeof(int *));
	for (i = 0; i < num_parlamentares; i++)
		matriz[i] = malloc (num_parlamentares * sizeof(int));
	
	temp = malloc(tam_partido * sizeof(int));
	
	/* Le o restante da entrada */
	for (i = 0; i < num_parlamentares; i++)
		scanf("%d", &custos[i]);
	
	for (i = 0; i < num_parlamentares; i++)
		for (j = 0; j < num_parlamentares; j++)
			scanf("%d", &matriz[i][j]);
		
	combinacoes (matriz, custos, num_parlamentares, tam_partido, temp, 1, 
	   0, &preco_total);

	return 0;
	}

void combinacoes(int **matriz, int *custos, int num_parlamentares, int 
				 tam_partido, int temp[], int next, int size, int 
				 *preco_total) {
	int i;
	int tem, influenciados;
	
	if (size >= tam_partido) {
		*preco_total = 0;
		for (i = 0; i < tam_partido; i++)
			printf("%d ", temp[i]);
		printf("preco total = %d\n", *preco_total);
	}
	
	for (i = next; i <= num_parlamentares; i++) {
		/* Verifica se o parlamentar ja esta no partido */
		tem = verifica (temp, size, i);
		/* Caso o parlamentar ainda nao esteja no partido ...  */
		if (tem == 0) {
			/* ... insere ele no vetor */
			temp[size] = i;
			/* Veririca quantos e quais parlamentares ele influencia */
			influenciados = influencias(matriz, i, num_parlamentares, size, 
										temp);
			if (size + influenciados <= tam_partido)
			combinacoes(matriz, custos, num_parlamentares, tam_partido, 
						temp, i + 1, size + influenciados, preco_total);
		}
		
		/* Caso o parlamentar a ja estivesse no partido */
		else {
			combinacoes(matriz, custos, num_parlamentares, tam_partido, temp, 
						i + 1, size, preco_total);
		}
			
			
	}
}

int verifica (int *temp, int size, int prox) {
	int i = 0;
	
	for (i = 0; i < size; i++) {
		if (temp[i] == prox)
			return 1;
	}
	
	return 0;
}

int influencias (int **matriz, int linha, int num_parlamentares,int size, int 
				 *temp) {
	int i, aux = 1, tem;
	
	for (i = 0; i < num_parlamentares; i++)
		if (matriz[linha - 1][i] == 1) {
			tem = verifica(temp, size + 1, i + 1);
			if (tem == 0) {
				temp[++size] = i + 1;
				aux++;
			}
		}
				  
	return aux;
}