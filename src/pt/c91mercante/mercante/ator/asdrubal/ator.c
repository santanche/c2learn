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
#include "testes.h"

#include "ator.h"

static char cadastrados[50][60];

void programa() {
   /** Programa de exemplo, deve ser substituido pelo trabalho **/

   int planetaAsdrubal = registro("Asdrubal", 0);

   // adicionando uma nova mercadoria
   int novaMercadoria = adicionaMercadoria("carro", 500, 50, 10, 3);

   // tornando a mercadoria disponível em dois planetas
   acrescentaMercadoriaPlaneta(plaBantor, novaMercadoria, -1, -1);
   acrescentaMercadoriaPlaneta(plaAsdropolis, novaMercadoria, 150, 5);

   // enviando uma instrução nova para a planeta corrente
   executaInstrucao("desconhecida", instrDesconhecida, "nada", 0);

   // conectando com outro planeta e mandando a instrucao nova
   executaInstrucao("conecta", instrConecta, "Asdrubal", planetaAsdrubal);
   executaInstrucao("desconhecida", instrDesconhecida, "nada", 0);
   executaInstrucao("desconecta", instrDesconecta, "nada", 0);
}

int ativaAsdrubal(char* strInstrucao,
              char *paramStr, int paramInt, int valor) {
   int status = STATUS_SUCESSO;

   printf("\nRecebi a instrucao: %s, %s, %d, %d\n", strInstrucao, paramStr, paramInt, valor);

   return status;
}

