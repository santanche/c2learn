#include <stdio.h>

int main() {
   int x[5];
   x[0] = 3;
   x[1] = 4;
   x[2] = 8;
   x[3] = 7;
   x[4] = 9;

   int *y;
   y = x;

   printf("%d", y[2]);

   return 0;
}
