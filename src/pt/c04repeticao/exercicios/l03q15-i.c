#include <stdio.h>

int main() {
   int horas    = 0;

   while (horas < 24) {

      int minutos = 0;

      while (minutos < 60) {

         int segundos = 0;

         while (segundos < 60) {
            printf("%d:%d:%d\n",
                   horas, minutos, segundos);
            segundos++;
         }
         minutos++;
      }
      horas++;
   }

   return 0;
}
