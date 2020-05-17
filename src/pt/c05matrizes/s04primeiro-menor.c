#include <stdio.h>

#define TAMANHO 5

int main() {
   int vetor[TAMANHO];

   int indice;
   for (indice = 0; indice < TAMANHO; indice++) {
      printf("Digite um valor: ");
      scanf("%d", &vetor[indice]);
   }

   int menor = vetor[0],
       indiceMenor = 0;
   for (indice = 1; indice < TAMANHO; indice++)
      if (menor > vetor[indice]) {
         menor = vetor[indice];
         indiceMenor = indice;
      }
   vetor[indiceMenor] = vetor[0];
   vetor[0] = menor;

   for (indice = 0; indice < TAMANHO; indice++)
      printf("invertido: %d\n", vetor[indice]);

   return 0;
}
