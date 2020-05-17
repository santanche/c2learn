#include <stdio.h>

int main() {
   unsigned char n;
   char *n2;

   printf("Digite um numero: ");
   scanf("%d", &n);

   n2 = &n;

   printf("Voce digitou: %d", (*n2));

   return 0;
}
