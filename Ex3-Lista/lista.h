/* 
 * File:   lista.h
 * Author: Eliane Gniech Karasawa
 */

#ifndef LISTA_H
#define LISTA_H

#define boolean int /*Define tipo booleano*/
#define TRUE 1
#define FALSE 0
#define ERRO -32000

typedef struct item ITEM; /*Tipo ITEM da lista*/

struct item {
    int chave;
    char titulo[20];
};

typedef struct lista LISTA;

LISTA *lista_criar(void); /*Criacao da lista e retorno do seu ponteiro*/
boolean lista_apagar(LISTA **l); /*Apaga todo o conteudo da lista e libera o bloco de memoria*/
void lista_imprimir(LISTA *l); /*Imprime os elementos armazenados na lista*/
boolean lista_cheia(LISTA *l); /*Retorna TRUE se nao for possivel alocar mais nos*/
boolean lista_vazia(LISTA *l); /*Retorna TRUE se a lista estiver vazia*/

boolean lista_inserir_pos(LISTA *l, ITEM filme, int pos); /*Insere o ITEM na posicao desejada*/
boolean lista_remover(LISTA *l, int chave); /*Remove a chave desejada - se nao existir, retorna FALSE*/
int lista_buscar(LISTA *l, int chave); /*Busca a chave na lista e se nao existir, retorna ERRO*/
int lista_tamanho(LISTA *l); /*Retorna o tamanho da lista*/

#endif /* LISTA_H */