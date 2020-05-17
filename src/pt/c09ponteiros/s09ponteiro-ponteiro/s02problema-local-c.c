#include <stdio.h>
#include <stdlib.h>

void atribui(int **pa) {
   int *b = malloc(sizeof(int));
   (*b) = 175;
   (*pa) = b;
}

void alguem() {
   int z = 21;
}

int main() {
   int *a;

   atribui(&a);
   alguem();

   printf("%d", *a);

   free(a);

   return 0;
}
