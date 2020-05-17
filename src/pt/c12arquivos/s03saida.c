#include <stdio.h>

int main() {
   FILE *arqSaida;

   arqSaida = fopen("salarios.txt", "w");

   if (arqSaida == NULL)
      printf("erro ao abrir o arquivo\n");
   else {
      fprintf(arqSaida, "Doriana %d\n", 7800);
      fprintf(arqSaida, "Quincas %d\n", 3200);
      fprintf(arqSaida, "Zandor %d\n", 1800);
   }

   fclose(arqSaida);

   printf("arquivo gravado com sucesso!\n");

   return 0;
}
