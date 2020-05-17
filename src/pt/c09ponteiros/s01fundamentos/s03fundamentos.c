#include <stdio.h>

int main() {
   int x = 5;
   int *y;

   y = &x;

   printf("x: %d; y: %d; *y: %d", x, y, *y);

   return 0;
}
