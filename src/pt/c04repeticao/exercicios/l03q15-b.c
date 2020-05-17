#include <stdio.h>

int main() {
   int segundos = 0,
       minutos  = 0;

   while (minutos < 60) {
      printf("%d:%d\n", minutos, segundos);
      segundos++;
      if (segundos == 60) {
         segundos = 0;
         minutos++;
      }
   }

   return 0;
}
