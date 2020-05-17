#include <stdio.h>

void soma() {
    int a, b, valorSoma;

    printf("Digite o primeiro numero:");
    scanf("%d", &a);
    printf("Digite o segundo numero: ");
    scanf("%d", &b);

    valorSoma = a + b;

    printf("\nA soma eh %d", valorSoma);
}

int main() {
    soma();
    return 0;
}

