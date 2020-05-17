#include <stdio.h>

int main() {
   int segundos = 0,
       minutos  = 0;

   while (minutos < 60) {
      while (segundos < 60) {
         printf("%d:%d\n", minutos, segundos);
         segundos++;
      }
      segundos = 0;
      minutos++;
   }

   return 0;
}
