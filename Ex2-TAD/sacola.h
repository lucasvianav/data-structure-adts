/* 
 * File:   sacola.h
 * Author: Eliane Gniech Karasawa
 */

#ifndef SACOLA_H
#define SACOLA_H

#define TAM_MAX 10 /*Estimativa de tamanho máximo da sacola*/

typedef struct sacola SACOLA;

SACOLA *criar(); /*Função que cria um elemento do tipo sacola e retorna seu ponteiro*/
void limpar(SACOLA *sac); /*Função que limpa o elemento sacola e desaloca seu ponteiro*/
int contar(SACOLA *sac, char elem); /*Função que recebe uma sacola e um char e retorna o numero de vezes que o char esta na sacola*/

void inserir(SACOLA *sac, char elem); /*Função que recebe uma sacola e um char e insere esse char na sacola*/

#endif /* SACOLA_H */