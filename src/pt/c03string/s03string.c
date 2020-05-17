#include <stdio.h>
#include <string.h>

int main() {
   char login[21];

   puts("Digite seu login (max 6 carac): ");
   gets(login);

   if (strlen(login) > 6)
      puts("Login muito grande");
   else
      puts("Voce esta logado");
   return 0;
}
