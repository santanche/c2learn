#include <stdio.h>

int main() {
   int m[3][3] = {{4, 3, 5},
                  {2, 1, 2},
                  {5, 9, 9}
                 };
   int *p = m;

   int i = 0;
   for (i = 0; i < 9; i++)
      printf("%d, ", p[i]);

   return 0;
}
