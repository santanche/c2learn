#include <stdio.h>

int main() {
   int vetor[5];

   int indice = 0;
   do {
      printf("Digite um valor: ");
      scanf("%d", &vetor[indice]);
      indice++;
   } while (indice < 5);

   indice = 4;
   while (indice >= 0) {
      printf("invertido: %d\n", vetor[indice]);
      indice--;
   }

   return 0;
}
