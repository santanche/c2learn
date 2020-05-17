#include <stdio.h>

int soma() {
    int a,b;

    printf("Digite o primeiro numero:");
    scanf("%d", &a);
    printf("Digite o segundo numero: ");
    scanf("%d", &b);

    printf("\nA soma é %d", a+b);

    return (a+b);
}

int main() {
    soma();
    return 0;
}

