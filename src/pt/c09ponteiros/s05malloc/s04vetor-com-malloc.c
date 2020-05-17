#include <stdio.h>
#include <stdlib.h>

int main() {
   int *x = (int *)malloc(5 * sizeof(int));
   x[0] = 3;
   x[1] = 4;
   x[2] = 8;
   x[3] = 7;
   x[4] = 9;

   int *y;
   y = x;

   printf("%d", y[2]);

   free(x);

   return 0;
}
