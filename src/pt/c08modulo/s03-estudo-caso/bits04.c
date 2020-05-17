/*
Serie de Programas: Modularizacao progressiva
Mostra etapas sucessivas do processo de modularizacao, ate se
chegar ao componente de software.

Exemplo:
Programa que calcula e apresenta o numero de combinacoes possiveis
que podem ser realizadas com bits, que variam de 1 a 8.

Terceira versao:
Tentativa de transferir a variavel "combinacoes" para os modulos,
a fim de remover a dependencia.

Erro de execucao:
- O programa principal deixa de ter acesso as variaveis que se
  tornaram locais.

Autor: Andre Santanche
Data:  01/03/2011
*/

#include <stdio.h>

void inicializa()
{
    int combinacoes;

    combinacoes = 1;
}

int proximoNumeroCombinacoes()
{
    int combinacoes;

    combinacoes *= 2;
    return combinacoes;
}

int main()
{
    int bits;

    inicializa();

    for (bits = 1; bits <= 8; bits++)
        printf("%d bits = %d combinacoes\n", bits, proximoNumeroCombinacoes());
}
