#define CAPACIDADE_INICIAL_NAVE 100
#define CELULAS_INICIAIS_NAVE 50

typedef struct {
   int mercadoria,
       quantidade;
} RegCelula;

void inicializaNave();
int getCelulasOcupadas();
int getCelulasLivres();
RegCelula* getCelulas();
int ocupaCelula(TipoMercadoria mercadoria, int quantidade);
int desocupaCelula(TipoMercadoria mercadoria, int quantidade);
int mercadoriaNaNave();
void setCapacidadeNave(int capacidade);
int getCapacidadeNave();
int getQuantidadeOcupada();
