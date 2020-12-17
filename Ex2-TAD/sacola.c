/* Eliane Gniech Karasawa
 Implementação do TAD Sacola que armazena elementos*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "sacola.h"

/*Contrução do tipo sacola que contém:
elem: vetor de char de TAM_MAX
used: inteiro que armazena o número de char contidos em elem
*/

struct sacola{
    char elem[TAM_MAX];
    int used;
};

/*
Criação da sacola com alocação dinâmica e inicialização do contador used
Retorna o ponteiro da sacola
*/

SACOLA *criar(){
    SACOLA *sac = (SACOLA *)malloc(sizeof(SACOLA));
    sac->used = 0;
    
    return sac;
}

/*
Limpeza do elemento sacola e desalocação seu ponteiro
*/

void limpar(SACOLA *sac){
    if(sac){
        free(sac);
    }
}

/*
Contagem de um dado elemento c na sacola recebida
*/

int contar(SACOLA *sac, char c){
    int cont = 0, i = 0;
    while(i < sac->used){
        if(sac->elem[i] == c){
            cont++;
        }
		i++;
    }
    return cont;
}

/*
Inserção do elemento c na sacola sac recebida
Só insere se ainda possui espaço (verificação através do elemento used)
*/

void inserir(SACOLA *sac, char c){
    if(sac && sac->used != TAM_MAX){
        sac->elem[sac->used] = c;
        sac->used++;
        /*printf("Elemento %c inserido\n", c);*/
        return;
    }
    /*printf("Elemento %c nao foi inserido\n", c);*/
    return;
}