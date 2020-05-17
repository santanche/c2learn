#include <stdio.h>

int main() {
   // cria vetor de ponteiros
   int **m = malloc(3 * sizeof(int*));

   // cria um vetor para cada posicao
   int i;
   for (i = 0; i < 3; i++)
      m[i] = malloc(3 * sizeof(int));

   int* a = m[0];
   a[0] = 4;
   a[1] = 3;
   a[2] = 5;

   m[1][0] = 2;
   m[1][1] = 1;
   m[1][2] = 2;

   m[2][0] = 5;
   m[2][1] = 9;
   m[2][2] = 9;

   int j;
   for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++)
         printf("%d, ", m[i][j]);
      printf("\n");
   }

   for (i = 0; i < 3; i++)
      free(m[i]);
   free(m);

   return 0;
}
