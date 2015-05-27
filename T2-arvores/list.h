#ifndef _LIST_H_
#define _LIST_H_

typedef struct lista{
    char str[50];
    struct lista *prox;
}Lista;

int lista_vazia(Lista* l);
Lista* insereLista(Lista *l, char* str);
void imprimeLista(Lista* lista);
void liberaLista(Lista *l);

#endif // _LIST_H_
