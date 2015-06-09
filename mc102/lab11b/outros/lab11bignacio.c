/* Laboratorio 11b - Brasil, o Pais do Volei
 * Nome: Ignacio Espinoso Ribeiro
 * RA:169767
 */

#include <stdio.h>
#include <string.h>
#define MAX 21

struct time {
   char nome[21];
   int indice, pontos, vitorias;
   int pontosGanhos, pontosPerdidos, setsGanhos, setsPerdidos;
};
typedef struct time time_t;

/* Atualiza os atributos relativos aos sets e aos pontos */
void atualizaSetsPontos(time_t *time, int setsGanhos, int setsPerdidos,
                        int pontosGanhos, int pontosPerdidos) {
   time->setsGanhos += setsGanhos;
   time->setsPerdidos += setsPerdidos;
   time->pontosGanhos += pontosGanhos;
   time->pontosPerdidos += pontosPerdidos;
}

/* Atualiza os atributos relativos as partidas */
void atualizaPartida(time_t *timeGanhador, time_t *timePerdedor,
                     int diferencaSets, int confrontoDireto[][6]) {
   timeGanhador->vitorias++;

   if (diferencaSets > 1)
      timeGanhador->pontos += 3;
   else {
      timeGanhador->pontos += 2;
      timePerdedor->pontos += 1;
   }

   confrontoDireto[timeGanhador->indice][timePerdedor->indice] = 1;
   confrontoDireto[timePerdedor->indice][timeGanhador->indice] = -1;
}









/* Le os resultados das partidas entre todos os times de uma chave */
void leResultadosChave(time_t timesChave[], int confrontoDireto[][6]) {
	int i = 0, j = 0, k = 0, pontos1 = 0, pontos2 = 0, flag = 0;
	int sets1 = 0, sets2 = 0, timesreg = 0;
	char aux1[MAX], aux2[MAX];

  for(i=0;i<6;i++){
      timesChave[i].indice = i;
      timesChave[i].setsGanhos = 0;
      timesChave[i].setsPerdidos = 0;
      timesChave[i].pontosGanhos = 0;
      timesChave[i].pontosPerdidos = 0;
      timesChave[i].pontos = 0;
      timesChave[i].vitorias = 0;
  }
	/*Le os resultados das 15 partidas da chave*/
	for(i = 0; i < 15; i++) {

		/*Verifica se o time 1 esta registrado na chave*/
		scanf("%s", aux1);
		for(j = 0, flag = 0; (j < 6) && (!flag) && (j < timesreg); j++) {
			if(strcmp(aux1, timesChave[j].nome) == 0)
				flag = 1;
		}
		if(flag)
			j--;
		/*Insere o time 1 caso nao esteja registrado*/
		if(flag == 0) {
			strcpy(timesChave[j].nome, aux1);
			timesreg++;
		}
		/*Obs.: 'j' armazena a posicao do time 1*/

		/*Verifica se o time 2 esta registrado na chave*/
		scanf(" %s", aux2);
		for(k = 0, flag = 0; (k < 6) && (!flag) && (k < timesreg); k++) {
			if(strcmp(aux2, timesChave[k].nome) == 0)
				flag = 1;
		}
		if(flag)
			k--;
		/*Insere o time 2 caso nao esteja registrado*/
		if(flag == 0) {
			strcpy(timesChave[k].nome, aux2);
			timesreg++;
		}
		/*Obs.: 'k' armazena a posicao do time 2*/

		sets1 = 0;
		sets2 = 0;
		/*Le os resultados da partida enquanto nenhum time ganhou 3 sets*/
		do {
			scanf(" %d-%d", &pontos1, &pontos2);
			/*Atualiza os dados do 1o time caso o mesmo tenha ganho o set*/
			if(pontos1 > pontos2) {
				atualizaSetsPontos(&timesChave[j], 1, 0, pontos1, pontos2);

				sets1++;
			/*Atualiza os dados do 2o time caso o mesmo tenha ganho o set*/
    	} else if (pontos2 > pontos1) {
    		atualizaSetsPontos(&timesChave[k], 1, 0, pontos2, pontos1);

    		sets2++;
    	}

		} while((sets1 < 3) && (sets2 < 3));
    /*Atualiza a pontuacao dos times com base em que venceu a partida*/
    if(sets1 > sets2){
        atualizaPartida(&timesChave[j], &timesChave[k],
                        (sets1-sets2), confrontoDireto);
    } else {
        atualizaPartida(&timesChave[k], &timesChave[j],
                        (sets2-sets1), confrontoDireto);
    }
  }

    printf("\n           Nome,  pts, Vi,  SG,  SP,  PG,   PP\n");
    for(i = 0; i < 6; i++) {

        printf("%15s   %2d   %2d   %2d   %2d   %3d   %3d\n",
            timesChave[i].nome, timesChave[i].pontos, timesChave[i].vitorias,
            timesChave[i].setsGanhos, timesChave[i].setsPerdidos,
            timesChave[i].pontosGanhos, timesChave[i].pontosPerdidos);
    }
}








/* Ordena o vetor de times */
void ordenaTimes(time_t times[], int n, int confrontoDireto[][6]) {
  
}

int main() {
   /* variaveis de entrada */
   time_t timesChaveA[6], timesChaveB[6];
   /* variaveis auxiliares */
   int i, confrontosChaveA[6][6], confrontosChaveB[6][6];

   /* le entrada */
   leResultadosChave(timesChaveA, confrontosChaveA);
   leResultadosChave(timesChaveB, confrontosChaveB);

   /* ordena os vetores de times na ordem de classificacao */
   ordenaTimes(timesChaveA, 6, confrontosChaveA);
   ordenaTimes(timesChaveB, 6, confrontosChaveB);

   /* imprime a saida */
   for (i = 0; i < 4; i++) {
      printf("%s x %s\n", timesChaveA[i].nome, timesChaveB[3-i].nome);
   }

   return 0;
}
