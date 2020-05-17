#include <stdio.h>

#define MESES 12

int main() {
   int dias[MESES] = {31,28,31,30,31,30,31,31,30,31,30,31};

   printf("Dias dos meses: ");

   int m;
   for (m = 0; m < MESES; m++)
       printf("%d, ", dias[m]);

   return 0;
}
