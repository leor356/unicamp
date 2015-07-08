/*
	Aluno: Leonardo de Oliveira Ramos
	RA: 171941
	Sala: mc102r
	Professor: Zanoni Dias
*/

#include <stdio.h>
#include <stdlib.h>



int main(){

	int N, P, *V , i, j;


	scanf(" %d %d", &N, &P);

	V = malloc(N * sizeof(int));
	
	for(i=0;i<N;i++)
		scanf(" %d", &V[i]);	
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(i<j){
				printf("%d %d\n", i, j);
			}
		}
	}


	return 0;
}
