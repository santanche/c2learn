#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "universo.h"
#include "caixa.h"
#include "mercadoria.h"
#include "planeta.h"
#include "robo.h"
#include "linguagem.h"
#include "status.h"

#include "asdrubal/ator.h"

static char cadastrados[50][60];

void programa() {
   /** Programa de exemplo, deve ser substituido pelo trabalho **/

   registro("Ator01", 0);

   executaInstrucao("viaja", instrViaja, "Ator01", getNumeroPlanetas()-1);

   executaInstrucao("saca", instrSaca, "150", 150);

   executaInstrucao("quadrado", instrDesconhecida, "5", 5);

   executaInstrucao("cadastra", instrDesconhecida, "quincas", 0);

   executaInstrucao("saca", instrSaca, "300", 300);

   executaInstrucao("aposta", instrDesconhecida, "quincas", 0);
}

int ativaAtor(char* strInstrucao,
              char *paramStr, int paramInt, int valor) {
   int status = STATUS_SUCESSO;

   int q = 0;
   if (strcmp(strInstrucao, "quadrado") == 0) {
      q = quadrado(paramInt);
      // printf("Quadrado: %d", q);
   }

   int st;
   if (strcmp(strInstrucao, "cadastra") == 0)
      st = cadastra(paramStr);
   if (strcmp(strInstrucao, "aposta") == 0) {
      st = aposta(paramStr, valor);
      // printf("%d", st);
   }

   return status;
}

int quadrado(int numero) {
   return numero * numero;
}

int cadastra(char *nome) {
   strcpy(cadastrados[0], nome);
   printf("cadastrei: %s", cadastrados[0]);
   return STATUS_SUCESSO;
}

int aposta(char *nome, int valor) {
   int status = STATUS_SUCESSO;

   if (strcmp(nome, cadastrados[0]) != 0 ||
       valor <= 0)
      status = STATUS_FALHA;

   return status;
}
