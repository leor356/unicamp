/* 
	Laboratorio 12a - Bola de Ouro
	Autor: Leonardo de Oliveira Ramos
	RA: 171941
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Tamanho maximo do nome do jogador */
#define MAXNOME 26
/* Tamanho maximo do nome dos arquivos de entrada/saida */
#define MAXNOMEARQ 101
/* Numero maximo de jogadores */
#define MAXJOGADORES 40

/* Jogador:
* nome = nome do jogador
* C1 = numero de gols
* C2 = numero de assistencias
* C3 = numero de dribles feitos
* C4 = numero de gols contra
* C5 = numero de cartoes vermelhos
* C6 = numero de cartoes amarelos
*/
struct Jogador {
	char nome[MAXNOME];
	int C1;
	int C2;
	int C3;
	int C4;
	int C5;
	int C6;
};

typedef struct Jogador Jogador;

int encontralelek(char nomeJogador[], Jogador leleks[], int numeroDeleleks){
	int i;
	for(i=0;i<numeroDeleleks;i++){
		if(!(strcmp(nomeJogador, leleks[i].nome)))
			return i;
	}
	return -1;
}
void troca(int *a, int *b, char leleki[], char lelekMax[]) {
	int aux;
	char chaux[MAXNOME];
	aux = *a;
	*a = *b;
	*b = aux;
	strcpy(chaux, leleki);
	strcpy(leleki, lelekMax);
	strcpy(lelekMax, chaux);
}

int indiceMaior(int vet[], int n, int inicio) {
	int j, max = inicio;
	for (j = inicio + 1; j < n; j++)
		if (vet[max] < vet[j])
			max = j;
	return max;
	}

int main(int argc, char **argv) {
	/* Nome do arquivo binario com as estatisticas */
	char nomeArqEstat[MAXNOMEARQ];
	/* Nome do arquivo binario de saida */
	char nomeArqSaida[MAXNOMEARQ];
	/*
		nomeJogaor[i] eh o nome de 
	*/
	char nomeJogador[MAXNOME];
	int i, j, pesos[6], C[6], R, N, numeroDeleleks=0, indlelek;
	int *pontuacao, max;
	Jogador leleks[MAXJOGADORES], aux;
	FILE *arqEntrada, *arqSaida;

	/* Lendo os nomes dos arquivos binarios */
	strcpy(nomeArqEstat, argv[1]);
	strcpy(nomeArqSaida, argv[2]);

	/* Lendo a entrada dos textos */
	for(i=0;i<6;i++)
		scanf("%d", &pesos[i]);

	/* Abrindo os arquivos de entrada e saida */
	arqEntrada = fopen(nomeArqEstat, "rb");
	arqSaida = fopen(nomeArqSaida, "wb");

	/* Lendo e armazenando os jogadores do arquivo binario */
	fread(&N, sizeof(int), 1, arqEntrada);
	for(j=0;j<N;j++){
		fread(&aux, sizeof(Jogador), 1, arqEntrada);
		indlelek = encontralelek(aux.nome, leleks, numeroDeleleks);
		if(indlelek == -1){
			indlelek = numeroDeleleks;
			leleks[numeroDeleleks] = aux;
			numeroDeleleks++;
		}
	}

	scanf(" %d", &R);
	/* Inicializando os Cs */
	for(i=0;i<R;i++){    
		leleks[i].C1 = 0;
		leleks[i].C2 = 0;
		leleks[i].C3 = 0;
		leleks[i].C4 = 0;
		leleks[i].C5 = 0;
		leleks[i].C6 = 0;
	}

	for(i=0;i<R;i++){
		scanf(" %d", &N);
		for(j=0;j<N;j++){
			/* Le o nome e procura o jogador,
			se nao encontrar adiciona um novo */    
			scanf("%s", nomeJogador);
			indlelek = encontralelek(nomeJogador, leleks, numeroDeleleks);
			if(indlelek == -1){
				indlelek = numeroDeleleks;
				strcpy(leleks[numeroDeleleks].nome, nomeJogador);
				numeroDeleleks++;
			}
			/* Le e a armazena os dados do jogador de indice indlelek */
			scanf(" %d %d %d %d %d %d", &C[0], &C[1], &C[2], &C[3], &C[4], &C[5]);
			leleks[indlelek].C1 += C[0];
			leleks[indlelek].C2 += C[1];
			leleks[indlelek].C3 += C[2];
			leleks[indlelek].C4 += C[3];
			leleks[indlelek].C5 += C[4];
			leleks[indlelek].C6 += C[5];
		}
	}

	/* Escreve o arquivo binario com a saida */
	fwrite(&numeroDeleleks, sizeof(int), 1, arqSaida);
	for(i=0;i<numeroDeleleks;i++){
		fwrite(&leleks[i], sizeof(Jogador), 1, arqSaida);
	}

	/* Calcula a pontuacao dos jogadores */
	pontuacao = malloc(numeroDeleleks * sizeof(int));
	for(i=0;i<numeroDeleleks;i++){
		pontuacao[i] = leleks[i].C1 * pesos[0] + leleks[i].C2 * pesos[1]
					 + leleks[i].C3 * pesos[2] - leleks[i].C4 * pesos[3]
					 - leleks[i].C5 * pesos[4] - leleks[i].C6 * pesos[5];
	}

	/* Encontra os 3 melhores jogadores e imprime na saida padrao */
	for(i=0;i<3;i++){
		max = indiceMaior(pontuacao, numeroDeleleks, i);
		troca(&pontuacao[i], &pontuacao[max], leleks[i].nome, leleks[max].nome);
		printf("%s\n", leleks[i].nome);
	}

	fclose(arqEntrada);
	fclose(arqSaida);
	free(pontuacao);

	return 0;
}
