#include <stdio.h>

int main() {
   int vetor[5];

   vetor[0] = 12;
   vetor[3] = 27;

   printf("Digite um valor: ");
   scanf("%d", &vetor[1]);
   printf("Voce digitou: %d", vetor[1]);

   return 0;
}
