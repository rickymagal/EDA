#include <string.h>
#include "TABB.h"


int main(void){
  int no, pai;
  printf("Digite a raiz da arvore... ");
  scanf("%d", &no);
  TABB *a = cria(no, NULL, NULL), *resp;
  char repete;
  do{
    char lado[2];
    printf("Quer continuar inserindo nos na árvore (digite N ou n para parar)? ");
    scanf(" %c", &repete);
    if((repete == 'N') || (repete == 'n')) break;
    printf("Digite o pai (que deve existir), o filho a ser inserido na arvore e a posição E(ESQ) ou D(DIR)... ");
    scanf("%d%d%s", &pai, &no, lado);
    resp = busca(pai,a);
    if(!resp){
      libera(a);
      return 0;
    }
    if(strcmp(lado, "E") == 0) resp->esq = cria(no, NULL, NULL);
    else resp->dir = cria(no, NULL, NULL);
  }while(1);
  imprime(a);
  printf("Maior elemento, %d\n", maior(a)->info);
  printf("Menor elemento, %d\n", menor(a)->info);
  imprime(a);
  int * vet;
  vetorizar(a,vet);
  printf("%d", vet[1]);
  a = retira_impares(a);
  printf("Retirando impares:\n");
  libera(a);
  while(1){}
  return 0;
}