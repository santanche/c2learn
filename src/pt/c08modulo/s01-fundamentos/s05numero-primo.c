#include <stdio.h>

int calculaPrimo() {
   int numero;

   printf("Digite um numero: ");
   scanf("%d", &numero);

   int i;
   int fPrimo=1;

   for (i=2; i < numero && fPrimo == 1; i++) {

      if (numero % i == 0)
         fPrimo = 0;
   }

   return fPrimo;

}

int main() {
   int flag = calculaPrimo();

   if (flag == 0)
      printf("Nao eh primo");
   else
      printf("Primo");


   return flag;
}

