#include <stdio.h>
#include <string.h>

int main() {
   char voto[100];

   char sultimo[100] = "",
        smaior1[100] = "",
        smaior2[100] = "";

   int ultimo = 0,
       maior1 = 0,
       maior2 = 0;

   do {
      scanf("%s", voto);
      if (strcmp(voto, sultimo) == 0)
         ultimo++;
      else {
         if (ultimo > maior1) {
            maior2 = maior1;
            strcpy(smaior2, smaior1);
            maior1 = ultimo;
            strcpy(smaior1, sultimo);
         } else if (ultimo > maior2) {
            maior2 = ultimo;
            strcpy(smaior2, sultimo);
         }
         strcpy(sultimo, voto);
         ultimo = 1;
      }
   } while (strcmp(voto, "FIM") != 0);

   if (maior1 > 0) {
      printf("primeiro lugar: %s", smaior1);
      if (maior2 > 0)
         printf("; segundo lugar: %s", smaior2);
   }

   return 0;
}
