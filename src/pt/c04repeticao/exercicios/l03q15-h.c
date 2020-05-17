#include <stdio.h>

int main() {
   int minutos  = 0,
       horas    = 0;

   while (horas < 24) {
      while (minutos < 60) {
         int segundos = 0;
         while (segundos < 60) {
            printf("%d:%d:%d\n",
                   horas, minutos, segundos);
            segundos++;
         }
         minutos++;
      }
      printf("%d\n", segundos);
      minutos = 0;
      horas++;
   }

   return 0;
}
