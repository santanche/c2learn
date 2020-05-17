/*
Serie de Programas: Modularizacao progressiva

Modulo usado pelo programa bits05.c
*/

#include "bits05module.h"

static int combinacoes;

void inicializa()
{
    combinacoes = 1;
}

int proximoNumeroCombinacoes()
{
    combinacoes *= 2;
    return combinacoes;
}
