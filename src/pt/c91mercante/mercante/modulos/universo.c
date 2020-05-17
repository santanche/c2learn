#include <string.h>

#include "planeta.h"
#include "status.h"
#include "robo.h"

int registro(char* nomePlaneta, char* chavePrivada) {
   char complemento[100] = "registro ";

   int novoPlaneta = adicionaPlaneta(nomePlaneta);
   strcat(complemento, nomePlaneta);

   monitorStatus(STATUS_SUCESSO, complemento);

   return novoPlaneta;
}
