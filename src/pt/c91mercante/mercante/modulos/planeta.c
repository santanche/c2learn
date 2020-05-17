#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "status.h"
#include "planeta.h"
#include "caixa.h"
#include "mercadoria.h"

/** Nome dos planetas */
static char* nomePlanetas[TOTAL_MAXIMO_PLANETAS] = {
   "Mantor",
   "Zintor",
   "Asdropolis",
   "Zeta",
   "Bantor",
   "Tander",
   "Nova",
   "Pindora",
   "Castor",
   "Ra",
   "Re",
   "Ri"
};

/** Registra mercadorias e precos no planeta */
static RegPlaneta dadosPlanetas[TOTAL_MAXIMO_PLANETAS];

/** Numero total de planetas existentes */
static int numeroPlanetas = TOTAL_INICIAL_PLANETAS;

/** Preco para viajar de um planeta a outro */
static int precoPassagem = PRECO_INICIAL_PASSAGEM;

/** Retorna o número de planetas disponíveis. */
int getNumeroPlanetas() {
   return numeroPlanetas;
}

/** Retorna um vetor de strings com o nome de todos os planetas. */
char** getNomePlanetas() {
   return nomePlanetas;
}

/** Retorna o nome do planeta indicado como parâmetro. */
char* getNomePlaneta(TipoPlaneta planeta) {
   char *nPlaneta = "Desconhecido";
   if (planeta >= 0 || planeta < numeroPlanetas)
      nPlaneta = nomePlanetas[planeta];
   return nPlaneta;
}

/** Mostra na interface o nome dos planetas. */
void iGetNomePlanetas() {
   puts("\n+-----------------+");
   puts(  "|   [PLANETAS]    |");
   puts(  "| nn | planeta    |");
   puts(  "+----+------------+");
   int p;
   for (p = 0; p < numeroPlanetas; p++)
      printf("| %2d | %-10s |\n", p, nomePlanetas[p]);
   puts(  "+-----------------+");
}

/** Retorna dados de todos os planetas.
    Os dados do planeta incluem a relação de mercadorias no planeta, com os dados de preços. */
RegPlaneta* getDadosPlanetas() {
   return dadosPlanetas;
}

/** Inicializa dados dos planetas, atribuindo preços e quantidades às mercadorias. */
void inicializaPlanetas() {
   srand (time(NULL));

   int p;
   for (p = 0; p < numeroPlanetas; p++) {
      dadosPlanetas[p].numeroMercadorias = getNumeroMercadorias();
      dadosPlanetas[p].mercadorias = precosPlaneta();
   }
}

/**
Sorteia valores e quantidades de mercadorias a ser usado para um planeta.
O numero de mercadorias sorteado é o número de mercadorias que existem no
monento que a função é chamada.
Esta função é usada por inicializaPlanetas().
*/
RegMercadoriaPlaneta* precosPlaneta() {
   RegMercadoriaPlaneta* mercadorias =
      malloc(sizeof(RegMercadoriaPlaneta) * getNumeroMercadorias());
   int m;

   // sorteia precos e quantidades a partir de base e variacao
   for (m = 0; m < getNumeroMercadorias(); m++)
      mercadorias[m] = calculaPrecosQuantidades(m);

   return mercadorias;
}

/** Calcula preços e quantidades de uma mercadoria a ser usada em um planeta.
    Esta função é usada por precosPlaneta(). */
RegMercadoriaPlaneta calculaPrecosQuantidades(int mercadoria) {
   RegMercadoria *dadosMercadorias = getDadosMercadorias();

   RegMercadoriaPlaneta rmp;
   rmp.mercadoria = mercadoria;

   // calcula preco: base + variacao (sorteada)
   rmp.preco =
      dadosMercadorias[mercadoria].basePreco +
      (rand() % dadosMercadorias[mercadoria].variacaoPreco);

   // calcula quantidade: base + variacao (sorteada)
   rmp.disponivel =
      dadosMercadorias[mercadoria].baseDisponivel +
      (rand() % dadosMercadorias[mercadoria].variacaoDisponivel);

   return rmp;
}

/**
Acrescenta uma mercadoria nova para ser vendida em um planeta.
O valor e a quantidade da mercadoria são sorteados a partir dos valores de base e variação.

@param preco indica o preço de venda da mercadoria; se for -1 a função sorteia o valor.
@param disponivel indica a quantidade da mercadoria disponível; se for -1 a função sorteia o valor.
*/
int acrescentaMercadoriaPlaneta(int planeta, int mercadoria,
                                int preco, int disponivel) {
   RegMercadoria *dadosMercadorias = getDadosMercadorias();

   int status = STATUS_SUCESSO;

   if (planeta <= plaNada || planeta >= getNumeroPlanetas())
      status = STATUS_PLANETA_INEXISTENTE;
   else {
      printf("Calculando precos para %d mercadoria %d\n", planeta, mercadoria);

      // cria novo vetor (maior) de mercadorias e copia dados do antigo para ele
      RegMercadoriaPlaneta* novasMercadorias =
         malloc(sizeof(RegMercadoriaPlaneta) * (dadosPlanetas[planeta].numeroMercadorias + 1));
      int m;
      for (m = 0; m < dadosPlanetas[planeta].numeroMercadorias; m++)
         novasMercadorias[m] = dadosPlanetas[planeta].mercadorias[m];

      // libera vetor antigo e substitui pelo novo
      free(dadosPlanetas[planeta].mercadorias);
      dadosPlanetas[planeta].mercadorias = novasMercadorias;

      // acrescenta nova mercadoria com valor sorteado
      int novaMercadoria = dadosPlanetas[planeta].numeroMercadorias;
      RegMercadoriaPlaneta *mPlaneta = dadosPlanetas[planeta].mercadorias;
      mPlaneta[novaMercadoria] = calculaPrecosQuantidades(mercadoria);
      if (preco >= 0)
         mPlaneta[novaMercadoria].preco = preco;
      if (disponivel >= 0)
         mPlaneta[novaMercadoria].disponivel = disponivel;
      dadosPlanetas[planeta].numeroMercadorias++;
   }

   return status;
}

/**
Adiciona um novo planeta no conjunto de planetas e sorteia precos e
quantidades de mercadoria para o novo planeta.

@return código numérico do novo planeta.
*/
int adicionaPlaneta(char *nomePlaneta) {
   char* np = malloc(strlen(nomePlaneta) + 1);
   strcpy(np, nomePlaneta);
   nomePlanetas[numeroPlanetas] = np;
   dadosPlanetas[numeroPlanetas].numeroMercadorias = getNumeroMercadorias();
   dadosPlanetas[numeroPlanetas].mercadorias = precosPlaneta();
   numeroPlanetas++;

   return numeroPlanetas - 1;
}

/** Altera o preço da passagem para viagem entre planetas. */
void setPrecoPassagem(int preco) {
   precoPassagem = preco;
}

/** Retorna o preço da passagem para viagem entre planetas. */
int getPrecoPassagem() {
   return precoPassagem;
}
