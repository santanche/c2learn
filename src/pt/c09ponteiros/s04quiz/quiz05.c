#include <stdio.h>

void swap(int *a, int *b)
{
     int x;
     x = *a;
     *a = *b;
     *b = x;
}

int main()
{
    int a, b;
    a = 3;
    b = 5;
    swap(&a, &b);
    
    printf("Valor de a: %d\n", a);
    printf("Valor de b: %d\n", b);
    
    return 0;
}
