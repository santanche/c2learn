#include <stdio.h>

int main() {
    int numero, fatorial = 1;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);

    int i;
    for (i=1; i <= numero; i++)
        fatorial = fatorial * i;

    printf("O fatorial de %d eh %d", numero, fatorial);
}
