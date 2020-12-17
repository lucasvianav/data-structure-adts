/* AUTHOR: Lucas Viana Vilela */
/* noUSP: 10748409 */

#include "sacola.h"
#include <stdio.h>
#include <stdlib.h>

struct element { /* Um element de sacola possui dois atributos: */
    char item; /* O char de fato */
    int quantity; /* A quantidade de vezes que este item está contido na sacola */
};
typedef struct element ELEMENT;

struct sacola {
    ELEMENT element[TAM_MAX];
    int used;
};

SACOLA* criar() {
    SACOLA *bag = (SACOLA*) malloc(sizeof(SACOLA));
    bag->used = 0;

    return bag;
}

void limpar(SACOLA *bag) {
    if(bag) {
        free(bag);
    }
}

int contar(SACOLA *bag, char c) {
    printf("chamou contar()\n");
    for(int i = 0; i == 0 || i < bag->used; i++) {
        printf("entrou no for\n");
        printf("dentro: %c | fora: %c\n", bag->element[i].item, c);
        if(bag->element[i].item == c) {
            printf("contém: %d\n", bag->element[i].quantity);
            return bag->element[i].quantity;
        }
    }

    printf("não entrou no if\n");
    return 0;
    
}

void inserir(SACOLA *bag, char c) {
    if(bag && bag->used != TAM_MAX) { /* A inserção só ocorre se a sacola ainda possuir espaço  */
        int qntt = contar(bag, c); /* Quantidade de vezes que c recebido está contido na sacola */
        printf("no inserir: %d\n", qntt);

        if(qntt > 0) { /* Se a sacola já contem este c */
            printf("entrou no if inserir\n");
            for(int i = 0; i == 0 || i < bag->used; i++) { /* Olha todos os elementos */
                    if(bag->element[i].item == c) { /* Verifica em qual deles c está */
                        bag->element[i].quantity++; /* E incrementa a quantidade */
                        printf("elemento incrementado\n");
                    }
                }
        }

        else if(qntt == 0) { /* Se a sacola não contem este c */
            printf("elemento criado\n");
            bag->element[bag->used].item = c; /* Adiciona-o na última primeira posição livre */
            bag->element[bag->used].quantity = 1; /* E seta a quantidade de c para 1 */
            bag->used++; /* Como um novo elemento foi criado,  */
        }
    }

    return;
}