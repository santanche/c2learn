#include <stdio.h>

void imprimeVetor(int *vetor) {
   int i;
   for (i = 0; i < 3; i++)
      printf("%d, ", vetor[i]);
}

int main() {
   int v[3] = {5, 7, 9};

   imprimeVetor(v);
}
