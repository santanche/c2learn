#include <stdio.h>

int main() {
   int x[5] = {3, 4, 8, 7, 9};

   int *y;
   y = &x[2];

   printf("%d", y[-1]);

   return 0;
}
