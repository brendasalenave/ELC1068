#ifndef _BINARIA_H_
#define _BINARIA_H_

#include "list.h"

typedef struct arv{
    char chave[50];
    struct arv* esq;
    struct arv* dir;
}Arv_bin;

Arv_bin* criaBinaria(Arv_bin* bin);
Arv_bin* insere_bin(Arv_bin* bin, char *str);
Arv_bin* buscaArvoreBin(Arv_bin* a, char *str);
int bin_vazia(Arv_bin* bin);
void imprimeBin_emOrdem(Arv_bin* bin);
Arv_bin* remove_bin(Arv_bin* a, char* str);
void tempoBuscaBin(Arv_bin* bin, char* chave);
void insere_bin1(Lista* l, Arv_bin* bin)
void liberaArvoreBinaria(Arv_bin* bin);

#endif
