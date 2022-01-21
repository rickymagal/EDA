#include "TLSE.h"

TLSE* TLSE_inicializa(void){
  return NULL;
}

TLSE* TLSE_ins_ini(TLSE* l, int elem){
  TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
  novo->info = elem;
  novo->prox = l;
  return novo;
}

void TLSE_imprime(TLSE* l){
  while(l){
    printf("%d ", l->info);
    l = l->prox;
  }
}

void TLSE_imp_rec(TLSE* l){
  if(l){
    printf("%d ", l->info);
    TLSE_imp_rec(l->prox); 
  }
}

void TLSE_imp_rec_rev(TLSE* l){
  if(l){
    TLSE_imp_rec_rev(l->prox); 
    printf("%d ", l->info);
  }
}

TLSE* TLSE_ins_fim(TLSE* l, int elem){
  if(!l) return TLSE_ins_ini(l, elem);
  TLSE *p = l;
  while(p->prox) p = p->prox;
  p->prox = TLSE_ins_ini(p->prox, elem);
  return l;
}

TLSE* TLSE_ins_fim_rec(TLSE* l, int elem){
  if(!l) return TLSE_ins_ini(l, elem);
  l->prox = TLSE_ins_fim_rec(l->prox, elem);
  return l;
}

void TLSE_libera(TLSE* l){
  TLSE *p = l, *q;
  while(p){
    q = p;
    p = p->prox;
    free(q);
  }
}

void TLSE_lib_rec(TLSE* l){
  if(l){
    TLSE_lib_rec(l->prox);
    free(l);
  }
}

TLSE* TLSE_busca(TLSE* l, int elem){
  TLSE *resp = l;
  while((resp) && (resp->info != elem)) resp = resp->prox;
  return resp;
}

TLSE* TLSE_busca_rec(TLSE* l, int elem){
  if((!l) || (l->info == elem)) return l;
  return TLSE_busca_rec(l->prox, elem);
}

TLSE* TLSE_retira(TLSE* l, int elem){
  TLSE *p = l, *ant = NULL;
  while((p) && (p->info != elem)){
    ant = p;
    p = p->prox;
  }
  if(!p) return l;
  if(!ant) l = l->prox;
  else ant->prox = p->prox;
  free(p);
  return l;
}

TLSE* TLSE_retira_rec(TLSE* l, int elem){
  if(!l) return l;
  if(l->info == elem){
    TLSE *temp = l;
    l = l->prox;
    free(temp);
  }
  else l->prox = TLSE_retira_rec(l->prox, elem);
  return l;
}

TLSE* TLSE_retira_pos(TLSE* l, int pos){
  TLSE *p = l, *ant = NULL;
  int i = 1;
  while((p) && i<pos){
    ant = p;
    p = p->prox;
	i++;
  }
  if(!p) return l;
  if(!ant) l = l->prox;
  else ant->prox = p->prox;
  free(p);
  return l;
}

//SUPOR QUE A l ORIGINAL ESTA ORDENADA. QUANDO TERMINAR A EXECUCAO, ELA CONTINUARA ORDENADA... 
TLSE* TLSE_ins_ord(TLSE* l, int elem){
  TLSE *novo = TLSE_ins_ini(NULL, elem);
  if(!l) return novo;
  TLSE *p = l, *ant = NULL;
  while((p) && (p->info < elem)){
    ant = p;
    p = p->prox;
  }
  if(!ant){
    novo->prox = l;
    return novo;
  }
  novo->prox = p;
  ant->prox = novo;
  return l;
}

//SUPOR QUE A l ORIGINAL ESTA ORDENADA. QUANDO TERMINAR A EXECUCAO, ELA CONTINUARA ORDENADA... 
TLSE* TLSE_ins_ord_rec(TLSE* l, int elem){
  if((!l) || (l->info >= elem)) return TLSE_ins_ini(l, elem);
  l->prox = TLSE_ins_ord_rec(l->prox, elem);
  return l;
}

void inverte_modifica(TLSE** l){
	TLSE* current = *l;
	TLSE* prev = NULL;
	TLSE* next = NULL;
	while(current!=NULL){
		next = current->prox;
		current->prox = prev;
		prev= current;
		current = next;
	}
	*l = prev;
}

TLSE * inverte(TLSE* l){
	TLSE * current = l;
	TLSE * new = TLSE_inicializa();
	while(current!=NULL){
		new = TLSE_ins_ini(new,current->info);
		current = current->prox;
	}return new;
}

TLSE * desloca (TLSE* l, int n){
	TLSE * first = l;
	TLSE * current = l;
	TLSE * next = l->prox;
	TLSE * new = TLSE_inicializa();
	if(n%2==0){
		while(current->prox!=NULL){
			new = TLSE_ins_fim(new, (current->prox)->info);
			current = current->prox;
		}
		new = TLSE_ins_fim(new,first->info);
	}else{
		while(current->prox!=NULL){
			new = TLSE_ins_fim(new, current->info);
			current = current->prox;
		}
		new = TLSE_ins_ini(new,current->info);
	}
	free(first);
	free(current);
	free(next);
	return new;
}

TLSE *copia (TLSE *l){
	TLSE * current = l;
	TLSE * new = TLSE_inicializa();
	while(current!=NULL){
		new = TLSE_ins_fim(new,current->info);
		current = current->prox;
	}
	free(current);
	return new;
}

TLSE* rto (TLSE* l, int elem){
  TLSE *p = l;
  TLSE * new = TLSE_inicializa();
  while(p){
	  if(p->info != elem){
		  new = TLSE_ins_fim(new,p->info);
	  }
	  p = p->prox;
  }
  free(p);
  return new;
}

LSE* i_p (TLSE *l){
	TLSE * p = l;
	TLSE * pares = TLSE_inicializa();
	TLSE * impares = TLSE_inicializa();
	while(p){
		if(p->info%2==0){
			pares = TLSE_ins_fim(pares,p->info);
		}else{
			impares = TLSE_ins_fim(impares,p->info);
		}
	p = p->prox;
	}
	
}