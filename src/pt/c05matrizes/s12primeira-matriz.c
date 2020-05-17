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

   int l, c;
   for (l = 0; l < TOTAL_LINHAS; l++) {
      for (c = 0; c < TOTAL_COLUNAS; c++)
         printf("%d ", precos[l][c]);
      printf("\n");
   }

   return 0;
}
