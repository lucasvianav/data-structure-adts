// AUTHOR: LUCAS VIANA VILELA 10748409

#include <stdio.h>
#include <string.h>
#include "lista.h"

// Constantes para representar os valores que indicam cada uma das funções possíveis
#define DELETE 2
#define INSERT 3
#define REMOVE 4
#define SEARCH 5
#define PRINT 6
#define COUNT 7
#define IS_FULL 8
#define IS_EMPTY 9
#define EXIT 0

int main(){
    float auxOp, auxNoOp, auxPos, auxKey; // Variáveis auxiliar que serão utilizadas para receber os inputs (podendo o input ser float ou int)
    int operation; // Identifica a operação solicitada pela entrada
    int noOperations; // Identifica quantas operações do tipo 'operation' serão realizadas
    int position; // Posição em que será inserido determinado filme
    LISTA *database = lista_criar(); // Lista para armazenar os filmes
    ITEM movie; // Variável auxiliar para armazenar nomes e chaves

    while(1){
        scanf("%f", &auxOp);
        operation = (int)auxOp; // Esta linha (e todas as outra similares ao longo do código) serve para truncar o valor recebido (seja int ou float) em um int

        switch (operation){ // De acordo com o valor de 'operations':
            case DELETE: // Apaga a lista
                printf("%d\n", lista_apagar(&database)); // Apaga a lista e printa o resultado

                database = lista_criar(); // Cria uma nova lista

                break;

            case INSERT: // Insere 'noOperations' itens na lista
                scanf("%f", &auxNoOp);
                noOperations = (int)auxNoOp;

                for(int i = 0; i < noOperations; i++){ // Para cada item a ser inserido
                    scanf("%f %s %f", &auxKey, movie.titulo, &auxPos); // Recebe as informações
                    movie.chave = (int)auxKey;
                    position = (int)auxPos;

                    printf("%d\n", lista_inserir_pos(database, movie, position)); // Insere na lista e printa o resultado
                }

                break;
            
            case REMOVE: // Remove 'noOperations' itens da lsita
                scanf("%f", &auxNoOp);
                noOperations = (int)auxNoOp;

                for(int i = 0; i < noOperations; i++){ // Para cada item a ser removido
                    scanf("%f", &auxKey); // Recebe a chave
                    movie.chave = (int)auxKey;

                    printf("%d\n",lista_remover(database,movie.chave)); // Remove da lista e printa o resultado
                }

                break;

            case SEARCH: // Busca a posição de 'noOperations' itens na lista
                scanf("%f", &auxNoOp);
                noOperations = (int)auxNoOp;

                for(int i = 0; i < noOperations; i++){ // Para cada item a ser buscado
                    scanf("%f", &auxKey); // Recebe a chave 
                    movie.chave = (int)auxKey;

                    printf("%d\n", lista_buscar(database, movie.chave)); // Printa sua posição na lista
                }

                break;

            case PRINT: // Imprime toda a lista
                lista_imprimir(database);

                break;

            case COUNT: // Conta quantos itens a lista contém atualmente
                printf("%d\n", lista_tamanho(database)); // Printa o tamanho da lista

                break;

            case IS_FULL: // Checa se a lista está cheia
                printf("%d\n", lista_cheia(database)); // Printa o resultado

                break;

            case IS_EMPTY: // Checa se a lista está vazia
                printf("%d\n", lista_vazia(database)); // Printa o resultado

                break;

            case EXIT: // Encerra a execução do programa
                lista_apagar(&database); // Apaga a lista

                return 0; // Encerra o programa
        }

    }

}