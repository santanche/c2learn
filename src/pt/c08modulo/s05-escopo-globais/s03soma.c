#include <stdio.h>

int a, b, valorSoma;

void soma() {
    valorSoma = a + b;
}

int main() {
    printf("Digite o primeiro numero: ");
    scanf("%d", &a);
    printf("Digite o segundo numero: ");
    scanf("%d", &b);

    soma();

    printf("\nA soma eh %d", valorSoma);

    return 0;
}

