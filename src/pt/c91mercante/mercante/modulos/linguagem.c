#include "linguagem.h"

static char *instrucoes[TOTAL_INSTRUCOES] = {
   "viaja",
   "indica",
   "compra",
   "vende",
   "saca",
   "conecta",
   "desconecta"
};

char** getInstrucoes() {
   return instrucoes;
}
