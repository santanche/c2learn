#include <stdio.h>

#include "fatorial.h"

int main() {
   int n;
   printf("Digite um numero: ");
   scanf("%d", &n);

   int resultado = calculaFatorial(n);

   printf("O fatorial eh %d", resultado);

   return 0;
}
