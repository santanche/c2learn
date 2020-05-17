#include <stdio.h>

#define DIAS_SEMANA 7

void converte(char semana[][8], int diaSemana) {
   printf("%s", semana[diaSemana]);
}

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
   int diaSemana;

   printf("Digite o dia da semana: ");
   scanf("%d", &diaSemana);

   converte(semana, diaSemana);

   // printf("Convertido: %s", convertido);

   return 0;
}
