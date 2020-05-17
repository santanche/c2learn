#include <stdio.h>

int main() {
   int x = 5;
   int *y;

   y = &x;

   printf("tamanho x: %d; tamanho y: %d", sizeof(x), sizeof(y));

   return 0;
}
