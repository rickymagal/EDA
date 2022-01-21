#include <stdio.h>
#include <stdlib.h>

typedef struct arvbinbusca{
    int info;
    struct arvbinbusca *esq, *dir;
}TABB;

TABB* cria(int x, TABB* e, TABB* d);
void imprime(TABB *t);
void libera(TABB* t);
TABB* busca(int e, TABB* t);
TABB* insere(int e, TABB* t);
TABB* retira(int e, TABB *t);
TABB* maior(TABB *a);
TABB* menor(TABB *a);
TABB* retira_impares(TABB* a);
int* mN(TABB*a, int N);
void Insere_vect_elemento(int * vet, int elemento, int i);
void Insere_vect_vect(int * vet, int * vect, int i);
void vetorizar(TABB * a, int * vet);

