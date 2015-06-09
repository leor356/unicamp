/*
  Laboratorio 12a - Bola de Ouro
  Autor: Leonardo de Oliveira Ramos
  RA: 171941
*/

#include <stdio.h>
#include <string.h>

#define MAX_FILENAME 25
#define MAX_ENTITY 10

/* Funcao que converte uma entidade no caractere correspondente,
   supondo que o caractere '&' foi previamente lido no arquivo de
   entrada (arqin). Se a entidade eh diferente de aspas simples ou
   aspas dupla, a funcao simplesmente o ignora, caso contrario ela
   imprime o caractere correspondente no arquivo de saida (arqout). */
void converte_entidade(FILE *arqin, FILE *arqout) {
    char c, entidade[MAX_ENTITY];
    int i = 0;
    
    /* armazena o codigo da entidade ate encontrar o caractere ';' */
    c = fgetc(arqin);
    while (c != ';') {
        entidade[i++] = c;
        c = fgetc(arqin);
    }
    entidade[i] = '\0';
    
    /* se a entidade corresponde ao caractere aspas simples ou aspas duplas,
       imprime o caractere no arquivo de saida */
    if (!strcmp(entidade, "#39"))
        fprintf(arqout, "\'");
    else if(!strcmp(entidade, "quot"))
        fprintf(arqout, "\"");
}


void extrai_tweets (char *nomearqin, char *nomearqout){
    FILE *arqin, *arqout;
    char caractere;
    char identificador1[] = {"p class=\"ProfileTweet-text js-tweet-text u-dir\""};
    char identificador2[] = {"</p>"};
    int i=0,j=0, foraDoTweet, dentro=0;

    arqin = fopen(nomearqin, "r");
    arqout = fopen(nomearqout, "w");
    if(arqin == NULL || arqout == NULL){
      printf("Houve um problema com entrada de arquivos\n");
    }else{
        /* Leitura dos caracteres enquanto testa se encontrou o identificador de tweet */
        while (fscanf(arqin, "%c", &caractere) != EOF){
            if(caractere == identificador1[i]){
                i++;
                /* Quanto i chega em 46 significa que todos 
                os 47 caracteres do identificador sao iguais aos
                ultimos 47 caracteres lidos */
                if(i == 46){
                    i = 0;
                    foraDoTweet=0;
                    while((fscanf(arqin, "%c", &caractere) != EOF) && (!foraDoTweet)){
                        /* Imprime se estiver entre <p> </p> */
                        if(caractere == '<'){
                            dentro = 0;
                        }
                        if(dentro){
                            if(caractere == '&')
                                converte_entidade(arqin, arqout);
                            else
                                fprintf(arqout, "%c", caractere);
                        }else{
                            /* Caso nao esteja dentro verifica se terminou o tweet 
                            testando se os caracteres são </p> */
                            if(caractere == identificador2[j]){
                                j++;
                                if(j==3){
                                    j = 0;
                                    foraDoTweet = 1;
                                    fprintf(arqout, "\n");
                                }
                            }else{
                                j=0;
                            }
                        }
                        if(caractere == '>'){
                            dentro = 1;
                        }
                    }
                }
            }else{
                i=0;
            }
        }
    }

    fclose(arqin);
    fclose(arqout);
}


int main(int argc, char *argv[]) {  
    char nomearqin[MAX_FILENAME], nomearqout[MAX_FILENAME];
    
    /* Copia os nomes do arquivo de entrada e de saida nas variaveis */
    strcpy(nomearqin, argv[1]);
    strcpy(nomearqout, argv[2]);
 
    extrai_tweets(nomearqin, nomearqout);

    return 0;
}
