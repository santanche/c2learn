#include <stdio.h>
#include <string.h>

int main() {
   char login[51],
        montagem[101];

   puts("Digite seu login: ");
   gets(login);

   strcpy(montagem, "<");
   strcat(montagem, login);
   strcat(montagem, "> voce esta logado");

   puts(montagem);
   return 0;
}
