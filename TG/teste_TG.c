#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


void criaArqOrd(char *nome);
void Merge(char *arq1, char *arq2, char *saida);

int main(int argc, char **argv){
  if(argc != 4){
    printf("Erro: chamada correta e exec <nome_arq1> <nome_arq2> <nome_arq_saida>\n");
    exit(1);
  }
  criaArqOrd(argv[1]);
  criaArqOrd(argv[2]);
  Merge(argv[1], argv[2], argv[3]);
}

void criaArqOrd(char *nome){
  FILE *fp = fopen(nome, "w");
  if(!fp) exit(1);
  int n, ant;
  scanf("%d", &ant);
  fprintf(fp, "%d\n", ant);
  do{
    scanf("%d", &n);
    if(n < ant) break;
    ant = n;
    fprintf(fp, "%d\n", ant);  
  }while(1);
  fclose(fp);
}

void Merge(char *arq1, char *arq2, char *saida){
  FILE *fp1 = fopen(arq1, "r"), *fp2 = fopen(arq2, "r"), *fp = fopen(saida, "w");
  if((!fp1) || (!fp2) || (!fp)) exit(1);
  int n1, n2, r1, r2;
  r1 = fscanf(fp1, "%d", &n1);
  r2 = fscanf(fp2, "%d", &n2);
  while((r1 == 1) || (r2 == 1)){
    if((r2 != 1) || (n1 <= n2)){
      fprintf(fp, "%d\n", n1);
      r1 = fscanf(fp1, "%d", &n1);
      if(r1 != 1) n1 = INT_MAX;
    }
    else if((r1 != 1) || (n2 < n1)){
      fprintf(fp, "%d\n", n2);
      r2 = fscanf(fp2, "%d", &n2);
      if(r2 != 1) n2 = INT_MAX;
    }
  }
  fclose(fp1);
  fclose(fp2);
  fclose(fp);  
}