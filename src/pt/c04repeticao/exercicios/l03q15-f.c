#include <stdio.h>

int main() {
   int segundos = 0,
       minutos  = 0,
       horas    = 0;

   while (horas < 24) {
      while (minutos < 60) {
         while (segundos < 60) {
            printf("%d:%d:%d\n",
                   horas, minutos, segundos);
            segundos++;
         }
         segundos = 0;
         minutos++;
      }
      minutos = 0;
      horas++;
   }

   return 0;
}
