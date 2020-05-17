#include <stdio.h>

int main()
{
    int a;
    int* b;

    a = 3;
    b = &a;
    (*b) += 5;

    printf("Valor de a: %d\n", a);
    printf("Valor de b: %d\n", *b);
    printf("O endereco de a: %d\n", b);

    return 0;
}
