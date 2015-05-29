/* Nome: Matheus Teixeira Corraleiro Felix
 * RA: 174693
 * Turma T
 * Laboratorio 10 A - Tag Cloud */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 /* Funcao pra zerar as ocorrencias que serao utilizadas inicialmente */
 void zera_ocorrencias(int *vetor, int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++)
        vetor[i] = 0;
 }       
 
 int main() {
    int max_palavras, min_ocor, tam_min, tam_max, i, *ocorrencias;
    char **texto, *aux;
 
    
    scanf("%d %d %d %d", &max_palavras, &min_ocor, &tam_min, &tam_max);
    
    /* Transformando o texto de entrada em uma 'lista' onde cada linha e uma palavra. */
 
    texto = malloc(sizeof (char*) * max_palavras);
    for (i = 0; i < max_palavras; i++)
    texto[i] = malloc(sizeof (char) * (tam_max + 1)); /* + 1 pro \0 */
    aux = malloc(sizeof (char) * (tam_max + 1));
    ocorrencias = malloc(sizeof (int) * max_palavras);
    zera_ocorrencias(ocorrencias, max_palavras);
    
    while (aux[0] != '*') {
        scanf("%s", aux);
        if (strlen(aux) >= tam_min) {
            for (i = 0; i < max_palavras; i++) {
                /* se a palavra ta aparecendo pela primeira vez */
                if (strcmp(aux, texto[i]) == strlen(aux)) { /* acho que ta errado, mas considerei uma casa VAZIA se a strcmp dela com a aux for igual à propria aux */
                    strcpy(texto[i], aux);
                    ocorrencias[i] = 1;
                }    
                else if (strcmp(aux, texto[i]) == 0 )
                    ocorrencias[i]++;
            }
        }                    
    }    
    
    
    /* Ler palavra por palavra, calcular o tamanho, ver se ela entra no minimo; se entrar, guardar ela num vetor de strings (matriz de char); isso se ela nunca apareceu. se ela tiver aparecido, apenas marcar q ela apareceu de novo, pelo vetor de ocorrencias: cada posicao dele equivale a uma linha da matriz de caracteres. para guardar quantas vezes cada uma parece. depois pra printar pegar as com mais ocorrencias e ir printando em ordem alfabética. usar a biblioteca string.h para calcular o tamanho, copiar a string na matriz e checar se uma palavra ja apareceu na matriz.*/
          
        
        
        
        
        
    free(texto);
    free(ocorrencias);
    
    return 0;
 }      
        
