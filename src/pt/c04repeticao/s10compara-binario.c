#include <stdio.h>

int main() {
   int numero,
       bit;

   printf("Digite um numero: ");
   scanf("%d", &numero);

   int igual = 1;

   int b,
       divisor = 128;
   for (b = 1; b <= 8; b++) {
       printf("Digite um bit: ");
       scanf("%d", &bit);

       if ((numero >= divisor && bit == 0) ||
           (numero < divisor && bit == 1))
          igual = 0;

       numero = numero % divisor;
       divisor /= 2;
   }

   if (igual == 1)
      printf("Sao iguais");
   else
      printf("Sao diferentes");

   return 0;
}
