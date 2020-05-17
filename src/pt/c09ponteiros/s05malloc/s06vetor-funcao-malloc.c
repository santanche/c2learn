#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int* criaVetor() {
   int *x = (int *)malloc(5 * sizeof(int));
   x[0] = 3;
   x[1] = 4;
   x[2] = 8;
   x[3] = 7;
   x[4] = 9;

   return x;
}

int main() {
   int *y;
   y = criaVetor();

   printf("%d", y[2]);

   free(y);

   return 0;
}
