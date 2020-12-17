/* 
 * File:   Fila.h
 * Author: Eliane Gniech Karasawa
 */

#ifndef FILA_H
#define FILA_H

#define TRUE 1
#define FALSE 0
#define ERRO -32000

typedef struct fila FILA;
typedef int boolean;

/*
 * Cria uma fila vazia de inteiros.
 * @retorno ponteiro para a fila
 */
FILA *criar(); 
/*
 * Apaga a fila se ela existir, desalocando todos os seus nos
 * Se a fila nao existir, nao faz nada
 * @parametro f Endereço do ponteiro que aponta para a fila
 * @retorno void
 */
void apagar(FILA **f);
/*
 * Verifica se a fila esta vazia
 * @parametro f Ponteiro para a fila
 * @retorno TRUE se o tamanho for 0 e nao existir nenhum no alocado
 *          FALSE caso contrário
 *          ERRO se a fila nao existir
 */
boolean fila_vazia(FILA *f);
/*
 * Verifica se a fila esta cheia
 * @parametro f Ponteiro para a fila
 * @retorno TRUE se ainda consegue criar um no
 *          FALSE caso contrario
 *          ERRO se a fila nao existir
 */
boolean fila_cheia(FILA *f);
/*
 * Informa o número de elementos na fila
 * @parametro f Ponteiro para a fila
 * @retorno inteiro que representa o numero de nos na fila
 *          ERRO se a fila nao existir (ponteiro para nulo)
 */
int tamanho(FILA *f);
/*
 * Insere o elemento na fila
 * Se a fila nao existir, nao faz nada
 * @parametro f Ponteiro para a fila
 * @parametro num Inteiro que eh o elemento a ser inserido na fila
 * @retorno void
 */
void inserir(FILA *f, int num);
/*
 * Remove um elemento da fila
 * Se a fila nao existir, nao faz nada
 * @parametro f Ponteiro para a fila
 * @retorno void
 */
void remover(FILA *f);
/*
 * Informa o elemento na frente da fila
 * @parametro f Ponteiro para a fila
 * @retorno inteiro (copia) que eh o primeiro elemento
 *          ERRO caso a fila esteja vazia
 */
int frente(FILA *f);

#endif /* FILA_H */

