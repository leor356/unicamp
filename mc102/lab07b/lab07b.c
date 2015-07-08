/*
Leonardo de Oliveira Ramos
RA: 171941
Sala: mc102r
Professor: Zanoni Dias
*/

#include <stdio.h>
#define NMAX 50
#define MMAX 50
int main() {
/*
	N e M sao respectivamente o valor de linhas e colunas do tabuleiro
	i, j, p sao contadores
	armadilha, loop, saiu sao flags para caso tenha entrado em uma armadilha, um loop ou tenha saido do tabuleiro
	tempo eh o valor do tempo percorrido pelo robo ao andar pelo tabuleiro
	tloop eh o valor do tempo de um loop
	tabuleiro[i][j] eh a matriz de entrada do tabuleiro
	hisTabuleiro[i][j] eh uma matriz que guarda o tempo como historico de onde passou o robo
*/
	int N, M, i, j, p, armadilha, loop, saiu, tempo, tloop;
	char tabuleiro[NMAX][MMAX], hisTabuleiro[NMAX][MMAX];
	
/* Entrada de valores */
	scanf("%d %d", &N, &M);
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			scanf(" %c", &tabuleiro[i][j]);
		
/* Caminhada do robo e impressao dos dados */
	for(p=0;p<N;p++){
/* Inicializando i, j, saiu, loop, armadilha, tempo e hisTabuleiro(que recebe um valor que nunca coincida com a variavel tempo) */
		for(i=0;i<N;i++)
			for(j=0;j<M;j++)
			 hisTabuleiro[i][j] = -1;
		 i=p;
		 j=0;
		 saiu=0;
		 loop=0;
		 armadilha=0;
		 tempo=0;
/* Verifica se houve loop, caso contrario realiza o comando */
		 do{
			if(hisTabuleiro[i][j] != -1){
			 loop = 1;
		 }
		 else if(tabuleiro[i][j] == 'L'){
			 hisTabuleiro[i][j]=tempo;
			 j--;
			 tempo++;
		 }
		 else if(tabuleiro[i][j] == 'D'){
			 hisTabuleiro[i][j]=tempo;
			 i++;
			 tempo++;
		 }
		 else if(tabuleiro[i][j] == 'U'){
			 hisTabuleiro[i][j]=tempo;
			 i--;
			 tempo++;
		 }
		 else if(tabuleiro[i][j] == 'X'){
			 armadilha=1;
		 }
		 else if(tabuleiro[i][j] == 'R'){
			 if(j==M-1){
				 saiu=1;
			 }else{
				 hisTabuleiro[i][j]=tempo;
				 j++;
				 tempo++;
			 }
		 }
	 }while(armadilha==0 && loop==0 && saiu==0);
		 
	/* Imprime a saida certa */
		 if(armadilha){
			printf("Armadilha em (%d,%d) apos %d passo(s)\n", i+1, j+1, tempo);
		}else if(loop){
			tloop = tempo - hisTabuleiro[i][j];
			printf("Loop de tamanho %d\n", tloop);
		}else if (saiu){
			printf("Saiu em (%d,%d) apos %d passo(s)\n", i+1, M, tempo);
		}
	}
	
	return 0;
}