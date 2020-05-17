#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char v[] = "caju";
    
    char *w = "caju";
    
    char *z = malloc(100);
    strcpy(z, "caju");
    
    printf("Sao iguais?\n");
    printf("String v: %s\n", v);
    printf("String w: %s\n", w);
    printf("String z: %s\n", z);

    free(z);
    
    return 0;
}
