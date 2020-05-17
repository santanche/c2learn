#include <stdio.h>

void list(int **p) {
   int i, j;
   for (i = 0; i < 3; i++)
      for (j = 0; j < 3; j++)
         printf("%d, ", p[i][j]);
}

int main() {
   int **m = malloc(9 * sizeof(int));



   {{4, 3, 5},
                     {2, 1, 2},
                     {5, 9, 9}
                    };
   list(m);

   return 0;
}
