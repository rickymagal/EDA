#include "TAB.h"

TAB *TAB_inicializa(void){
  return NULL;
}

TAB *TAB_cria(int raiz, TAB *esq, TAB *dir){
  TAB *novo = (TAB *) malloc(sizeof(TAB));
  novo->info = raiz;
  novo->esq = esq;
  novo->dir = dir;
  return novo;
}

TAB* retira_pares (TAB* arv){
	if(arv == NULL)
        return NULL;
	TAB * novoNo;
	if(arv->info%2!=0){ 
		novoNo = TAB_cria(arv->info,NULL,NULL);
	}
	else{
		novoNo = TAB_cria(0,NULL,NULL);
	}
	novoNo->esq = copia(arv->esq);
	novoNo->dir = copia(arv->dir);
	return novoNo;
}

TAB* copia(TAB *a){
	if(a == NULL)
        return NULL;
    TAB* novoNo = TAB_cria(a->info,NULL,NULL);
    novoNo->esq = copia(a->esq);
    novoNo->dir = copia(a->dir);
    return novoNo;
}

TAB* espelho (TAB *a){
	if(a == NULL)
        return NULL;
    TAB* novoNo = TAB_cria(a->info,NULL,NULL);
    novoNo->esq = copia(a->dir);
    novoNo->dir = copia(a->esq);
    return novoNo;
}

TAB *TAB_busca(TAB *a, int elem){
  if((!a) || (a->info == elem)) return a;
  TAB *resp = TAB_busca(a->esq, elem);
  if(resp) return resp;
  return TAB_busca(a->dir, elem);
}

void TAB_imp_pre(TAB *a){
  if(a){
    printf("%d ", a->info);
    TAB_imp_pre(a->esq);
    TAB_imp_pre(a->dir);
  }
}

void TAB_imp_pos(TAB *a){
  if(a){
    TAB_imp_pos(a->esq);
    TAB_imp_pos(a->dir);
    printf("%d ", a->info);
  }
}

void TAB_imp_sim(TAB *a){
  if(a){
    TAB_imp_sim(a->esq);
    printf("%d ", a->info);
    TAB_imp_sim(a->dir);
  }
}

void imp_aux(TAB *a, int andar){
  int j;
  if(a){
    imp_aux(a->esq, andar + 1);
    for(j = 0; j <= andar; j++) printf("\t"); //printf("   ");
    printf("%d\n", a->info);
    imp_aux(a->dir, andar + 1);
  }
  else{
   for(j = 0; j <= andar; j++) printf("\t");
   printf("N\n");
  }
}

void TAB_imp_ident(TAB *a){
  imp_aux(a, 0);
}

TAB * menor(TAB *a){
	if(a == NULL)
        return 0;
	TAB* minimoEsq = a;
	TAB* minimoDir = a;
	TAB* minimo = a;
	if(a->esq!=NULL){
		minimoEsq = menor(a->esq);
		if(minimo->info>minimoEsq->info){
			minimo = minimoEsq;
		}
	}if(a->dir!=NULL){
		minimoDir = menor(a->dir);
		if(minimo->info>minimoDir->info){
			minimo = minimoDir;
		}
	}
	return minimo;
	
}

int igual (TAB* a1, TAB* a2){
    if (a1==NULL && a2==NULL)
        return 1;
    if (a1!=NULL && a2!=NULL)
    {
        return
        (
            a1->info == a2->info &&
            igual(a1->esq, a2->esq) &&
            igual(a1->dir, a2->dir)
        );
    }
    return 0;
}

/*
void colore (TAB* arv){
	if(arv){
		if(arv->cor==0){
			arv->esq->cor = 1;
			arv->dir->cor = 1;
		}else if(arv->cor==1){
			arv->esq->cor = 0;
			arv->dir->cor = 0;
		}else{
			arv->cor = 0;
		}
		colore(arv->esq);
		colore(arv->dir);
	}
}
*/
int ni(TAB *a){
	int n = 0;
	if(a){
		if(a->esq!=NULL || a->dir!=NULL) n++;
		n+= ni(a->esq);
		n+= ni(a->dir);
	}return n;
}

int nf(TAB *a){
	int n = 0;
	if(a){
		if(a->esq==NULL && a->dir==NULL) n++;
		n+=nf(a->esq);
		n+=nf(a->dir);
	}return n;
}

void TAB_libera(TAB *a){
  if(a){
    TAB_libera(a->esq);
    TAB_libera(a->dir);
    free(a);
  }
}