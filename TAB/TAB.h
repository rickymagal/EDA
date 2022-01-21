#include <stdio.h>
#include <stdlib.h>

typedef struct arvbin{
  int info;
  struct arvbin *esq, *dir;
}TAB;

TAB *TAB_inicializa(void);
TAB *TAB_cria(int raiz, TAB *esq, TAB *dir);
TAB* retira_pares (TAB* arv);
TAB* copia(TAB *a);
TAB* espelho (TAB *a);
void colore (TAB* arv);
int ni(TAB *a);
int nf(TAB *a);

void TAB_imp_pre(TAB *a);
void TAB_imp_pos(TAB *a);
void TAB_imp_sim(TAB *a);
void TAB_imp_ident(TAB *a);

TAB *TAB_busca(TAB *a, int elem);
TAB * menor(TAB *a);
int igual (TAB* a1, TAB* a2);

void TAB_libera(TAB *a);
