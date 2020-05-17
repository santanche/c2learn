#include <stdlib.h>
#include <string.h>

int main()
{
    int i;

    char *z = malloc(10);
    for (i = 0; i < 10; i++)
        z[i] = '.';
    strcpy(z, "caju");
    
    printf("String: %s\n\n", z);
    
    printf("Caracteres da string ate strlen:\n");
    for (i = 0; i < strlen(z); i++)
        printf("%c", z[i]);
    printf("\n");
    for (i = 0; i < strlen(z); i++)
        printf("%c[%d] ", z[i], z[i]);
    printf("\n");
    
    printf("\n\nCaracteres da string ate espaco alocado (10 bytes):\n");
    for (i = 0; i < 10; i++)
        printf("%c", z[i]);
    printf("\n");
    for (i = 0; i < 10; i++)
        printf("%c[%d] ", z[i], z[i]);
    printf("\n");

    return 0;
}
