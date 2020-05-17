#include <stdio.h>

#define TAM_LINHA 200

int main() {
   char linha[TAM_LINHA];
   FILE *arqEntrada;

   arqEntrada = fopen("salarios.txt", "r");

   if (arqEntrada == NULL)
      printf("erro na abertura do arquivo\n");
   else {
      while (fgets(linha, TAM_LINHA-1, arqEntrada) != NULL)
         printf("%s", linha);
   }

   fclose(arqEntrada);
}
