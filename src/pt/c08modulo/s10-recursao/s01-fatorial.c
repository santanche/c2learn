#include <stdio.h>

int fatorial(int n) {
   int fat = 1;
   if (n != 0)
      fat = n * fatorial(n-1);
   return fat;
}

int main() {
   int numero;

   printf("Digite um numero: ");
   scanf("%d", &numero);

   int f = fatorial(numero);

   printf("Fatorial: %d", f);

   return 0;
}
