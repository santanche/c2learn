#define TOTAL_INICIAL_MERCADORIAS 5
#define TOTAL_MAXIMO_MERCADORIAS 100

typedef enum {
   merNada = -1,
   merCabeca,
   merCorpo,
   merBraco,
   merPerna,
   merRobo
} TipoMercadoria;

typedef struct {
   int  basePreco,
        variacaoPreco,
        baseDisponivel,
        variacaoDisponivel;
} RegMercadoria;

int getNumeroMercadorias();
char** getNomeMercadorias();
char* getNomeMercadoria(TipoMercadoria mercadoria);
RegMercadoria* getDadosMercadorias();
int indicaMercadoria(TipoMercadoria mercadoria);
void iIndicaMercadoria();
TipoMercadoria getMercadoriaIndicada();
char *getNomeMercadoriaIndicada();
int adicionaMercadoria(char *nomeMercadoria,
                       int basePreco, int variacaoPreco,
                       int baseDisponivel, int variacaoDisponivel);
