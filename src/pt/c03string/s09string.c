#include <stdio.h>
#include <string.h>

int main() {
   char data[21];

   puts("Digite uma data:");
   gets(data);

   if (strlen(data) != 10)
      puts("data invalida");
   else {
      char *barra = strchr(data, '/');
      if (barra == NULL || strlen(barra) != 8)
         puts("data invalida");
      else
         puts(barra);
   }

   return 0;
}
