#include <stdio.h>

int main() {
   typedef struct {
      int matricula;
      char nome[100];
      float salario;
   } TipoFuncionario;

   typedef struct {
      TipoFuncionario funcionario;
      char departamento[100];
   } TipoChefe;

   TipoChefe chefe;

   printf("Digite matricula: ");
   scanf("%d", &chefe.funcionario.matricula);
   printf("Digite nome: ");
   scanf("%s", chefe.funcionario.nome);
   printf("Digite salario: ");
   scanf("%f", &chefe.funcionario.salario);
   printf("Digite departamento: ");
   scanf("%s", chefe.departamento);

   printf("Ficha: %d, %s, %f, %s",
          chefe.funcionario.matricula,
          chefe.funcionario.nome,
          chefe.funcionario.salario,
          chefe.departamento);

   return 0;
}
