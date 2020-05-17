#include <stdio.h>

int calculaFatorial() {
   int numero;
   int fatorial = 1;

   printf("Digite um numero: ");
   scanf("%d", &numero);

   int i;
   for (i = numero; i > 1; i--) {
      fatorial = fatorial * i;
   }

   return fatorial;
}

int main() {

   int resultado = calculaFatorial();

   printf("O fatorial eh %d", resultado);

   return 0;
}
