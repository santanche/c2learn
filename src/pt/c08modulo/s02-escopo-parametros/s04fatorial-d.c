#include <stdio.h>

int calculaFatorial(int numero) {
   int fatorial = 1;

   int i;
   for (i = numero; i > 1; i--) {
      fatorial = fatorial * i;
   }

   return fatorial;
}

int main() {
   int resultado = calculaFatorial(5);

   printf("O fatorial eh %d", resultado);

   return 0;
}
