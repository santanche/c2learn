#include <stdio.h>

int main()
{
    char v[] = "jaca tatu";
 
    char *w;
    w = v;
    w[4] = '-';
    printf("String v: %s\n", v);
    printf("String w: %s\n\n", w);
    
    *(w+4) = '#';
    printf("String v: %s\n", v);
    printf("String w: %s\n\n", w);
    
    char *z;
    z = v;
    z += 4;
    z[0] = '*';
    printf("String v: %s\n", v);
    printf("String z: %s\n\n", z);

    z++;
    strcpy(z, "caja");
    printf("String v: %s\n", v);
    printf("String z: %s\n\n", z);

    char *x;
    x = &v[4];
    x[0] = '%';
    printf("String v: %s\n", v);
    printf("String x: %s\n", x);

    return 0;
}
