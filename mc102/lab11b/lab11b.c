/* Laboratorio 11b - Brasil, o Pais do Volei
 * Nome:
 * RA:
 */

#include <stdio.h>
#include <string.h>

struct time {
   char nome[21];
   int indice, pontos, vitorias;
   int pontosGanhos, pontosPerdidos, setsGanhos, setsPerdidos; 
};
typedef struct time time_t;

/* Encontra em timesChave[] uma string nomeTime */
int encontraTime(char nomeTime[], time_t timesChave[],int numeroDeTimes){
   int i;
   for(i=0;i<numeroDeTimes;i++){
      if(!(strcmp(nomeTime, timesChave[i].nome)))
         return i;
   }
   return -1;
}

/* Insere uma nova string nomeTime em timesChave */
int insereNaChave(char nomeTime[], time_t timesChave[], int *numeroDeTimes){
   strcpy(timesChave[*numeroDeTimes].nome, nomeTime);
   (*numeroDeTimes)++;
   return (*numeroDeTimes)-1;
}

/* Troca time1 por time2 */
void trocaTimes(time_t *time1, time_t *time2){
   time_t aux;
   aux = *time1;
   *time1 = *time2;
   *time2 = aux;
}

/* Inicializa os valores de timesChave */
void inicializaTimes(time_t timesChave[]){
   int i;
   for(i=0;i<6;i++){
      timesChave[i].indice = i;
      timesChave[i].setsGanhos = 0;
      timesChave[i].setsPerdidos = 0;
      timesChave[i].pontosGanhos = 0;
      timesChave[i].pontosPerdidos = 0;
      timesChave[i].pontos = 0;
      timesChave[i].vitorias = 0;
   }
}

/* Procura o melhor classificado entre i+1 e 6 em times[] */
int melhorClassificado(time_t times[], int i, int confrontoDireto[][6]){
   
   int jMax = i, j;
   double razaoPontosTime, razaoPontosMax, razaoSetsTime, razaoSetsMax;

   for(j=i+1;j<6;j++){

      /* Troca por pontos */
      if(times[j].pontos > times[jMax].pontos){
         jMax = j;
      }else if(times[j].pontos == times[jMax].pontos){

         /* Troca por vitorias */
         if(times[j].vitorias > times[jMax].vitorias){
            jMax = j;
         }else if(times[j].vitorias == times[jMax].vitorias){

            /* Troca por razao de sets */
            razaoSetsTime = (double)times[j].setsGanhos / (times[j].setsGanhos + times[j].setsPerdidos);
            razaoSetsMax = (double)times[jMax].setsGanhos / (times[jMax].setsGanhos + times[jMax].setsPerdidos);

            if(razaoSetsTime > razaoSetsMax){
               jMax = j;
            }else if(razaoSetsTime == razaoSetsMax){

               /* Troca por razao de pontos */
               razaoPontosTime = (double)times[j].pontosGanhos / (times[j].pontosGanhos + times[j].pontosPerdidos);
               razaoPontosMax = (double)times[jMax].pontosGanhos / (times[jMax].pontosGanhos + times[jMax].pontosPerdidos);

               if(razaoPontosTime > razaoPontosMax){
                  jMax = j;
               }else if(razaoPontosTime == razaoPontosMax){

                  /* Troca por confronto direto */
                  if(confrontoDireto[times[j].indice][times[jMax].indice] == 1){
                     jMax = j;
                  }
               }
            }
         }
      }
   }
   return jMax;
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
   /*
      time1[] eh time2[] sao os nomes dos times lidos
      i eh um contador
      venceu eh uma flag que vira 1 quando time1 ganha ou 2 quando o time2 ganha
      res1 e res2 sao os pontos marcados pelo time1 e time2
      sets1 e sets2 sao o numero de sets ganhos pelo time1 e time2
      pontos1 sao a soma de  todos res1 assim como pontos2 de todos res2
      indTimei eh o indice do timei em timesChave
      numeroDeTimes eh quantos times ja foram adicionados em timesChave
   */
   char time1[21], time2[21];
   int i, venceu, res1, res2, sets1, sets2,
       pontos1, pontos2, indTime1, indTime2, numeroDeTimes=0;

   inicializaTimes(timesChave);

   /* Le as entradas */
   for(i=0;i<15;i++){
      venceu = 0;
      sets1 = 0;
      sets2 = 0;
      pontos1 = 0;
      pontos2 = 0;
      scanf("%s %s", time1, time2);

      /* Le o resultado dos sets ate um time ganhar */
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

      /* Procura o indice dos times e se nao encontrar insere o time */
      indTime1 = encontraTime(time1, timesChave, numeroDeTimes);
      if(indTime1 == -1)
         indTime1 = insereNaChave(time1, timesChave, &numeroDeTimes);

      indTime2 = encontraTime(time2, timesChave, numeroDeTimes);
      if(indTime2 == -1)
         indTime2 = insereNaChave(time2, timesChave, &numeroDeTimes);

      /* Atualizando os valores de time1 e time2 em timesChave */
      atualizaSetsPontos(&timesChave[indTime1], sets1, sets2, pontos1, pontos2);
      atualizaSetsPontos(&timesChave[indTime2], sets2, sets1, pontos2, pontos1);

      /* Atualizando os pontos de classificacao */
      if(venceu == 1)
         atualizaPartida(&timesChave[indTime1], &timesChave[indTime2], sets1 - sets2, confrontoDireto);
      else if(venceu == 2)
         atualizaPartida(&timesChave[indTime2], &timesChave[indTime1], sets2 - sets1, confrontoDireto);
   }

}

/* Ordena o vetor de times */
void ordenaTimes(time_t times[], int n, int confrontoDireto[][6]) {
   int i, maior;

   /* Selection sort para ordenar os primeiros 4 de 6 */
   for(i=0;i<4;i++){
      maior = melhorClassificado(times, i, confrontoDireto);
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