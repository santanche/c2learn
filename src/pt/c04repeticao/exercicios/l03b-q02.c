      #include <stdio.h>

      int main() {
         int x, y, z, w;

         printf("Digite dois numeros inteiros positivo s: ");
         scanf("%d", &x);
         scanf("%d", &y);

         z = x;
         w = y;
         while (z != 0 && w != 0) {
            z--;
            w--;
         }

         if (z > 0)
            printf("%d", x);
         else
            printf("%d", y);

         return 0;
      }
