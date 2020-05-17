#include <stdio.h>
#include <stdlib.h>

#define DIAS_SEMANA 7

char* converte(char** semana, int diaSemana) {
   return semana[diaSemana];
}

int main() {
   char semanaBase[][8] = {
      "segunda",
      "terca",
      "quarta",
      "quinta",
      "sexta",
      "sabado",
      "domingo"
   };
   char** semana = malloc(sizeof(char*) * 7);
   int i;
   for (i = 0; i < 7; i++) {
      semana[i] = malloc(sizeof(char) * 8);
      strcpy(semana[i], semanaBase[i]);
   }

   int diaSemana;

   printf("Digite o dia da semana: ");
   scanf("%d", &diaSemana);

   char* convertido = converte(semana, diaSemana);

   printf("Convertido: %s", convertido);

   return 0;
}
