// AUTHOR: LUCAS VIANA VILELA 10748409

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct NODE{
    ITEM movie;
    struct NODE *next;
}; typedef struct NODE node;

struct lista{
    node *start;
};

LISTA* lista_criar(void){
    LISTA *newList = (LISTA *)malloc(sizeof(LISTA));

    if(newList != NULL){
        newList->start = NULL; // Cria uma lista vazia
        return newList;
    }

    else { return NULL; } // Se não conseguir alocar espaço para uma lista

}

boolean lista_vazia(LISTA *l){
    if(l == NULL || l->start != NULL){ return FALSE; }

    else{ return TRUE; }
}

boolean lista_cheia(LISTA *l){
    if(l == NULL || lista_vazia(l)){ return FALSE; } // Se a lista estiver vazia, ela não está cheia;

    else{
        // Como é uma lista com alocação dinâmica, não há um máximo inerente de elmentos, apenas um ditado
        // pela memória disponível. Se não for possível alocar mais memória, significa que a lista estaria cheia.
        node *newNode = (node *)malloc(sizeof(node));

        if(newNode == NULL){ 
            free(newNode);
            return TRUE; 
        }
        else{ 
            free(newNode);
            return FALSE; 
        }
    }
}

int lista_tamanho(LISTA *l){
    if(l == NULL){ return ERRO; } // Se a lista fornecida for nula, retorna erro.

    else if(lista_vazia(l)){ return 0; } // Se a lista estiver vazia, o tamanho é 0.
    
    else{
        node *tmp = l->start; // Variável temporária que começa apontando para o primeiro nó da lista
        int size = 1; // Contagem de nós, que começa em 1 (lista não está vazia)

        while(tmp->next != NULL){ // Varre toda a lista, até não haver um próximo nó
            tmp = tmp->next; // Passa para o próximo nó
            size++; // Incrementa a contagem de nós
        }

        return size; // Retorna o tamanho da lista
    }
}

boolean lista_inserir_pos(LISTA *l, ITEM filme, int pos){
    if(l == NULL || lista_cheia(l) || pos < 1 || pos > lista_tamanho(l)+1){ return FALSE; }
    
    else{
        node *newNode = (node *)malloc(sizeof(node));

        newNode->movie = filme;

        if(lista_vazia(l) || pos == 1){ // Caso a lista esteja vazia ou a posição desejada seja a primeira
            // Insere o novo nó no início da lista
            newNode->next = l->start;
            l->start = newNode;
        }

        else{
            node *tmp = l->start; // Variável temporária que começa apontando para o primeiro nó da lista

            // Varre a lista até encontrar o nó na posição pos-1
            for(int i = 1; i < pos-1; i++){ tmp = tmp->next; }

            // Insere o nó entre os das posições pos-1 e pos, passando a ser o nó em pos
            newNode->next = tmp->next;
            tmp->next = newNode;
        }

        return TRUE;
    }

}

int lista_buscar(LISTA *l, int chave){
    if(l == NULL){ return ERRO; }

    else if(lista_vazia(l)){ return ERRO; } // Se a lista estiver vazia, é impossível conter qualquer chave.

    else{ // Se a lista não estiver vazia:
        node *tmp = l->start; // Variável temporária que começa apontando para o primeiro nó da lista
        int position = 1; // Posição do elemento atual apontado por tmp

        while(tmp->movie.chave != chave && tmp->next != NULL){ // Varre a lista até encontrar a chave ou chegar no fim
            tmp = tmp->next; // Passa para o próximo elemento
            position++; // Incrementa a posição

        }
        // Se encontrar a chave, retorna a posição dela
        if(tmp->movie.chave == chave){ return position; }
        
        // Se chegar no fim sem encontrar a chave, retorna erro
        else{ return ERRO; } 
    }
}

boolean lista_remover(LISTA *l, int chave){
    int position = lista_buscar(l, chave); // Posição do filme com a chave desejada
    if(position == ERRO){ return FALSE; } // Se a função buscar retornar erro, a chave não está contida na lista

    else{
        node *target = NULL; // Variável temporária que vai apontar para o nó que contem a chave desejada

        if(position == 1){
            target = l->start; // Faz target apontar para o primeiro nó
            l->start = target->next; // Transforma o segundo nó no primeiro
        }

        else{
            node *tmp = l->start; // Variável temporária que começa apontando para o primeiro nó da lista

            for(int i = 1; i < position-1; i++){ tmp = tmp->next; } // Percorre a lista até o anterior ao nó em questão
            target = tmp->next; // Faz target apontar para o nó em questão

            tmp->next = target->next; // Faz o nó em position-1 apontar para o nó em position+1
        }

        free(target); // Desaloca o nó em questão

        return TRUE;
    }

}

void deallocate(node **n){ // Função local para recursivamente desalocar os nós de uma lista
    // Se este n não for o último nó da lista, chama a si mesma recursivamente no próximo nó
    if(*n != NULL && (*n)->next != NULL){ deallocate(&((*n)->next)); }

    // Indo do fim da lista até o início
    free(*n); // Desaloca a memória do nó
    *n = NULL; // Faz o ponteiro daquele nó apontar para NULL

    return;
}

boolean lista_apagar(LISTA **l){
    if(*l == NULL){ return FALSE; }

    else{ 
        deallocate(&((*l)->start)); // Desaloca todos os nós da lista

        free(*l); // Desaloca a lista
        *l = NULL; // Faz o ponteiro da lista apontar para NULL

        return TRUE;
    }
}

void lista_imprimir(LISTA *l){
    if(l != NULL){
        node *tmp = l->start; // Variável temporária que começa apontando para o possível primeiro nó

        while(tmp != NULL){ // Caso o nó atual apontado por tmp exista
            printf("%d %s\n", tmp->movie.chave, tmp->movie.titulo); // Printa a chave e o nome do filme
            tmp = tmp->next; // E passa para o próximo nó
        }
    }

    return;
}