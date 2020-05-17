#include <stdio.h>
#include <string.h>

int main() {
   char data[30],
        *p;

   printf("Digite uma data: ");
   scanf("%s", data);

   if (strlen(data) != 10)
      printf("data invalida: diferente de 10");
   else {
      p = strchr(data, '/');
      if (p == NULL || strlen(p) != 8)
         printf("data invalida: primeira barra errada");
      else {
         printf("%s\n", p);
         p++;
         p = strchr(p, '/');
         if (p == NULL || strlen(p) != 5)
            printf("data invalida: segunda barra errada");
         else {
            printf("%s\n", p);
            printf("data com barras ok");
         }
      }
   }


   return 0;
}
