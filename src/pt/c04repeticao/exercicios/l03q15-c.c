#include <stdio.h>

int main() {
   int segundos = 0,
       minutos  = 0,
       horas    = 0;

   while (horas < 24) {
      printf("%d:%d:%d\n",
             horas, minutos, segundos);
      segundos++;
      if (segundos == 60) {
         segundos = 0;
         minutos++;
         if (minutos == 60) {
            minutos = 0;
            horas++;
         }
      }
   }

   return 0;
}
