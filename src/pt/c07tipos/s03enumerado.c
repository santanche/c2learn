#include <stdio.h>

int main() {
   enum {
      domingo,
      segunda,
      terca,
      quarta,
      quinta,
      sexta,
      sabado
   } diaSemana;

   printf("Digite o dia da semana: ");
   scanf("%d", &diaSemana);

   printf("Valor digitado: %d\n", diaSemana);

   switch (diaSemana) {
      case domingo : printf("domingo"); break;
      case segunda : printf("segunda"); break;
      case terca   : printf("terca"); break;
      case quarta  : printf("quarta"); break;
      case quinta  : printf("quinta"); break;
      case sexta   : printf("sexta"); break;
      case sabado  : printf("sabado"); break;
      default : printf("dia errado");
   }

   return 0;
}
