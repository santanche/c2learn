#define TOTAL_INSTRUCOES 7

typedef enum {
   instrDesconhecida = -1,
   instrViaja,
   instrIndica,
   instrCompra,
   instrVende,
   instrSaca,
   instrConecta,
   instrDesconecta
} TipoInstrucao;

char** getInstrucoes();
