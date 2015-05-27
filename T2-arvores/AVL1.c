/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "AVL.h"

Arv_avl* criaAVL(Arv_avl* avl){
    return NULL;
}

Arv_avl* insere_avl(Arv_avl *a, char* str){
    if (a==NULL) {
        a = (Arv_avl*) malloc(sizeof(Arv_avl));
        strcpy(a->info,str);
        a -> sae = criaAVL(a->sae);
        a -> sad = criaAVL(a->sad);
        return a;
    }
    int cmp = strcmp(str, a->info);

    if (cmp < 0) {         // insere a esquerda
        a->sae = insere_avl(a->sae, str);
        a = balanceamento(a);
    }
    else if (cmp>0) {         // insere a direita
        a->sad = insere_avl(a->sad, str);
        a = balanceamento(a);
    }
    return a;
}

int altura(Arv_avl* a) {
   if (a == NULL)
      return -1; // altura de árvore vazia é -1
   else {
      int he = altura( a->sae);
      int hd = altura( a->sad);
      if (he < hd) return hd + 1;
      else return he + 1;
   }
}

int fator_balanceamento(Arv_avl *a){
    int he =altura(a -> sae); // altura da sub-arvore a esquerda
    int hd =altura(a -> sad); // altura da sub-arvore a direita
    int fb = he - hd;
    return fb;
}

Arv_avl* r_simplesDir(Arv_avl* pivo){
    Arv_avl* aux;
    aux = pivo ->sad;
    pivo->sad = aux -> sae;
    aux ->sae = pivo;
    return aux;
}

Arv_avl* r_simplesEsq(Arv_avl *pivo){
    Arv_avl *aux;
    aux = pivo -> sae;
    pivo -> sae = aux -> sad;
    aux -> sad = pivo;
    return aux;
}

Arv_avl* r_duplaEsqDir(Arv_avl* pivo){
    Arv_avl* aux;
    aux = pivo->sae;
    pivo-> sae = r_simplesDir(aux);
    return r_simplesEsq(pivo);
}

Arv_avl* r_duplaDirEsq(Arv_avl *pivo){
    Arv_avl *aux;
    aux=pivo -> sad;
    pivo->sad = r_simplesEsq(aux);
    return r_simplesDir(pivo);
}

Arv_avl* balanceamento(Arv_avl *a){
    int fb = fator_balanceamento(a);
    if (fb > 1) {
        if (fator_balanceamento(a->sae) >0)
            a = r_simplesEsq(a);
        else
            a = r_duplaEsqDir(a);
    }
    else if(fb < -1) {
        if(fator_balanceamento(a ->sad) >0)
            a = r_duplaDirEsq(a);
        else
            a = r_simplesDir(a);
    }
    return a;
}

//OK
void liberaArvoreAVL(Arv_avl* avl){
   if(!avl_vazia(avl)){
        liberaArvoreAVL(avl->sae);
        liberaArvoreAVL(avl->sad);
        free(avl);
    }
    return;
}

int avl_vazia(Arv_avl* avl){
    return avl == NULL;
}

Arv_avl* buscaArvoreAVL(Arv_avl* a, char *str){
    int cmp;
    if(a == NULL) return NULL;
    cmp = strcmp(str, a->info);
    if (cmp < 0) return buscaArvoreAVL(a->sae, str);
    else if (cmp > 0) return buscaArvoreAVL(a->sad, str);
    else return a;
}

void imprimeAVL_emOrdem(Arv_avl* avl){
    if(!avl_vazia(avl)){
        imprimeAVL_emOrdem(avl->sae);
        printf("%s\n", avl->info);
        imprimeAVL_emOrdem(avl->sad);
    }
}

/*
Arv_avl* remove_ArvAVL(Arv_avl *raiz, int valor){
	if(avl_vazia(a)){// valor não existe
	    return NULL;
	}

    int res;
	if(valor < raiz->info){
	    if((res = remove_ArvAVL(&(*raiz)->esq,valor)) == 1){
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(altura_NO((*raiz)->dir->esq) <= altura_NO((*raiz)->dir->dir))
                    RotacaoRR(raiz);
                else
                    RotacaoRL(raiz);
            }
	    }
	}

	if((*raiz)->info < valor){
	    if((res = remove_ArvAVL(&(*raiz)->dir, valor)) == 1){
            if(fator_balanceamento(raiz) >= 2){
                if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq) )
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
            }
	    }
	}

	if((*raiz)->info == valor){
	    if((raiz->sae == NULL || raiz->sad == NULL)){// nó tem 1 filho ou nenhum
			struct NO *oldNode = (*raiz);
			if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
			free(oldNode);
		}else { // nó tem 2 filhos
			struct NO* temp = procuraMenor((*raiz)->dir);
			(*raiz)->info = temp->info;
			remove_ArvAVL(&(*raiz)->dir, (*raiz)->info);
            if(fatorBalanceamento_NO(*raiz) >= 2){
				if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq))
					RotacaoLL(raiz);
				else
					RotacaoLR(raiz);
			}
		}
		return 1;
	}
	return res;
}
*/
