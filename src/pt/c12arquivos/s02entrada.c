#include <stdio.h>

#define TAM_LINHA 200

int main() {
   char linha[TAM_LINHA];

   while (gets(linha) != NULL)
      printf("%s", linha);
}
