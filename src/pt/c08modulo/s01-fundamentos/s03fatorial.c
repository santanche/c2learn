#include <stdio.h>

void calculaFatorial() {
   int numeroF;
   int fatorial = 1;

   printf("\nDigite um numero: ");
   scanf("%d", &numeroF);

   int i;
   for (i = numeroF; i > 1; i--) {
      fatorial = fatorial * i;
   }

   printf("O fatorial de %d eh %d", numeroF, fatorial);
}

void calculaQuadrado() {
   int numeroQ;

   printf("\nDigite um numero: ");
   scanf("%d", &numeroQ);

   printf("O quadrado de %d eh %d", numeroQ, numeroQ*numeroQ);
}

int main() {
   calculaFatorial();

   calculaQuadrado();

   calculaFatorial();

   return 0;
}
