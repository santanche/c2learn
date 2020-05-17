#include <stdio.h>

void calculaFatorial(int numero, int fatorial) {
   fatorial = 1;

   int i;
   for (i = numero; i > 1; i--)
      fatorial = fatorial * i;
}

int main() {
   int n;
   printf("Digite um numero: ");
   scanf("%d", &n);

   int resultado;
   calculaFatorial(n, resultado);

   // <erro> nao retorna o resultado da funcao
   printf("O fatorial eh %d", resultado);

   return 0;
}
