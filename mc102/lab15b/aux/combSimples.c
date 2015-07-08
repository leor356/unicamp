#include <stdio.h>
#include <stdlib.h>

void imprime_vetor(int vetor[], int size) {
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", vetor[i]);
	printf("\n");
}

void combinacao_simples(int n, int size) {
	int i;
	if(n != size){
		for (i=0;i<n;i++){
			printf("(%d : %d)\n", i, size);
			combinacao_simples(n, size + 1);
		}
	}
}

int main() {
	int n;
	
	printf("Entre com o valor de n: ");
	
	scanf("%d", &n);
	

	combinacao_simples(n, 0);
	

	return 0;
}