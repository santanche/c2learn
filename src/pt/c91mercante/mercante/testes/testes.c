#include <stdio.h>
#include <string.h>

#include "testes.h"

static int acertos = 0;
static int erros = 0;

void iniciaTestes() {
   acertos = 0;
   erros = 0;
}

void testeChar(char valorTeste, char valorReferencia) {
   if (valorTeste == valorReferencia)
      acertos++;
   else
      erros++;
}

void testeInt(int valorTeste, int valorReferencia) {
   if (valorTeste == valorReferencia)
      acertos++;
   else
      erros++;
}

void testeLong(long valorTeste, long valorReferencia) {
   if (valorTeste == valorReferencia)
      acertos++;
   else
      erros++;
}

void testeFloat(float valorTeste, float valorReferencia) {
   if (valorTeste == valorReferencia)
      acertos++;
   else
      erros++;
}

void testeDouble(double valorTeste, double valorReferencia) {
   if (valorTeste == valorReferencia)
      acertos++;
   else
      erros++;
}

void testeStr(char *valorTeste, char *valorReferencia) {
   if (strcmp(valorTeste, valorReferencia) == 0)
      acertos++;
   else
      erros++;
}

void relatorioTestes() {
   printf("\n[[testes - total: %d; acertos: %d; erros: %d]]", (acertos+erros), acertos, erros);
}
