#include <stdio.h>

void list(int *p) {
   int i = 0;
   for (i = 0; i < 9; i++)
      printf("%d, ", p[i]);
}

int main() {
   int m[3][3] = {{4, 3, 5},
                  {2, 1, 2},
                  {5, 9, 9}
                 };
   list(m);

   return 0;
}
