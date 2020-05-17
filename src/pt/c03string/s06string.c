#include <stdio.h>
#include <string.h>

int main() {
   char login[51];

   puts("Digite seu login: ");
   gets(login);

   if (strcmp(login, "Asdrubal") == 0) {
      strcat(login, " voce esta logado");
      puts(login);
   } else
      puts("sem autorizacao para entrar");

   return 0;
}
