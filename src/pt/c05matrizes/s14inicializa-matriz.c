#include <stdio.h>
#include <string.h>

#define TOTAL_LINHAS  4
#define TOTAL_COLUNAS 3

int main() {
   int precos[TOTAL_LINHAS][TOTAL_COLUNAS];

   memset(precos, 0,
          TOTAL_LINHAS * TOTAL_COLUNAS *
          sizeof(int));

   int l, c;
   for (l = 0; l < TOTAL_LINHAS; l++) {
      for (c = 0; c < TOTAL_COLUNAS; c++)
         printf("%d ", precos[l][c]);
      printf("\n");
   }

   return 0;
}
