#include <stdio.h>

int main() {
   typedef float TipoSalario;

   TipoSalario salario;

   printf("Digite salario: ");
   scanf("%f", &salario);

   printf("Salario: %f", salario);

   return 0;
}
