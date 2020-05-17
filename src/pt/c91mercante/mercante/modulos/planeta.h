#define TOTAL_INICIAL_PLANETAS 12
#define TOTAL_MAXIMO_PLANETAS 100
#define PRECO_INICIAL_PASSAGEM  5

typedef enum {
   plaNada = -1,
   plaMantor,
   plaZintor,
   plaAsdropolis,
   plaZeta,
   plaBantor,
   plaTander,
   plaNova,
   plaPindora,
   plaCastor,
   plaRa,
   plaRe,
   plaRi
} TipoPlaneta;

/**
Mantém dados (preço e quantidade) de uma mercadoria em um planeta.
*/
typedef struct {
   int mercadoria,
       preco,
       disponivel;
} RegMercadoriaPlaneta;

/**
Mantém dados de todas as mercadorias disponíveis para venda em um planeta.
*/
typedef struct {
   int numeroMercadorias;
   RegMercadoriaPlaneta *mercadorias;
} RegPlaneta;

int getNumeroPlanetas();
char** getNomePlanetas();
char* getNomePlaneta(TipoPlaneta planeta);
void iGetNomePlanetas();
RegPlaneta* getDadosPlanetas();

void inicializaPlanetas();
RegMercadoriaPlaneta* precosPlaneta();
RegMercadoriaPlaneta calculaPrecosQuantidades(int mercadoria);

int acrescentaMercadoriaPlaneta(int planeta, int mercadoria,
                                int preco, int disponivel);

int adicionaPlaneta(char *nomePlaneta);
void setPrecoPassagem(int preco);
int getPrecoPassagem();
