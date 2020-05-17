#include <stdio.h>

int main() {
   struct {
      int matricula;
      char nome[100];
      float salario;
   } funcionario;

   printf("Digite matricula: ");
   scanf("%d", &funcionario.matricula);
   printf("Digite nome: ");
   scanf("%s", funcionario.nome);
   printf("Digite salario: ");
   scanf("%f", &funcionario.salario);

   printf("Ficha: %d, %s, %f",
          funcionario.matricula,
          funcionario.nome,
          funcionario.salario);

   return 0;
}
