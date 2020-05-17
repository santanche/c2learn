#include <stdio.h>
#include <string.h>

#include "planeta.h"
#include "robo.h"
#include "status.h"

static char* mensagemStatus[TOTAL_STATUS] = {
   "status inexistente",
   "sucesso",
   "falha",
   "saldo insuficiente",
   "valor invalido",
   "planeta inexistente",
   "destino igual a origem",
   "mercadoria inexistente",
   "nave cheia",
   "mercadoria insuficiente",
   "estado invalido"
};

void mostraStatusBreve(int status, char *complemento) {
   int s = (status >= 0 && status < TOTAL_STATUS) ? status : STATUS_INEXISTENTE;
   char *m = (status == STATUS_SUCESSO && complemento != NULL) ? complemento : mensagemStatus[s];
   printf("[%s] ", m);
}



