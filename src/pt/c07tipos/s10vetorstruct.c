#include <stdio.h>

#define TOTAL_FUNCIONARIOS 2

int main() {
   typedef struct {
      int matricula;
      char nome[100];
      float salario;
   } TipoFuncionario;

   TipoFuncionario funcionarios[TOTAL_FUNCIONARIOS];

   int f;
   for (f = 0; f < TOTAL_FUNCIONARIOS; f++) {
      printf("Digite matricula: ");
      scanf("%d", &funcionarios[f].matricula);
      printf("Digite nome: ");
      scanf("%s", funcionarios[f].nome);
      printf("Digite salario: ");
      scanf("%f", &funcionarios[f].salario);
   }

   for (f = 0; f < TOTAL_FUNCIONARIOS; f++)
      printf("Ficha: %d, %s, %f",
             funcionarios[f].matricula,
             funcionarios[f].nome,
             funcionarios[f].salario);

   return 0;
}
