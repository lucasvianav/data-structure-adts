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
    ELEMENT element[TAM_MAX]; /* Conjunto (vetor) de elementos da sacola */
    int size; /* Tamanho da sacola: número de elementos já armazenados nela */
};

SACOLA* criar() {
    SACOLA *bag = (SACOLA*) malloc(sizeof(SACOLA));
    bag->size = 0;

    return bag;
}

void limpar(SACOLA *bag) {
    if(bag) {
        free(bag);
    }
}

int contar(SACOLA *bag, char item) {
    for(int i = 0; i == 0 || i < bag->size; i++) {
        if(bag->element[i].item == item) {
            return bag->element[i].quantity;
        }
    }

    return 0;
    
}

void inserir(SACOLA *bag, char item) {
    if(bag) { /* A inserção só ocorre se a sacola não for nula  */
        int quantity = contar(bag, item); /* Quantidade de vezes que o item recebido está contido na sacola */

        if(quantity > 0) { /* Se a sacola já contem este item, não é necessário criarum novo elemento */
            for(int i = 0; i == 0 || i < bag->size; i++) { /* Olha todos os elementos */
                    if(bag->element[i].item == item) { /* Verifica em qual deles o item está */
                        bag->element[i].quantity++; /* E incrementa a quantidade */
                    }
                }
        }

        else if(quantity == 0 && bag->size < TAM_MAX) { /* Se a sacola não contem este item e ainda possui espaço */
            bag->element[bag->size].item = item; /* Adiciona-o na última primeira posição livre */
            bag->element[bag->size].quantity = 1; /* E seta a quantidade do item para 1 */
            bag->size++; /* Como um novo elemento foi criado, incrementa-se a quantidade de elementos */
        }
    }

    return;
}