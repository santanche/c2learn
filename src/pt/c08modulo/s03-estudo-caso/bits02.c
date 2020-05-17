/*
Serie de Programas: Modularizacao progressiva
Mostra etapas sucessivas do processo de modularizacao, ate se
chegar ao componente de software.

Exemplo:
Programa que calcula e apresenta o numero de combinacoes possiveis
que podem ser realizadas com bits, que variam de 1 a 8.
Segunda versao:
Tentativa de modularizacao basica -- apenas procedures.

Erro de compilacao:
- Os modulos nao tem acesso a variavel "combinacoes" do main.

Autor: Andre Santanche
Data:  25/04/2012
*/


#include <stdio.h>

void inicializa()
{
    combinacoes = 1;
}

int proximoNumeroCombinacoes()
{
    combinacoes *= 2;
    return combinacoes;
}

int main()
{
    int bits;

    inicializa();

    for (bits = 1; bits <= 8; bits++)
        printf("%d bits = %d combinacoes\n", bits, proximoNumeroCombinacoes());

    return 0;
}
