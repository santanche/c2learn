#include <stdio.h>

int main() {
   int a, b;

   printf("Digite dois numeros: ");
   scanf("%d", &a);
   scanf("%d", &b);

   if (a > b)
      printf("Maior: %d", a);
   else
      printf("Maior: %d", b);

   return 0;
}
