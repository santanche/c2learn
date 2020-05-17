#include <stdlib.h>

int main()
{
    char *v = malloc(10);
    
    printf("Tamanho A: %d\n", sizeof(v));
    printf("Tamanho B: %d\n", sizeof(*v));

    return 0;
}
