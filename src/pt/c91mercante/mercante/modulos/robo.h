typedef enum {
   monitorInativo,
   monitorAtivoBreve,
   monitorAtivoCompleto
} TipoMonitor;

int getEstadoMonitor();
int setEstadoMonitor(TipoMonitor estado);
void monitorStatus(int status, char *complemento);
int getPlanetaCorrente();
int viaja(TipoPlaneta destino);
void iViaja();
void iGetMercadoriasPlaneta();
int compraMercadoria(int quantidade);
void iCompraMercadoria();
int vendeMercadoria(int quantidade);
void iVendeMercadoria();

void executaInstrucao(char* strInstrucao, int codInstrucao,
                      char *paramStr, int paramInt);
int instrucaoPlaneta(char* strInstrucao,
                     char *paramStr, int paramInt, int valor);
