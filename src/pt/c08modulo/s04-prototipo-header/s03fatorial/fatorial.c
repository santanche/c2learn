#include "fatorial.h"

int calculaFatorial(int numero) {
   int fatorial = 1;

   int i;
   for (i = numero; i > 1; i--) {
      fatorial = fatorial * i;
   }

   return fatorial;
}
