#include <stdio.h>

int main() {
   int precos[4][3] = {
      {5, 7, 10},
      {6, 5, 15},
      {4, 5, 13},
      {7, 6, 12}
   };

   printf("Endereço (2,1): %d", precos[2][1]);

   return 0;
}
