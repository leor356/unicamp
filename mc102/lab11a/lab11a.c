/*
  Aluno: Leonardo de Oliveira Ramos
  RA: 171941
  Sala: mc102r
  Professor: Zanoni Dias
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM1 20
#define TAM2 20

/* Chama de cadastro uma struct com os dados do cliente */
typedef struct {
  int conta, agencia;
  char nome[TAM1+1], sobrenome[TAM2+1];
  double saldo;
} Cadastro;

/* Encontra a pessoa que manda o dinheiro e a pessoa que recebe o dinheiro e coloca
   respectivamente em caraQueManda e caraQueRecebe */
void procuraOsCara(Cadastro *clientes, int C, int contaManda, int agenciaManda,
                   int contaRecebe, int agenciaRecebe, int *caraQueManda, int *caraQueRecebe){

  int i = 0;
  *caraQueManda = -1;
  *caraQueRecebe = -1;

  for(i=0;(i<C) && (*caraQueManda == -1 || *caraQueRecebe == -1);i++){
    if(clientes[i].conta == contaManda && clientes[i].agencia == agenciaManda){
      *caraQueManda = i;
    }
    if(clientes[i].conta == contaRecebe && clientes[i].agencia == agenciaRecebe){
      *caraQueRecebe = i;
    }
  }
}

int main(){

  /*
    C eh o numero de contas
    T eh o numero de transferencias
    i eh um contador
    contaManda eh uma variavel auxiliar que guarda clientes[i].conta de quem manda o dinheiro
    agenciaManda eh uma variavel auxiliar que guarda clientes[i].agencia de quem manda o dinheiro
    contaRecebe eh uma variavel auxiliar que guarda clientes[i].conta de quem recebe o dinheiro
    agenciaRecebe eh uma variavel auxiliar que guarda clientes[i].agencia de quem recebe o dinheiro
    caraQueManda eh o i de clientes[i] de quem manda o dinheiro
    caraQueRecebe eh o i de clientes[i] de quem manda o dinheiro
    valorDeTransf eh o valor da transferencia de dinheiro 
  */
  int C, T, i;
  int contaManda, agenciaManda, contaRecebe, agenciaRecebe, caraQueManda, caraQueRecebe;
  double valorDeTransf;

  Cadastro *clientes;

  scanf("%d %d", &C, &T);

  clientes = malloc(C * sizeof(Cadastro *));

  /* Le a entrada de clientes */
  for(i=0;i<C;i++){
    scanf("%d", &clientes[i].conta);
    scanf("@");
    scanf("%d %s %s %lf", &clientes[i].agencia, clientes[i].nome, clientes[i].sobrenome, &clientes[i].saldo);
  }

  /* Calcula todas as transferencias */
  for(i=0;i<T;i++){
    /* Entrada dos valores da transferencia */
    scanf("%d", &contaManda);
    scanf("@");
    scanf("%d", &agenciaManda);
    scanf(" >> ");
    scanf("%lf", &valorDeTransf);
    scanf(" >> ");
    scanf("%d", &contaRecebe);
    scanf("@");
    scanf("%d", &agenciaRecebe);

    /* Encontra a posicao do cliente que manda e do que recebe, e se nao encontrar retorna -1 */
    procuraOsCara(clientes, C, contaManda, agenciaManda, contaRecebe, agenciaRecebe, &caraQueManda, &caraQueRecebe);

    /* Caso tenha encontrado os clientes e quem manda tem dinheiro suficiente, realiza a transacao */
    if(valorDeTransf <= clientes[caraQueManda].saldo && caraQueManda !=-1 && caraQueRecebe != -1){
      clientes[caraQueManda].saldo -= valorDeTransf;
      clientes[caraQueRecebe].saldo += valorDeTransf;
    }
  }

  /* Imprime a saida */
  for(i=0;i<C;i++)
    printf("%d@%d %s %s %.2f\n", clientes[i].conta, clientes[i].agencia, clientes[i].nome, clientes[i].sobrenome, clientes[i].saldo);

  return 0;
}
