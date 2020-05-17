#include <stdio.h>

int main() {
   int n, soma = 0;

   printf("Digite um numero: ");
   scanf("%d", &n);
   while (n != 9999) {
      soma += n;
      printf("Digite um numero: ");
      scanf("%d", &n);
   }

   printf("Soma: %d", soma);

   return 0;
}
