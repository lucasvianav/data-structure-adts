#include <stdio.h>
#include "abb.h"

#define CREATE 1
#define DELETE 2
#define INSERT 3
#define REMOVE 4
#define SEARCH 5
#define PRINT 6
#define GET_HEIGHT 7
#define EXIT 0

int main(){
    float auxOp, auxNoOp, auxKey; // Variáveis auxiliar que serão utilizadas para receber os inputs (podendo o input ser float ou int)
    int operation; // Identifica a operação solicitada pela entrada
    int noOperations; // Identifica quantas operações do tipo 'operation' serão realizadas
    bst *database = NULL;
    item movie; // Variável auxiliar para armazenar nomes e chaves

    while(1){
        scanf("%f", &auxOp);
        operation = (int)auxOp; // Esta linha (e todas as outra similares ao longo do código) serve para truncar o valor recebido (seja int ou float) em um int

        switch (operation){ // De acordo com o valor de 'operations':
            case CREATE: // cria uma nova árvore
                // caso já exista uma árvore, printa erro
                if(database != NULL){ printf("%d\n", Error); }
                
                // caso contrário:
                else{
                    database = bst_new(); // cria uma nova

                    printf("%d\n", database != NULL ? 1 : Error); // printa o resultado
                }

                break;

            case DELETE: // Apaga a árvore
                printf("%d\n", bst_delete(&database)); // Apaga a árvore e printa o resultado

                break;

            case INSERT: // Insere 'noOperations' itens na árvore
                scanf("%f", &auxNoOp);
                noOperations = (int)auxNoOp;

                for(int i = 0; i < noOperations; i++){ // Para cada item a ser inserido
                    scanf("%f %s", &auxKey, movie.title); // Recebe as informações
                    movie.key = (int)auxKey;

                    printf("%d\n", bst_insert(database, movie)); // Insere na árvore e printa o resultado
                }

                break;
            
            case REMOVE: // Remove 'noOperations' itens da lsita
                scanf("%f", &auxNoOp);
                noOperations = (int)auxNoOp;

                for(int i = 0; i < noOperations; i++){ // Para cada item a ser removido
                    scanf("%f", &auxKey); // Recebe a chave
                    movie.key = (int)auxKey;

                    printf("%d\n", bst_remove(database, movie.key)); // Remove da árvore e printa o resultado
                }

                break;

            case SEARCH: // Busca o título de 'noOperations' itens na árvore
                scanf("%f", &auxNoOp);
                noOperations = (int)auxNoOp;

                for(int i = 0; i < noOperations; i++){ // Para cada item a ser buscado
                    scanf("%f", &auxKey); // Recebe a chave 
                    movie.key = (int)auxKey;

                    printf("%s\n", bst_search(database, movie.key)); // Printa seu título
                }

                break;

            case PRINT: // Imprime toda a árvore
                bst_print(database);

                break;

            case GET_HEIGHT: // Imprime a altura da árvore
                printf("%d\n", bst_getHeight(database));

                break;

            case EXIT: // Encerra a execução do programa
                bst_delete(&database); // Apaga a árvore

                return 0; // Encerra o programa
        }

    }
}
