#include <stdio.h>

#define DIAS_SEMANA 7

int main() {
   char semana[][8] = {
      "segunda",
      "terca",
      "quarta",
      "quinta",
      "sexta",
      "sabado",
      "domingo"
   };

   printf("Dias da semana: ");

   int d;
   for (d = 0; d < DIAS_SEMANA; d++)
       printf("%s, ", semana[d]);

   return 0;
}
