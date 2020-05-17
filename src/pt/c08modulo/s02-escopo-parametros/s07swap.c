#include <stdio.h>

void swap(int *a, int *b) {
   int aux;
   aux = (*a);
   (*a) = (*b);
   (*b) = aux;
}

int main() {
   int a, b;

   printf("Digite a: ");
   scanf("%d", &a);
   printf("Digite b: ");
   scanf("%d", &b);

   swap(&a, &b);

   printf("a: %d, b: %d", a, b);

   return 0;
}
