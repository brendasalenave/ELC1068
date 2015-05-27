typedef struct avl{
   struct avl* esq;
   struct avl* dir;
   char* chave[50];
   int altura;
}Avl;

Avl* cria_no(char* chave);
Avl* insere_avl(Avl* a, char* chave);
void imprimeAvl_emOrdem(Avl* a);
//void imprimir(Avl* a);
Avl* remove_avl(Avl* a, char* chave);
Avl* buscar(Avl* raiz, char* chave);
Avl* rotacaoDireita(Avl* raiz);
Avl* rotacaoEsquerda(Avl* raiz);
Avl* rotacaoEsquerdaDireita(Avl* raiz);
Avl* rotacaoDireitaEsquerda(Avl* raiz);
int fator_balanceamento(Avl* a);
Avl* balancear(Avl* a);
void ajustarAltura(Avl* a);
void tempoBuscaAvl(Avl* avl, char* chave);
void insere_avl1(Lista* l, Avl* avl);
void liberaArvoreAVL(Avl* avl);

