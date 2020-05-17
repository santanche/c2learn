#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "status.h"
#include "mercadoria.h"

static char* nomeMercadorias[TOTAL_MAXIMO_MERCADORIAS] = {
   "cabeca",
   "corpo",
   "braco",
   "perna",
   "robo"
};

static RegMercadoria dadosMercadorias[TOTAL_MAXIMO_MERCADORIAS] = {
   {50, 30, 7, 5},
   {80, 20, 12, 8},
   {30, 15, 15, 10},
   {40, 15, 12, 8},
   {450, 100, 5, 3}
};

static TipoMercadoria mercadoriaIndicada = merNada;

static int numeroMercadorias = TOTAL_INICIAL_MERCADORIAS;

int getNumeroMercadorias() {
   return numeroMercadorias;
}

char** getNomeMercadorias() {
   return nomeMercadorias;
}

char* getNomeMercadoria(TipoMercadoria mercadoria) {
   char *nMercadoria = "Desconhecida";
   if (mercadoria >= 0 || mercadoria < numeroMercadorias)
      nMercadoria = nomeMercadorias[mercadoria];
   return nMercadoria;
}

RegMercadoria* getDadosMercadorias() {
   return dadosMercadorias;
}

int indicaMercadoria(TipoMercadoria mercadoria) {
   int status = STATUS_SUCESSO;
   if (mercadoria <= merNada || mercadoria >= numeroMercadorias)
      status = STATUS_MERCADORIA_INEXISTENTE;
   else
      mercadoriaIndicada = mercadoria;
   return status;
}

void iIndicaMercadoria() {
   int nMercadoria;
   puts("\n>>>>>>>>>>");
   printf("> mercadoria a indicar: ");
   scanf("%d", &nMercadoria);

   int status = indicaMercadoria(nMercadoria);
   if (status == STATUS_SUCESSO)
      puts("> Mercadoria indicada com sucesso.");
   else if (status == STATUS_MERCADORIA_INEXISTENTE)
      puts("> A mercadoria indicada nao existe.");

   puts(">>>>>>>>>>");
}

TipoMercadoria getMercadoriaIndicada() {
   return mercadoriaIndicada;
}

char* getNomeMercadoriaIndicada() {
   if (mercadoriaIndicada != merNada)
      return nomeMercadorias[mercadoriaIndicada];
   else
      return "";
}

int adicionaMercadoria(char *nomeMercadoria,
                        int basePreco, int variacaoPreco,
                        int baseDisponivel, int variacaoDisponivel) {
   char* nm = malloc(strlen(nomeMercadoria) + 1);
   strcpy(nm, nomeMercadoria);
   nomeMercadorias[numeroMercadorias] = nm;
   dadosMercadorias[numeroMercadorias].basePreco = basePreco;
   dadosMercadorias[numeroMercadorias].variacaoPreco = variacaoPreco;
   dadosMercadorias[numeroMercadorias].baseDisponivel = baseDisponivel;
   dadosMercadorias[numeroMercadorias].variacaoDisponivel = variacaoDisponivel;
   numeroMercadorias++;

   return numeroMercadorias - 1;
}
