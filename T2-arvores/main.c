#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "binaria.h"
#include "AVL.h"
#include "list.h"


int main(){
    char* p;
    p = (char*)malloc(50*sizeof(char));

    Arv_bin* bin = NULL;
    Avl* avl = NULL;
    Lista* lista = NULL;;

    FILE *arq;

    arq = fopen("exemplo2.txt", "r");
    if (arq == NULL){
        printf ("Falha no arquivo.\n");
        exit(1);
    }else{
        while((fscanf(arq, "%s",p))!= EOF){
            lista = insereLista(lista,p);
            //bin = insere_bin(bin, p);
            //avl = insere_avl(avl, p);
        }
    }

    insere_bin1(lista, bin);
    imprimeBin_emOrdem(bin);
    bin = buscaArvoreBin(bin, "venenatis");
    if(bin != NULL)
        printf("\n\nencontrado!\n\n");

    tempoBuscaBin(bin,"venenatis");
    printf("\n\n");
    tempoBuscaAvl(avl,"venenatis");

    #if 0
    avl = remove_avl(avl, "venenatis");
    avl = remove_avl(avl, "saggits");
    imprimeAvl_emOrdem(avl);
    #endif

    free(p);
    liberaArvoreBinaria(bin);
    liberaArvoreAVL(avl);

    return 0;
}
