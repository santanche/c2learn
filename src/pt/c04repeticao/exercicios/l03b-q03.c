#include <stdio.h>

int main() {
   int m1, f1;
   float p1, j1;
   float v2, ap2, j2;
   int f2;

   scanf("%d,%f,%f,%d", &m1, &p1, &j1, &f1);
   scanf("%f,%f,%f,%d", &v2, &ap2, &j2, &f2);

   float saldo2 = v2;
   float parcela1 = p1;
   float acum1 = 0, acum2 = 0;
   int mes;
   for (mes = 1; mes <= m1 || saldo2 <= (v2/100);
        mes++) {
      float apagar = 0;

      acum1 += parcela1;

      if (mes % f1 == 0) {
         apagar += acum1;
         acum1 = 0;
      }


      parcela1 = parcela1 + (parcela1 * j1/100);
   }

   return 0;
}
