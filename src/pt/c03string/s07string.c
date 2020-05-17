#include <stdio.h>
#include <string.h>

int main() {
   char login[51],
        lista[33] = "Asdrubal Alcebiades Brontossauro";

   puts("Digite seu login: ");
   gets(login);

   char *posicao = strstr(lista, login);
   if (posicao != NULL) {
      strcat(login, " voce esta logado");
      puts(login);
      puts(posicao);
   } else
      puts("sem autorizacao para entrar");

   return 0;
}
