#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char v[] = "jaca tatu";
 
    char *z;
    z = malloc(strlen(v) + 1);
    strcpy(z, v);
    
    z[4] = '-';
    printf("String v: %s\n", v);
    printf("String z: %s\n\n", z);
    
    char *w;
    w = v;
    w[4] = '-';
    printf("String v: %s\n", v);
    printf("String w: %s\n", w);
    
    free(z);
    
    return 0;
}
