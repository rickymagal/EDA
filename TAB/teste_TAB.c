#include <string.h>
#include "TAB.h"

TAB* retorna_folha(TAB* a){
}

TAB* retira_folha(TAB* a, TAB* x){
}

TAB* ret_mult_k(TAB *a, int k){
  if(!a) return NULL;
  if(((a->info % k) == 0) && (!a->esq) && (!a->dir)){
    free(a);
    return NULL;
  }
  if((a->info % k) == 0){
    TAB *aux = a->esq;
    if(!aux) aux = a->dir;
    TAB* x = retorna_folha(aux);
    a->info = x->info;
    if(a->esq) a->esq = retira_folha(a->esq, x);
    else a->dir = retira_folha(a->dir, x);
    a = ret_mult_k(a, k);
  }
  a->esq = ret_mult_k(a->esq, k);
  a->dir = ret_mult_k(a->dir, k);
  return a;
}

int main(void){
  int no, pai;
  printf("Digite a raiz da arvore... ");
  scanf("%d", &no);
  TAB *a = TAB_cria(no, NULL, NULL), *resp;
  char repete;
  do{
    char lado[2];
    printf("Quer continuar inserindo nos na árvore (digite N ou n para parar)? ");
    scanf(" %c", &repete);
    if((repete == 'N') || (repete == 'n')) break;
    printf("Digite o pai (que deve existir), o filho a ser inserido na arvore e a posição E(ESQ) ou D(DIR)... ");
    scanf("%d%d%s", &pai, &no, lado);
    resp = TAB_busca(a, pai);
    if(!resp){
      TAB_libera(a);
      return 0;
    }
    if(strcmp(lado, "E") == 0) resp->esq = TAB_cria(no, NULL, NULL);
    else resp->dir = TAB_cria(no, NULL, NULL);
  }while(1);
  TAB_imp_ident(a);
  printf("\n");
  printf("%d", nf(a));
  printf("\n");
  int k;
  printf("Digite o valor de k... ");
  scanf("%d", &k);
  if(k > 1){
    a = ret_mult_k(a, k);
    TAB_imp_ident(a);
    printf("\n");
  }
  
  TAB_libera(a);
  while(1){}
  return 0;
}