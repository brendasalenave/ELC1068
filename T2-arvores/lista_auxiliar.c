#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

/*Lista* inicializa(){
    return NULL;
}*/

Lista* insereLista(Lista *l, char* str){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    strcpy(novo->str , str);
    novo->prox = l;
    return novo;
}

int lista_vazia(Lista* l){
    return (l==NULL);
}

void imprimeLista(Lista* lista){
    Lista* p = lista;

    if(p == NULL)
        printf("lista vazia");

    while(p != NULL){
        printf("%s\n", p->str);
        p = p->prox;
    }
}

void liberaLista(Lista *l){
    if(!lista_vazia(l)){
        liberaLista(l->prox);
        free(l);
    }
}
