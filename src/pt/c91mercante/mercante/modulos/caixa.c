#include <string.h>
#include <stdio.h>

#include "status.h"
#include "planeta.h"
#include "robo.h"

static int saldoCaixa = 30000;
static int valorSacado = 0;

int getSaldoCaixa() {
   return saldoCaixa;
}

int debitaCaixa(int valor) {
   int status = STATUS_SUCESSO;
   if (valor < 0)
      status = STATUS_VALOR_INVALIDO;
   else if (saldoCaixa < valor)
      status = STATUS_SALDO_INSUFICIENTE;
   else
      saldoCaixa -= valor;
   return status;
}

int creditaCaixa(int valor) {
   int status = STATUS_SUCESSO;
   if (valor < 0)
      status = STATUS_VALOR_INVALIDO;
   else
      saldoCaixa += valor;
   return status;
}

int saca(int valor) {
   int status = STATUS_SUCESSO;
   char complemento[12] = "saca ";
   char strValor[6];

   if (valor > saldoCaixa)
      status = STATUS_SALDO_INSUFICIENTE;
   else if (valor <= saldoCaixa) {
      valorSacado = valor;
      saldoCaixa -= valor;
      sprintf(strValor, "%d", valor);
      strcat(complemento, strValor);
   }

   monitorStatus(status, complemento);
   return status;
}

int getValorSacado() {
   return valorSacado;
}

/* Credita valor do ultimo saque para o planeta corrente */
int creditaPlanetaCorrente() {
   int status = STATUS_SUCESSO;

   if (valorSacado > 0) {
       char complemento[50];
       sprintf(complemento, "creditado %d para %s",
               valorSacado, getNomePlaneta(getPlanetaCorrente()));
       valorSacado = 0;

       monitorStatus(status, complemento);
   }

   return status;
}
