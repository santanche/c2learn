/*
Serie de Programas: Modularizacao progressiva
Mostra etapas sucessivas do processo de modularizacao, ate se
chegar ao componente de software.

Exemplo:
Programa que calcula e apresenta o numero de combinacoes possiveis
que podem ser realizadas com bits, que variam de 1 a 8.

Primeira versao:
Programa sem modularizacao.

Autor: Andre Santanche
Data:  01/03/2010
*/

#include <stdio.h>

int main()
{
    int combinacoes = 1,
        bits;

    for (bits = 1; bits <= 8; bits++)
    {
        combinacoes *= 2;
        printf("%d bits = %d combinacoes\n", bits, combinacoes);
    }

    return 0;
}
