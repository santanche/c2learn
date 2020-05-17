#include <stdio.h>

int fibonacci(int n) {
   int fibo = 1;
   if (n > 2)
      fibo = fibonacci(n-1) + fibonacci(n-2);
   return fibo;
}

int main() {
   int numero;

   printf("Digite um numero: ");
   scanf("%d", &numero);

   int f = fibonacci(numero);

   printf("Fibonacci: %d", f);

   return 0;
}
