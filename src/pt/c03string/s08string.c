#include <stdio.h>
#include <string.h>

int main() {
   char login[51],
        reconhecidos[24] = "quincas,asdrubal,zandor";

   puts("Digite seu login: ");
   gets(login);

   if (strstr(reconhecidos, login) != NULL) {
      strcat(login, " voce esta logado");
      puts(login);
   } else
      puts("sem autorizacao para entrar");

   return 0;
}
