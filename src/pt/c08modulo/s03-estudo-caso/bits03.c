/*
Serie de Programas: Modularizacao progressiva
Mostra etapas sucessivas do processo de modularizacao, ate se
chegar ao componente de software.

Exemplo:
Programa que calcula e apresenta o numero de combinacoes possiveis
que podem ser realizadas com bits, que variam de 1 a 8.
Segunda versao:
Programa com modularizacao basica -- apenas procedures.

Vantagens:
- Modulos encapsulem a logica do calculo de combinacoes,
  de forma que ela possa ser reusada.

Problemas:
- Os modulos dependem do programa principal que mantem a variavel
  "combinacoes".
- O programa principal se torna responsavel por detalhes de
  implementacao dos modulos, o que prejudica o reuso:
  . cada vez que um programa reusar os modulos precisara declarar
    a variavel "combinacoes";
  . a nova variavel "combinacoes" declarada pode entrar em
    conflito com uma ja existente, o que exige modificacao do
    codigo.

Autor: Andre Santanche
Data:  01/03/2011
*/


#include <stdio.h>

int combinacoes;

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
