#include <stdio.h>

int main() {
   int n, soma = 0;

   do {
      printf("Digite um numero: ");
      scanf("%d", &n);
      if (n != 9999)
         soma += n;
   } while (n != 9999);

   printf("Soma: %d", soma);

   return 0;
}
