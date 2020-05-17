#include <stdio.h>

int valorSoma=0;

void soma() {
    int a,b;

    printf("Digite o primeiro numero:");
    scanf("%d", &a);
    printf("Digite o segundo numero: ");
    scanf("%d", &b);

    valorSoma = a + b;

}

int main() {

    soma();

    printf("\nA soma é %d", valorSoma);

    return 0;
}

