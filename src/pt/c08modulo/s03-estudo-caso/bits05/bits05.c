/*
Serie de Programas: Modularizacao progressiva
Mostra etapas sucessivas do processo de modularizacao, ate se
chegar ao componente de software.

Exemplo:
Programa que calcula e apresenta o numero de combinacoes possiveis
que podem ser realizadas com bits, que variam de 1 a 8.

Quinta versao:
Os modulos menores (procedure e function) sao colocados dentro de
um modulo maior (unit).

Vantagens:
- A unit expoe apenas as interfaces das procedures e functions,
  escondendo detalhes da implementacao.
- A unit controla e mantem o estado da variavel "combinacoes",
  que nao e visivel para o programa principal.

Problemas:
- Esta unit funciona para apenas uma instancia. Se precisassemos
  de dois calculos de combinacoes em paralelo teriamos problemas.
- O uso de multiplas instancias e possivel mas complicado.

Autor: Andre Santanche
Data:  01/03/2011
*/

#include <stdio.h>
#include "bits05module.h"

int main()
{
    int bits;

    inicializa();

    for (bits = 1; bits <= 8; bits++)
        printf("%d bits = %d combinacoes\n",
               bits, proximoNumeroCombinacoes());

    return 0;
}
