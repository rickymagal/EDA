#include "TABB.h"

void libera(TABB* t){
  if(t){
  libera(t->esq);
  libera(t->dir);
  free(t);
  }
}

TABB* busca(int e, TABB* t){
  if(!t) return NULL;
  if(e < t->info) return busca(e, t->esq);
  if(e > t->info) return busca(e, t->dir);
  return t;
}

void imprime_aux(TABB* a, int andar){
  if(a){
    int j;
    imprime_aux(a->esq, andar + 1);
    for(j = 0; j <= andar; j++) printf("   ");
    printf("%d\n", a->info);
    imprime_aux(a->dir, andar + 1);
  }
}

void imprime(TABB* a){
  imprime_aux(a, 1);
}

TABB* cria(int x, TABB* e, TABB* d){
  TABB* a = (TABB*) malloc(sizeof(TABB));
  a->info = x;
  a->esq = e;
  a->dir = d;
  return a;
}

TABB* insere(int e, TABB* t){
  if(!t) t = cria(e, NULL, NULL);
  else if(e < t->info) t->esq = insere(e, t->esq);
  else if(e > t->info) t->dir = insere(e, t->dir);
  return t;
}

TABB* retira(int e, TABB *t){
  if(!t) return t;
  else if(e < t->info) t->esq = retira(e, t->esq);
  else if(e > t->info) t->dir = retira(e, t->dir);
  else{
    if((!t->esq) && (!t->dir)){
      free(t);
      t = NULL;
    }
    else if((!t->esq) || (!t->dir)){
      TABB *q = t;
      if(!t->dir) t = t->esq;
      else t = t->dir;
      free(q); 
    }
    else{
      TABB *f = t->esq;
      while(f->dir) f = f->dir;
      t->info = f->info;
      f->info = e;
      t->esq = retira(e, t->esq);
    }
  }
  return t;  
}

TABB* maior(TABB *a){
	TABB* atual = a;
	while(atual->dir!=NULL){
		atual = atual->dir;
	}return atual;
}

TABB* menor(TABB *a){
	TABB* atual = a;
	while(atual->esq!=NULL){
		atual = atual->esq;
	}return atual;
}
TABB* retira_impares(TABB* a){
	if(a!=NULL){
		a->esq = retira_impares(a->esq);
		a->dir = retira_impares(a->dir);
		if(a->info%2!=0){
			a=retira(a->info, a);
		}
	}return a;
}



int* mN(TABB*a, int N){
	int * vet = (int*) malloc(sizeof(int));
	TABB * atual = a;
	int i = 1;
	while(atual){
	}
	}return(vet);
}