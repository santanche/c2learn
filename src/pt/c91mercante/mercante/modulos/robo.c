#include <stdio.h>
#include <string.h>

#include "planeta.h"
#include "caixa.h"
#include "mercadoria.h"
#include "nave.h"
#include "robo.h"
#include "status.h"
#include "linguagem.h"
#include "ator.h"

static int estadoMonitor = monitorInativo;
static int planetaCorrente = plaMantor;

/** Registra uma conexão a um planeta externo. -1 quer dizer que não está conectado a ninguém. */
static int conectado = -1;

int getEstadoMonitor() {
   return estadoMonitor;
}

int setEstadoMonitor(TipoMonitor estado) {
   int status = STATUS_SUCESSO;
   if (estado < monitorInativo || estado > monitorAtivoCompleto)
      status = STATUS_ESTADO_INVALIDO;
   else
      estadoMonitor = estado;
   return status;
}

void monitorStatus(int status, char *complemento) {
   if (getEstadoMonitor() == monitorAtivoBreve)
      mostraStatusBreve(status, complemento);
}

int getPlanetaCorrente() {
   return planetaCorrente;
}

int viaja(TipoPlaneta destino) {
   int status = STATUS_SUCESSO;
   char complemento[50] = "viagem ";

   if (destino == planetaCorrente)
      status = STATUS_DESTINO_ORIGEM;
   if (destino < 0 || destino >= getNumeroPlanetas())
      status = STATUS_PLANETA_INEXISTENTE;
   else {
      status = debitaCaixa(getPrecoPassagem());
      if (status == STATUS_SUCESSO)
         planetaCorrente = destino;
      strcat(complemento, getNomePlaneta(destino));
   }
   monitorStatus(status, complemento);
   return status;
}

void iViaja() {
   int nPlaneta;
   puts("\n>>>>>>>>>>");
   printf("> planeta destino: ");
   scanf("%d", &nPlaneta);

   int status = viaja(nPlaneta);
   if (status == STATUS_SUCESSO)
      puts("> Viagem realizada com sucesso.");
   else if (status == STATUS_SALDO_INSUFICIENTE)
      puts("> Voce nao tem dinheiro suficiente para viajar.");
   else if (status == STATUS_PLANETA_INEXISTENTE)
      puts("> O planeta destino escolhido nao existe.");
   else if (status == STATUS_DESTINO_ORIGEM)
      puts("> Planeta destino igual ao de origem.");

   puts(">>>>>>>>>>");
}

void iGetMercadoriasPlaneta() {
   puts("\n+---------------------------------+");
   puts(  "|          [MERCADORIAS]          |");
   puts(  "| nn | mercadoria | preco | quant |");
   puts(  "|----|------------|-------|-------|");

   char** nomeMercadorias = getNomeMercadorias();
   RegPlaneta* dadosPlanetas = getDadosPlanetas();

   int m;
   for (m = 0; m < dadosPlanetas[planetaCorrente].numeroMercadorias; m++)
      printf("| %2d | %-10s | %5d | %5d |\n",
             m, nomeMercadorias[m],
             dadosPlanetas[planetaCorrente].mercadorias[m].preco,
             dadosPlanetas[planetaCorrente].mercadorias[m].disponivel);

   puts("+---------------------------------+");
}

int compraMercadoria(int quantidade) {
   int status = STATUS_SUCESSO;
   char complemento[50] = "";

   TipoMercadoria mercadoriaIndicada = getMercadoriaIndicada();
   if (mercadoriaIndicada == merNada)
      status = STATUS_MERCADORIA_INEXISTENTE;
   else {
      int planetaCorrente = getPlanetaCorrente();
      RegPlaneta *dadosPlaneta = getDadosPlanetas();

      // procura mercadoria indicada no planeta
      int m;
      for (m = 0; m < dadosPlaneta[planetaCorrente].numeroMercadorias &&
                  dadosPlaneta[planetaCorrente].mercadorias[m].mercadoria != mercadoriaIndicada; m++)
         /* nada */ ;

      if (m >= dadosPlaneta[planetaCorrente].numeroMercadorias)
         status = STATUS_MERCADORIA_INEXISTENTE;
      else {
         RegMercadoriaPlaneta dadosIndicada =
            dadosPlaneta[planetaCorrente].mercadorias[m];

         // verifica se há saldo e executa compra
         int gasto = quantidade * dadosIndicada.preco;
         if (quantidade <= dadosIndicada.disponivel &&
             gasto <= getSaldoCaixa()) {
            debitaCaixa(gasto);
            ocupaCelula(mercadoriaIndicada, quantidade);
            dadosPlaneta[planetaCorrente].mercadorias[m].disponivel -= quantidade;
            sprintf(complemento, "compra %s %d", getNomeMercadoria(mercadoriaIndicada),
                    quantidade);
         } else
            status = STATUS_SALDO_INSUFICIENTE;
      }
   }

   monitorStatus(status, complemento);
   return status;
}

