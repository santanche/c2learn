#include "mercadoria.h"
#include "nave.h"
#include "status.h"

static RegCelula celula[CELULAS_INICIAIS_NAVE];
static int celulasNave = CELULAS_INICIAIS_NAVE;
static int celulasOcupadas = 0;
static int capacidadeNave = CAPACIDADE_INICIAL_NAVE;
static int quantidadeOcupada = 0;

void inicializaNave() {
   int c;
   for (c = 0; c < CELULAS_INICIAIS_NAVE; c++) {
      celula[c].mercadoria = -1;
      celula[c].quantidade = 0;
   }
}

int getCelulasOcupadas() {
   return celulasOcupadas;
}

int getCelulasLivres() {
   return celulasNave - celulasOcupadas;
}

RegCelula* getCelulas() {
   return celula;
}

int ocupaCelula(TipoMercadoria mercadoria, int quantidade) {
   int status = STATUS_SUCESSO;
   if (quantidadeOcupada + quantidade > capacidadeNave)
      status = STATUS_NAVE_CHEIA;
   else if (mercadoria <= merNada || mercadoria >= getNumeroMercadorias())
      status = STATUS_MERCADORIA_INEXISTENTE;
   else {
      int c;
      for (c = 0; c < celulasOcupadas && celula[c].mercadoria != mercadoria; c++)
         /* nada */ ;

      if (c >= celulasOcupadas && celulasOcupadas >= celulasNave)
         status = STATUS_NAVE_CHEIA;
      else {
         if (c == celulasOcupadas)
            celulasOcupadas++;
         quantidadeOcupada += quantidade;
         celula[c].mercadoria = mercadoria;
         celula[c].quantidade += quantidade;
      }
   }

   return status;
}

int desocupaCelula(TipoMercadoria mercadoria, int quantidade) {
   int status = STATUS_SUCESSO;
   if (mercadoria <= merNada && mercadoria >= getNumeroMercadorias())
      status = STATUS_MERCADORIA_INEXISTENTE;
   else {
      int c;
      for (c = 0; c < celulasOcupadas && celula[c].mercadoria != mercadoria; c++)
         /* nada */ ;

      if (c >= celulasOcupadas)
         status = STATUS_MERCADORIA_INEXISTENTE;
      else if (celula[c].quantidade < quantidade)
         status = STATUS_MERCADORIA_INSUFICIENTE;
      else {
         quantidadeOcupada -= quantidade;
         celula[c].quantidade -= quantidade;

         if (celula[c].quantidade == 0) {
            int e;
            for (e = c; e < celulasOcupadas-1; e++)
               celula[e] = celula[e+1];
            celula[celulasOcupadas-1].mercadoria = 0;
            celula[celulasOcupadas-1].quantidade = 0;
            celulasOcupadas--;
         }
      }
   }

   return status;
}

int mercadoriaNaNave() {
   int m = 0;
   int mercadoriaIndicada = getMercadoriaIndicada();
   if (mercadoriaIndicada > merNada) {
      int c;
      for (c = 0; c < celulasOcupadas && celula[c].mercadoria != mercadoriaIndicada; c++)
         /* nada */ ;
      if (c < celulasOcupadas)
         m = celula[c].quantidade;
   }
   return m;
}

void setCapacidadeNave(int capacidade) {
   capacidadeNave = capacidade;
}

int getCapacidadeNave() {
   return capacidadeNave;
}

int getQuantidadeOcupada() {
   return quantidadeOcupada;
}
