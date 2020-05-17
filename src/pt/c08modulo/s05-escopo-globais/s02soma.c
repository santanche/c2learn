#include <stdio.h>

int valorSoma;

void soma() {
    int a, b;

    printf("Digite o primeiro numero: ");
    scanf("%d", &a);
    printf("Digite o segundo numero: ");
    scanf("%d", &b);

    valorSoma = a + b;

}

int main() {
    soma();

    printf("\nA soma eh %d", valorSoma);

    return 0;
}

