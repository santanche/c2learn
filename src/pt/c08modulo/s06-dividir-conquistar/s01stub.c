#include <stdio.h>

int calcula_custo() {
    //custo = tempo * custo/hora
    int custo=0;

    custo = retorna_tempo_producao() * retorna_custo_por_hora();

    return custo;
}

int retorna_tempo_producao() {
    return 10;
}

int retorna_custo_por_hora() {
    return 2;
}

int main(){

    printf("Custo é igual a %d", calcula_custo());

    return 0;
}
