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
   int n;

   for (n = 1; n <= 10; n++) {
      int resultado = calculaFatorial(n);
      printf("O fatorial eh %d\n", resultado);
   }

   return 0;
}
