#include <stdio.h>

int main() {
    int numero, flag=0;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    int i;
    for (i = 2; i < numero; i++)
        if (numero % i == 0)
            flag = 1;

    if (flag == 0)
        printf("Este numero eh primo");
    else
        printf("Não eh primo");


    return 0;
}
