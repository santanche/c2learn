#include <stdio.h>

int main()
{
    int total, sobra;
    scanf("%d", &total);

    printf("%d,", total / 100);
    sobra = total % 100;
    printf("%d,", sobra / 50);
    sobra = sobra % 50;
    printf("%d,", sobra / 10);
    sobra = sobra % 10;
    printf("%d,", sobra / 5);
    sobra = sobra % 5;
    printf("%d\n", sobra);

    return 0;
}
