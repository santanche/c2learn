#include <stdio.h>

int main() {
   int x = 5;
   int *y;

   y = &x;
   (*y)++;

   printf("x: %d; y: %d; *y: %d; &y: %d", x, y, *y, &y);

   return 0;
}
