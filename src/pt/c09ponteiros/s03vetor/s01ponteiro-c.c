#include <stdio.h>

int main() {
   int x[5] = {3, 4, 8, 7, 9};

   int *y;
   y = x;

   printf("%d", (*y)+2);

   return 0;
}
