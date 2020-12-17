/* 
 * File:   main.c
 * Author: Eliane Gniech Karasawa
 */

#include <stdio.h>
#include <stdlib.h>
#include "sacola.h"


int main(int argc, char** argv){
	/*
	n_sac: número de sacolas
	n_op: número de operações
	n_ins: número total de inserções
	id: identificador da sacola (sacola 0, sacola 1, etc)
	n_vzs: número de inserções na sacola
	i: contador auxiliar
	*/
    int n_sac, n_op, n_ins, id, n_vzs, i = 0;
	
	/*
	elem: char a ser inserido ou buscado na sacola
	*/
    char elem;
    
    scanf(" %d %d %d", &n_sac, &n_op, &n_ins);
    
	/*Alocação dinâmica do vetor de sacolas*/
    SACOLA **sac = (SACOLA **)malloc(n_sac*sizeof(SACOLA *));
        
    for(int i = 0; i < n_sac; i++){ /*Criação das sacolas*/
        sac[i] = criar();
    }
    
    i = 0;    
    while(i < n_ins){ /*Inserção de elem*/
        scanf(" %d %d", &id, &n_vzs);
        for(int j = 0; j < n_vzs; j++){
            scanf(" %c", &elem);
            inserir(sac[id], elem); /*Inserção de elem na sacola id*/
            i++;
        }
    }
    
    for(i = 0; i < n_op; i++){ /*Contagem de elem*/
        scanf("%d %c", &id, &elem);
        if(id > -1 && id < n_sac){
            printf("%d \n", contar(sac[id], elem)); /*Se a sacola id existe, retorna o numero de elem contidos nela*/
        }
        else{
            printf("-1 \n"); /*Se a sacola não existe, retorna -1*/
        }
    }
    
    for(int i = 0; i < n_sac; i++){ /*Limpeza e desalocação das sacolas*/
        limpar(sac[i]);
    }
    
    free(sac); /*Desalocação do vetor de sacolas*/

    return 0;
}