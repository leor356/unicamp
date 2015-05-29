/* Laboratorio 11b - Brasil, o Pais do Volei
 * Nome: Leonardo de Oliveira Ramos 
 * RA: 171941
 */

#include <stdio.h>
#include <string.h>

struct time {
   char nome[21];
   int indice, pontos, vitorias;
   int pontosGanhos, pontosPerdidos, setsGanhos, setsPerdidos; 
};
typedef struct time time_t;

int encontraTime(char *nomeTime, time_t *timesChave){
   int i;
   for(i=0;i<6;i++){
      if(!(strcmp(nomeTime, timesChave[i].nome)))
         return i;
   }
   return -1;
}
int insereNaChave(char *nomeTime, time_t *timesChave, int *numeroDeTimes){
   strcpy(timesChave[*numeroDeTimes].nome, nomeTime);
   (*numeroDeTimes)++;
   return (*numeroDeTimes)-1;
}

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
   char time1[21], time2[21];
   int i, venceu, res1, res2, sets1, sets2, pontos1, pontos2, indTime1, indTime2, numeroDeTimes=0, difsets;

   for(i=0;i<6;i++){
      timesChave[i].indice = i;
      timesChave[i].setsGanhos = 0;
      timesChave[i].setsPerdidos = 0;
      timesChave[i].pontosGanhos = 0;
      timesChave[i].pontosPerdidos = 0;
      timesChave[i].pontos = 0;
      timesChave[i].vitorias = 0;
   }

   for(i=0;i<15;i++){
      venceu = 0;
      sets1 = 0;
      sets2 = 0;
      pontos1 = 0;
      pontos2 = 0;
      scanf("%s %s", time1, time2);

      do{
         scanf(" %d", &res1);
         scanf("-");
         scanf("%d", &res2);
         if(res1>res2){
            sets1++;
            if(sets1==3)
               venceu = 1;
         }else{
            sets2++;
            if(sets2==3)
               venceu = 2;
         }
         pontos1 += res1;
         pontos2 += res2;
      }while(!venceu);

      indTime1 = encontraTime(time1, timesChave);
      if(indTime1 == -1)
         indTime1 = insereNaChave(time1, timesChave, &numeroDeTimes);

      indTime2 = encontraTime(time2, timesChave);
      if(indTime2 == -1)
         indTime2 = insereNaChave(time2, timesChave, &numeroDeTimes);

      atualizaSetsPontos(&timesChave[indTime1], sets1, sets2, pontos1, pontos2);
      atualizaSetsPontos(&timesChave[indTime2], sets2, sets1, pontos2, pontos1);

      if(venceu == 1){
         difsets = sets1 - sets2;
         atualizaPartida(&timesChave[indTime1], &timesChave[indTime2], difsets, confrontoDireto);
      }else if(venceu == 2){
         difsets = sets2 - sets1;
         atualizaPartida(&timesChave[indTime2], &timesChave[indTime1], difsets, confrontoDireto);
      }
   }
}

void trocaTimes(time_t *time1, time_t *time2){
   time_t aux;
   aux = *time1;
   *time1 = *time2;
   *time2 = aux;
}

/* Ordena o vetor de times */
void ordenaTimes(time_t times[], int n, int confrontoDireto[][6]) {
   int i, j, maior;
   double razaoPontosTime, razaoPontosAux, razaoSetsTime, razaoSetsAux;
   time_t aux;

   for(i=0;i<4;i++){

      aux = times[i];
      maior = i;
      for(j=i+1;j<6;j++){
         if(times[j].pontos > aux.pontos){
            maior = j;
            aux = times[j];
         }else if(times[j].pontos == aux.pontos){
            if(times[j].vitorias > aux.vitorias){
               maior = j;
               aux = times[j];
            }else if(times[j].vitorias == aux.vitorias){

               razaoSetsTime = (double) times[j].setsGanhos / (times[j].setsGanhos + times[j].setsPerdidos);
               razaoSetsAux = (double) aux.setsGanhos / (aux.setsGanhos + aux.setsPerdidos);

               if(razaoSetsTime > razaoSetsAux){
                  maior = j;
                  aux = times[j];
               }else if(razaoSetsTime == razaoSetsAux){

                  razaoPontosTime = (double) times[j].pontosGanhos / (times[j].pontosGanhos + times[j].pontosPerdidos);
                  razaoPontosAux = (double) aux.pontosGanhos / (aux.pontosGanhos + aux.pontosPerdidos);

                  if(razaoPontosTime > razaoPontosAux){
                     maior = j;
                     aux = times[j];
                  }else if(razaoPontosTime == razaoPontosAux){
                     if(confrontoDireto[times[j].indice][aux.indice] == 1){
                        maior = j;
                        aux = times[j];
                     }
                  }
               }
            }
         }
      }
      trocaTimes(&times[i], &times[maior]);
   }
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
