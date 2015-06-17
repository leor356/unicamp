/*
	Leonardo de Oliveira Ramos
	RA: 171941
	Sala: mc102r
	Professor: Zanoni Dias
*/

#include <stdio.h>
#include <stdlib.h>

void executa(char **caixas, int linhas, int colunas, char **programas, int i,
						 int *posGarra, char *segurando, char *condicao, int *altura,
						 int *execucoes, int maxExecucoes, int *capotou){
	int j=0;
	(*execucoes)++;
	/* Executa o comando enquanto nao encontrar um asterico */
	do
	{
		/* Verifica se capotou */
		if(*capotou)
			return;
		/* Caso tenha alguma condicao para o proximo comando, guarda na variavel 
			condicao */
		if(programas[i][j] == 'B' || programas[i][j] == 'Y' ||
			 programas[i][j] == 'G' || programas[i][j] == 'N' ||
			 programas[i][j] == 'A'){

			*condicao = programas[i][j];

		}else{
			/* Caso esteja na condicao, executa o comando*/
			if((*condicao == 0) || (*condicao == *segurando) || (*condicao == 'A' &&
					*segurando != 0) || (*condicao == 'N' && *segurando == 0)){

				/* Comando de movimento para a direita */
				if(programas[i][j] == 'R' && *posGarra < colunas-1){
					if(caixas[0][*posGarra + 1] != '.' && *segurando != 0)
						*capotou = 1;
					(*posGarra)++;
				}

				/* Comando de movimento para a esquerda */
				else if(programas[i][j] == 'L' && *posGarra > 0){
					if(caixas[0][*posGarra-1] != '.' && *segurando != 0)
						*capotou = 1;
					(*posGarra)--;
				}

				/* Comando para a abaixar a garra */
				else if (programas[i][j] == 'D' && altura[*posGarra] < linhas && 
								 *segurando == 0){
					*segurando = caixas[altura[*posGarra]][*posGarra];
					caixas[altura[*posGarra]][*posGarra] = '.';
					altura[*posGarra]++;
				}else if (programas[i][j] == 'D' && altura[*posGarra] > 0 &&
									*segurando != 0){
					caixas[(altura[*posGarra])-1][*posGarra] = *segurando;
					*segurando = 0;
					altura[*posGarra]--;
				}

				/* Comando de chamar outro programa */
				else if(programas[i][j] >= '1' && programas[i][j] <= '9' &&
								*execucoes < maxExecucoes){
					executa(caixas, linhas, colunas, programas, programas[i][j] - '1',
									posGarra, segurando, condicao, altura, execucoes,
									maxExecucoes, capotou);
				}
			}
			/* Apos executar o comando, reseta a condicao */
			*condicao = 0;
		}
	}while(programas[i][++j] != '*');
}


int main() {
	/*
	caixas[i][j] eh a matriz de posicao das caixas
	programas[i][j] tem i programas com j comandos
	condicao guarda o valor da condicao de execucao (G, B, Y)
	segurando guarda a caixa que a garra segura
	colunas e linhas sao o valor X e Y referentes aos lados da matriz caixas
	numProgramas numComandos sao numeros P e C de programas e de comandos maximo
	maxExecucoes eh o valor E do maximo de execucoes
	i e j sao contadores
	capotou eh uma flag para dizer se houve um acidente
	altura[i] eh um vetor com as alturas de caixas
	posGarra eh o valor referente a posicao da garra
	execucoes eh o valor de quantas execucoes ja aconteceram
	*/
	char **caixas, **programas, condicao=0, segurando=0;
	int colunas, linhas, numProgramas, numComandos, maxExecucoes, i, j, capotou=0,
			*altura, posGarra=0, execucoes=0;

	/* Entrada dos valores de X, Y, P, C, E */
	scanf(" %d %d %d %d %d", &colunas, &linhas, &numProgramas, &numComandos,
													 &maxExecucoes);

	/* Alocacao de memoria para os vetores e matrizes */
	altura = malloc(colunas * sizeof(int));

	caixas = malloc(linhas * sizeof(char *));
	for(i=0;i<linhas;i++)
		caixas[i] = malloc(colunas * sizeof(char));
	
	programas = malloc(numProgramas * sizeof(char *));
	for(i=0;i<numProgramas;i++)
		programas[i] = malloc((numComandos+1) * sizeof(char));

	/* Entrada das posicoes das caixas e calculo das alturas */
	for(i=0;i<colunas;i++)
		altura[i] = linhas;
	for(i=0;i<linhas;i++){
		for(j=0;j<colunas;j++){
			scanf(" %c", &caixas[i][j]);
			if (caixas[i][j] != '.' && i < altura[j])
			altura[j] = i;
		}
	}

	/* Entrada dos programas */
	for(i=0;i<numProgramas;i++){
		j=0;
		do{
			scanf(" %c", &programas[i][j]);
		}while(programas[i][j++] != '*');
	}
	
	/* Executa os testes */
	for(i=0;i<numProgramas && !capotou && execucoes < maxExecucoes;i++){
		executa(caixas, linhas, colunas, programas, i, &posGarra, &segurando,
						&condicao, altura, &execucoes, maxExecucoes, &capotou);
	}

	/* Verifica se capotou */
	if(capotou){
		printf("Um acidente ocorreu\n");
	}else{
		/* Imprime a saida */
		for(i=0;i<linhas;i++){
			for(j=0;j<colunas;j++){
				printf("%c", caixas[i][j]);
			}
			printf("\n");
		}
	}

	/* Desalocando espacos */
	for(i=0;i<linhas;i++)
		free(caixas[i]);
	free(caixas);

	for(i=0;i<numProgramas;i++)
		free(programas[i]);

	free(programas);
	free(altura);

	return 0;
}