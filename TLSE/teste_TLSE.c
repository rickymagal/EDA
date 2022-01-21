#include "TLSE.h"

int main(void){
  TLSE *l = TLSE_inicializa();
  l = TLSE_ins_ord_rec(l, 1);
  l = TLSE_ins_ord_rec(l, 3);
  l = TLSE_ins_ord_rec(l, 0);
  l = TLSE_ins_ord_rec(l, 2);
  TLSE_imprime(l);
  printf("\n");
  l = inverte(l);
  TLSE_imprime(l);
   printf("\n");
  l = desloca(l,1);
  TLSE_imprime(l);
  printf("\n");
  l = copia(l);
  TLSE_imprime(l);
  printf("\n");
  l = rto(l,3);
  TLSE_imprime(l);
  printf("\n");
  TLSE_lib_rec(l);
  while(1){}
  return 0;
}