void iCompraMercadoria() {
   int quantidade;
   puts("\n>>>>>>>>>>");
   printf("> quantidade: ");
   scanf("%d", &quantidade);

   int status = compraMercadoria(quantidade);
   if (status == STATUS_SUCESSO)
      puts("> Compra realizada com sucesso.");
   else if (status == STATUS_MERCADORIA_INEXISTENTE)
      puts("> Nao foi indicada mercadoria.");
   else if (status == STATUS_SALDO_INSUFICIENTE)
      puts("> Voce nao tem dinheiro suficiente para comprar.");

   puts(">>>>>>>>>>");
}

int vendeMercadoria(int quantidade) {
   int status = STATUS_SUCESSO;
   char complemento[50] = "";

   TipoMercadoria mercadoriaIndicada = getMercadoriaIndicada();
   if (mercadoriaIndicada == merNada)
      status = STATUS_MERCADORIA_INEXISTENTE;
   else {
      int planetaCorrente = getPlanetaCorrente();
      RegPlaneta *dadosPlaneta = getDadosPlanetas();

      // procura mercadoria indicada no planeta
      int m;
      for (m = 0; m < dadosPlaneta[planetaCorrente].numeroMercadorias &&
                  dadosPlaneta[planetaCorrente].mercadorias[m].mercadoria != mercadoriaIndicada; m++)
         /* nada */ ;

      // executa venda se houver quantidade disponível na nave
      status = desocupaCelula(mercadoriaIndicada, quantidade);
      if (status == STATUS_SUCESSO) {
         // se mercadoria não existe no planeta acrescenta (com preço sorteado)
         if (m >= dadosPlaneta[planetaCorrente].numeroMercadorias)
            status = acrescentaMercadoriaPlaneta(planetaCorrente, mercadoriaIndicada, -1, 0);

         // processo de venda
         if (status == STATUS_SUCESSO) {
            creditaCaixa(quantidade * dadosPlaneta[planetaCorrente].mercadorias[m].preco);
            dadosPlaneta[planetaCorrente].mercadorias[m].disponivel += quantidade;
            sprintf(complemento, "vende %s %d", getNomeMercadoria(mercadoriaIndicada),
                    quantidade);
         }
      }
   }

   monitorStatus(status, complemento);
   return status;
}

void iVendeMercadoria() {
   int quantidade;
   puts("\n>>>>>>>>>>");
   printf("> quantidade: ");
   scanf("%d", &quantidade);

   int status = vendeMercadoria(quantidade);
   if (status == STATUS_SUCESSO)
      puts("> Venda realizada com sucesso.");
   else if (status == STATUS_MERCADORIA_INEXISTENTE)
      puts("> Nao foi indicada mercadoria.");
   else if (status == STATUS_MERCADORIA_INSUFICIENTE)
      puts("> Voce nao tem mercadoria suficiente para vender.");

   puts(">>>>>>>>>>");
}

void executaInstrucao(char* strInstrucao, int codInstrucao,
                      char *paramStr, int paramInt) {

   if (estadoMonitor != monitorInativo)
       printf("{%s,%d,%s,%d} ", strInstrucao, codInstrucao,
                                paramStr, paramInt);

   int valorSacado;
   switch (codInstrucao) {
      case instrViaja: viaja(paramInt); break;
      case instrIndica: indicaMercadoria(paramInt); break;
      case instrCompra: compraMercadoria(paramInt); break;
      case instrVende: vendeMercadoria(paramInt); break;
      case instrSaca: saca(paramInt); break;
      case instrConecta : conectado = paramInt; break;
      case instrDesconecta : conectado = -1; break;
      default:
         valorSacado = getValorSacado();
         creditaPlanetaCorrente();
         instrucaoPlaneta(strInstrucao, paramStr,
                          paramInt, valorSacado);
   }
}

int instrucaoPlaneta(char* strInstrucao,
                     char *paramStr, int paramInt, int valor) {
   int status = STATUS_SUCESSO;

   int planetaInstrucao = ((conectado == -1) ? getPlanetaCorrente() : conectado);
   char* nomePlanetaInstrucao = getNomePlaneta(planetaInstrucao);

   // Desvio de instrucoes para planetas. Acrescente seu planeta aqui.
   if (strcmp(nomePlanetaInstrucao, "Asdrubal") == 0)
      ativaAsdrubal(strInstrucao, paramStr,
                    paramInt, valor);

   return status;
}
