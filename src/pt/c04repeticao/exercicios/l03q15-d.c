#include <stdio.h>

#define SEGUNDOS_MINUTO 60
#define MINUTOS_HORA    60
#define TOTAL_HORAS     24

int main() {
   int segundos = 0,
       minutos  = 0,
       horas    = 0;

   while (horas < TOTAL_HORAS) {
      printf("%d:%d:%d\n",
             horas, minutos, segundos);
      segundos++;
      if (segundos == SEGUNDOS_MINUTO) {
         segundos = 0;
         minutos++;
         if (minutos == MINUTOS_HORA) {
            minutos = 0;
            horas++;
         }
      }
   }

   return 0;
}
