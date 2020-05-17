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

   printf("Endereço (2,1): %d", precos[2][1]);

   return 0;
}
