#include <stdio.h>

#define TAMANHO 5

int main() {
   int vetor[TAMANHO];

   int indice,
       indiceMenor = 0;
   for (indice = 0; indice < TAMANHO; indice++) {
      printf("Digite um valor: ");
      scanf("%d", &vetor[indice]);
      if (vetor[indiceMenor] > vetor[indice])
         indiceMenor = indice;
   }

   int aux = vetor[0];
   vetor[0] = vetor[indiceMenor];
   vetor[indiceMenor] = aux;

   for (indice = 0; indice < TAMANHO; indice++)
      printf("invertido: %d\n", vetor[indice]);

   return 0;
}
