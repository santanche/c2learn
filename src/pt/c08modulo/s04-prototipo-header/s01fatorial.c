#include <stdio.h>

int calculaFatorial(int numero);

int main() {
   int n;
   printf("Digite um numero: ");
   scanf("%d", &n);

   int resultado = calculaFatorial(n);

   printf("O fatorial eh %d", resultado);

   return 0;
}

int calculaFatorial(int numero) {
   int fatorial = 1;

   int i;
   for (i = numero; i > 1; i--) {
      fatorial = fatorial * i;
   }

   return fatorial;
}
