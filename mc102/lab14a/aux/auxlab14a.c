/*
	Leonardo de Oliveira Ramos
	RA: 171941
	Sala: mc102r
	Professor: Zanoni Dias
*/

#include <stdio.h>
#define XMAX 10
#define YMAX 10
#define PMAX 9
#define CMAX 60
#define EMAX 60

void execucao(char matriz[][XMAX], char programas[][CMAX], char ordemDosProgramas[], int altura[], int *capotou,int X, int Y, int E){
	int i, j, k, posGarra=0;
	char segurando, condicao;
	/* Executando os programas em ordem */
	for (k=0;k<E;k++){
		i = ordemDosProgramas[k] - '1';
		j=0;
		do{
			/* Colocando a condicional */
			if(programas[i][j] == 'B' || programas[i][j] == 'Y' || programas[i][j] == 'G' || programas[i][j] == 'N' || programas[i][j] == 'A'){
				condicao = programas[i][j];
			}else {
				if(condicao == segurando || (condicao == 'A' && segurando != 0) || (condicao == 'N' && segurando == 0) || condicao == 0){
					/* Movimento da garra para a direita */
					if(programas[i][j] == 'R' && posGarra < X-1){
						if(matriz[0][posGarra + 1] != '.' && segurando != 0){
							*capotou=1;
							return;
						}
						posGarra++;
					}
					/* Movimento da garra para a esquerda */
					else if(programas[i][j] == 'L' && posGarra > 0){
						if(matriz[0][posGarra -1] != '.' && segurando != 0){
							*capotou=1;
							return;
						}
						posGarra--;
					}
					/* Movimento da garra para baixo */
					else if (programas[i][j] == 'D' && altura[posGarra] < Y && segurando == 0){
						segurando = matriz[altura[posGarra]][posGarra];
						matriz[altura[posGarra]][posGarra] = '.';
						altura[posGarra]++;
					}else if (programas[i][j] == 'D' && altura[posGarra] > 0 && segurando != 0){
						matriz[(altura[posGarra])-1][posGarra] = segurando;
						segurando = 0;
						altura[posGarra]--;
					}
				}
			condicao = 0;
			}
		}while(programas[i][j++] != '*');
	}
}


int main() {
	/*
		X eh o numero de posicoes existentes para o empilhamento
		Y eh o numero maximo de caixas que podem ser empilhadas
		P eh o numero de programas
		C eh o numero maximo de comandos por programa
		E eh o numero de execucoes de programas
		i j k sao contadores
		altura[i] eh a altura da i-esima coluna contando de cima para baixo
		posGarra eh a posicao da garra 
		capotou eh uma flag para saber quando houve um acidente
		matriz[i][j] eh a matriz de entrada do estado inicial das caixas
		ordemDosProgramas guarda a ordem em que os programas serao executados
		programas sao os programas de entrada do 
		segurando guarda o que a garra segura
		condicao guarda a condicional do comando
	*/
	int X, Y, P, C, E, i, j, altura[XMAX], capotou = 0;
	char matriz[YMAX][XMAX], ordemDosProgramas[EMAX], programas[PMAX][CMAX];
	
	/* Escaneando as entradas, inicializando as alturas com o valor de Y e calculando a altura */
	scanf("%d %d %d %d %d", &X, &Y, &P, &C, &E);
	for(i=0;i<X;i++)
		altura[i] = Y;
	for(i=0;i<Y;i++){
		for(j=0;j<X;j++){
			scanf(" %c", &matriz[i][j]);
			if (matriz[i][j] != '.' && i < altura[j])
				altura[j] = i;
		}
	}
	for(i=0;i<E;i++)
		scanf(" %c", &ordemDosProgramas[i]);
	for(i=0;i<P;i++){
		j=0;
		do
			scanf(" %c", &programas[i][j]);
		while(programas[i][j++] != '*');
	}
	
	execucao(matriz, programas, ordemDosProgramas, altura, &capotou,X, Y, E);
	
	/* Verificando se houve um acidente e imprimindo a saida */
	if(capotou)
		printf("Um acidente ocorreu\n");
	else{
		for(i=0;i<Y;i++){
			for(j=0;j<X;j++)
	printf("%c", matriz[i][j]);
			printf("\n");
		}
	}
	return 0;
}