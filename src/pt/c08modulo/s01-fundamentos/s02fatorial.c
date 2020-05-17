#include <stdio.h>

int main() {
   int numeroF;
   int fatorial = 1;

   printf("Digite um numero: ");
   scanf("%d", &numeroF);

   int i;
   for (i = numeroF; i > 1; i--)
      fatorial = fatorial * i;

   printf("O fatorial de %d eh %d", numeroF, fatorial);

   int numeroQ;
   printf("\nDigite um numero: ");
   scanf("%d", &numeroQ);

   printf("O quadrado de %d eh %d", numeroQ, numeroQ*numeroQ);

   fatorial = 1;
   printf("\nDigite um numero: ");
   scanf("%d", &numeroF);

   for (i = numeroF; i > 1; i--) {
      fatorial = fatorial * i;
   }

   printf("O fatorial de %d eh %d", numeroF, fatorial);

   return 0;
}
