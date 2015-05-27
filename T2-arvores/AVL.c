#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "AVL.h"


Avl* cria_no(char* chave){
   Avl* a = (Avl*) malloc(sizeof(Avl));
   a->esq = NULL;
   a->dir = NULL;
   strcpy(a->chave, chave);
   a->altura = 0; // Modifica a altura para zero no primeiro no criado
   return a;
}

bool vazia(Avl* a){
   return (a == NULL);
}

int max(int a, int b){
  if (a > b)
    return a;
  return b;
}

void imprimeAvl_emOrdem(Avl* a){
    if(!vazia(a)){
        imprimeAvl_emOrdem(a->esq);
        printf("%s\n", a->chave);
        imprimeAvl_emOrdem(a->dir);
    }
}

Avl* insere_avl(Avl* a, char* chave){
   if (a == NULL)
      a = cria_no(chave);
   else if (strcmp(chave, a->chave) < 0)
      a->esq = insere_avl(a->esq, chave);
   else
      a->dir = insere_avl(a->dir, chave);
   a = balancear(a); // balanceamento pos-insercao
   return a;
}

Avl* remove_avl(Avl* a, char* chave){
    if (vazia(a))
       return NULL;
    else if (strcmp(chave, a->chave) < 0)
       a->esq = remove_avl(a->esq, chave);
    else if (strcmp(chave, a->chave) > 0)
       a->dir = remove_avl(a->dir, chave);
    else{
         // Caso 1: No sem filhos
         if ((a->esq == NULL) && (a->dir == NULL)){
            free(a);
            a = NULL;
         } else
         if (a->esq == NULL){ // Caso 2: Somente um filho (o da direita)
            Avl* t = a;
            a = a->dir;
            free(t);
         } else
         if (a->dir == NULL){ // Caso 2: Somente um filho (o da esquerda)
            Avl* t = a;
            a = a->esq;
            free(t);
         } else { // Caso 3: Os dois nós
            Avl* f = a->esq; // vai para a SAE
            while (f->dir != NULL)
               f = f->dir;
            strcpy(a->chave, f->chave);
            strcpy(f->chave, chave);
            a->esq = remove_avl(a->esq, chave);
         }
    }
    a = balancear(a);
    return a;
}

Avl* buscar(Avl* raiz, char* chave){
   if (raiz == NULL)
       return NULL;
   else if (strcmp(chave, raiz->chave) < 0)
       return buscar(raiz->esq, chave);
   else if (strcmp(chave, raiz->chave) > 0)
       return buscar(raiz->dir, chave);
   else return raiz;
}

// Funcoes novas para lidar com arvores AVL

int altura(Avl* a){
   if (vazia(a))
      return -1;
   else
      return a->altura;
}

void ajustarAltura(Avl* a){
   if (!(vazia(a)))
      a->altura = 1 + max(altura(a->esq), altura(a->dir));
}

int fator_balanceamento(Avl* a){
   if (vazia(a))
      return 0;
   return (altura(a->esq) - altura(a->dir));
}

Avl* rotacaoDireita(Avl* raiz){
   Avl* q = raiz->esq;
   Avl* hold = q->dir;
   q->dir = raiz;
   raiz->esq = hold;
   ajustarAltura(raiz->esq);
   ajustarAltura(raiz);
   return q;
}

Avl* rotacaoEsquerda(Avl* raiz){
   Avl* q = raiz->dir;
   Avl* hold = q->esq;
   q->esq = raiz;
   raiz->dir = hold;
   ajustarAltura(raiz->dir);
   ajustarAltura(raiz);
   return q;
}

Avl* rotacaoEsquerdaDireita(Avl* raiz){
   raiz->esq = rotacaoEsquerda(raiz->esq);
   raiz = rotacaoDireita(raiz);
   return raiz;
}

Avl* rotacaoDireitaEsquerda(Avl* raiz){
   raiz->dir = rotacaoDireita(raiz->dir);
   raiz = rotacaoEsquerda(raiz);
   return raiz;
}

bool caso1(Avl* a){ // Desbalanceada a Esquerda / Esquerda
   return (fator_balanceamento(a) > 1) && (fator_balanceamento(a->esq) > 0);
}

bool caso2(Avl* a){ // Desbalanceada a Esquerda / Direita
   return (fator_balanceamento(a) > 1) && !(fator_balanceamento(a->esq) > 0);
}

bool caso3(Avl* a){ // Desbalanceada a Esquerda / Direita
   return (fator_balanceamento(a) < -1) && !(fator_balanceamento(a->dir) < 0);
}

bool caso4(Avl* a){ // Desbalanceada a Esquerda / Direita
   return (fator_balanceamento(a) < -1) && (fator_balanceamento(a->dir) < 0);
}

Avl* balancear(Avl* a){ // Balanceamento da arvore
   ajustarAltura(a);
   if (caso1(a))
      a = rotacaoDireita(a);
   else
   if (caso2(a))
      a = rotacaoEsquerdaDireita(a);
   else
   if (caso3(a))
      a = rotacaoDireitaEsquerda(a);
   else
   if (caso4(a))
      a = rotacaoEsquerda(a);
   return a;
}

void tempoBuscaAvl(Avl* avl, char* chave){
    int i;
    clock_t tempoInicial, tempoFinal;
    double tempoGasto;
    tempoInicial = clock();
    for(i=0;i<100000000;i++){
        avl = buscaArvoreBin(avl, chave);
    }
    tempoFinal = clock();

    tempoGasto = ((tempoFinal-tempoInicial)/CLOCKS_PER_SEC);
    printf("Tempo de busca avl: %f s", tempoGasto);

}

void insere_avl1(Lista* l, Avl* avl){
    Lista* p = lista;
    if(p == NULL)
        printf("Lista vazia");
    while(p != NULL){
        avl = insere_avl(avl, p->str);
        p = p->prox;
    }
}

void liberaArvoreAVL(Avl* avl){
   if(!vazia(avl)){
        liberaArvoreAVL(avl->esq);
        liberaArvoreAVL(avl->dir);
        free(avl);
    }
    return;
}
