// AUTHOR: Lucas Viana Vilela
// no.USP: 10748409

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
    // k, j e i são como descritos no enunciado da atividade
    int k, j, i;

    // x é uma variável auxiliar que será utilizada para acessar
    // cada um dos índices de vector (a seguir) para armazenar
    // valores nele
    int x;

    // vector é um ponteiro que será utilizado para armazenar
    // os valores removidos da fila
    int *vector;

    // queue é a fila que será utilizada
    FILA *queue;

    // loop that will repeat the whole process until
    // the user enters "0 0 0" as input
    while(TRUE){
        // aloca memória para a fila
        queue = criar();
        x = 0;

        // recebe o input
        scanf("%d", &k);
        scanf("%d", &j);
        scanf("%d", &i);

        // caso o input seja "0 0 0", encerra a execução do programa
        if(k == 0 && j == 0 && i == 0){
            apagar(&queue);
            break; 
        }
        // caso seja "0 X Y" ou "X 0 Y", pula todo o resto do
        // código e recebe um novo input
        else if(k == 0 || j == 0){ continue; }

        // insere todos os valores na fila: k, k-1, k-2 ... 1
        for(int w = k; w > 0; w--){ inserir(queue, w); }

        // aloca memória para vector (ele vai armazenar
        // todos os valores na fila, exceto o último)
        vector = (int *)malloc((k-1) * sizeof(int));

        // loop no qual as operações de remoção e reinserção serão feitas
        // até sobrar apenas um elemento na fila (o "último manuseado")
        // vale lembrar que se k == 1, o programa não vai entrar nesse loop
        while(tamanho(queue) > 1){
            // remoções
            for(int w = 0; w < j && tamanho(queue) > 1; w++, x++){ 
                vector[x] = frente(queue); // armazena o valor a ser removido em vector
                remover(queue); // remove
            }

            // reinserções
            for(int w = 0; w < i && tamanho(queue) > 1; w++){
                inserir(queue, frente(queue)); // insere o valor do começo da fila no final
                remover(queue); // remove o valor do começo da fila
            }
        }

        // printa os valores que foram removidos, na ordem
        // (se k == 1, o programa não vai entrar nesse loop)
        for(int w = 0; w < k - 1; w++){
            printf("%d", vector[w]);
            if(w < k - 2){ printf("-"); }
            else{ printf("\n"); }
        }
        // caso especial em que k == 1 (o valor printado sempre será 1)
        if(k == 1){ printf("1\n"); }

        // printa o último valor manueado (o que foi deixado na fila)
        printf("%d\n", frente(queue));

        // desaloca vector e apaga a fila, para serem novamente criados
        // na próxima iteração do loop
        free(vector);
        apagar(&queue);
    }

    return 0;
}