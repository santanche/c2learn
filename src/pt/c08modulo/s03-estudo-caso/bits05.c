/*
Serie de Programas: Modularizacao progressiva
Mostra etapas sucessivas do processo de modularizacao, ate se
chegar ao componente de software.

Exemplo:
Programa que calcula e apresenta o numero de combinacoes possiveis
que podem ser realizadas com bits, que variam de 1 a 8.

Quarta versao:
Uma variavel global e declarada e passada como parametro para os
modulos.

Vantagens:
- A variavel do programa principal se torna independente da
  variavel dos modulos (o nome pode ser diferente).

Problemas:
- O programa principal continua precisando declarar e manter a
  variavel "combinacoes", o que ainda causa dependencia dos
  modulos.
- Neste ponto esgotam-se as possibilidades da modularizacao
  baseada em procedimentos e funcoes.

Autor: Andre Santanche
Data:  01/03/2011
*/

#include <stdio.h>

int combinacoes;

void inicializa(int *combinacoes)
{
    *combinacoes = 1;
}

int proximoNumeroCombinacoes(int *combinacoes)
{
    *combinacoes *= 2;
    return *combinacoes;
}

int main()
{
    int bits;

    inicializa(&combinacoes);

    for (bits = 1; bits <= 8; bits++)
        printf("%d bits = %d combinacoes\n", bits, proximoNumeroCombinacoes(&combinacoes));
}
