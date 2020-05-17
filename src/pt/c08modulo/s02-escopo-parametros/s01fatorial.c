#include <stdio.h>

int main() {
   int numero;
   int fatorial = 1;

   printf("Digite um numero: ");
   scanf("%d", &numero);

   int i;
   for (i = numero; i > 1; i--)
      fatorial = fatorial * i;

   printf("O fatorial eh %d", fatorial);

   return 0;
}
