#include <stdio.h>
#include <stdlib.h>

typedef struct arvbinbusca{
    int info;
    struct arvbinbusca *esq, *dir;
}TABB;

void Insere_vect_elemento(int * vet, int elemento, int i){
	realloc(vet, sizeof(int)*i);
	*(vet+i-1) = elemento;	
}


void Insere_vect_vect(int * vet, int * vet2, int i){
	for(int j = 0;j<(sizeof(vet2)/sizeof(vet2[0]));j++){
		Insere_vect_elemento(vet, vet2[j], i++);
	}
	
}
void vetorizar(TABB * a, int * vet){
	int j = 1;
	vetorizar(a->esq, vet);
    Insere_vect_elemento(vet, a->info,j++);
    vetorizar(a->dir, vet);
}
}

int main(){
 int vet[1];
 vet[0] = 1;
 int vet2[1];
 vet2[0] = 2;
 Insere_vect_vect(vet,vet2,2);
 printf("%d", vet[1]);
 while(1){}
}