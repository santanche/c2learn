#include <stdio.h>

#define TOTAL_LINHAS  4
#define TOTAL_COLUNAS 3

int main() {
   int precos[TOTAL_LINHAS][TOTAL_COLUNAS] = {
      {5, 7, 10},
      {6, 5, 15},
      {4, 5, 13},
      {7, 6, 12}
   };
   int *p;

   p = precos;

   int i;
   for (i = 0; i < TOTAL_LINHAS*TOTAL_COLUNAS; i++)
      printf("%d ", p[i]);

   return 0;
}
