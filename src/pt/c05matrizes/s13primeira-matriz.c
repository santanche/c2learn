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

   int l = 0, c = 0;
   while (l < TOTAL_LINHAS) {
      printf("%d ", precos[l][c]);
      c++;
      if (c == TOTAL_COLUNAS) {
         l++;
         c = 0;
         printf("\n");
      }
   }

   return 0;
}
