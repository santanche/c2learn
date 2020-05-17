#include <stdio.h>
#include <string.h>

int main() {
   char login[101];

   puts("Digite seu login: ");
   gets(login);

   strcat(login, " voce esta logado");

   puts(login);
   return 0;
}
