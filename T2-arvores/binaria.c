#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "binaria.h"
//#include "list.h"

Arv_bin* criaBinaria(Arv_bin* bin){
    return NULL;
}

int bin_vazia(Arv_bin* bin){
    return bin == NULL;
}

Arv_bin* insere_bin(Arv_bin* bin, char *str){
    if (bin_vazia(bin)){
        Arv_bin* bin = (Arv_bin*)malloc(sizeof(Arv_bin));
        bin->dir = criaBinaria(bin->dir);
        bin->esq = criaBinaria(bin->esq);
        strcpy(bin->chave,str);
        return bin;
    }else if (strcmp(str,bin->chave) < 0){   // insere a esquerda
        bin->esq = insere_bin(bin->esq, str);
    }else if (strcmp(str,bin->chave) >= 0){   // insere a direita
        bin->dir = insere_bin(bin->dir, str);
    }
    return bin;
}

Arv_bin* buscaArvoreBin(Arv_bin* a, char *str){
    int cmp;
    if(a == NULL) return NULL;
    cmp = strcmp(str, a->chave);
    if (cmp < 0) return buscaArvoreBin(a->esq, str);
    else if (cmp > 0) return buscaArvoreBin(a->dir, str);
    else return a;
}

void imprimeBin_emOrdem(Arv_bin* bin){
    if(!bin_vazia(bin)){
        imprimeBin_emOrdem(bin->esq);
        printf("%s\n", bin->chave);
        imprimeBin_emOrdem(bin->dir);
    }
}

Arv_bin* remove_bin(Arv_bin* a, char* chave){
    if(bin_vazia(a)) return NULL;
    else if (strcmp(chave ,a->chave) < 0) a->esq = remove_bin(a->esq, chave);
    else if (strcmp(chave ,a->chave) > 0) a->dir = remove_bin(a->dir, chave);
    else{ /* elemento encontrado */
        if(a->esq == NULL && a->dir == NULL){ /* Nó sem filhos */
            free(a);
            a = NULL;

        }else if(a->esq == NULL){ /* Filho a direta */
            Arv_bin* aux = a;
            a = a->dir;
            free(aux);

        }else if(a->dir == NULL){ /* Filho a direita */
            Arv_bin* aux = a;
            a = a->esq;
            free(aux);

        }else{
            Arv_bin* pai = a;
            Arv_bin* f = a->esq;
            while(f->dir != NULL){
                pai = f;
                f = f->dir;
            }
            strcpy(a->chave,f->chave);
            strcpy(f->chave,chave);
            a->esq = remove_bin(a->esq,chave);
        }
    }
    return a;
}

void insere_bin1(Lista* l, Arv_bin* bin){
    Lista* p = lista;
    if(p == NULL)
        printf("Lista vazia");
    while(p != NULL){
        bin = insere_bin(bin p->str);
        p = p->prox;
    }
}

void tempoBuscaBin(Arv_bin* bin, char* chave){
    int i;
    clock_t tempoInicial, tempoFinal;
    double tempoGasto;
    tempoInicial = clock();
    for(i=0;i<100000000;i++){
        bin = buscaArvoreBin(bin, chave);
    }
    tempoFinal = clock();

    tempoGasto = ((tempoFinal-tempoInicial)/CLOCKS_PER_SEC);
    printf("Tempo de busca: %f s", tempoGasto);

}


void liberaArvoreBinaria(Arv_bin* bin){
   if(!bin_vazia(bin)){
        liberaArvoreBinaria(bin->esq);
        liberaArvoreBinaria(bin->dir);
        free(bin);
    }
    return;
}
