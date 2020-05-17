#include <stdio.h>

#include "planeta.h"
#include "mercadoria.h"
#include "caixa.h"
#include "nave.h"
#include "robo.h"
#include "interface.h"

#include "ator.h"

int mainMenu() {
   int opcao;

   showEstado();

   puts("1. Relacao de planetas");
   puts("2. Viajar");
   puts("3. Mercadorias no planeta");
   puts("4. Indicar mercadoria");
   puts("5. Comprar mercadoria");
   puts("6. Vender mercadoria");
   puts("9. Ativa programa");
   puts("0. Sair");

   printf("Digite sua opcao: ");
   scanf("%d", &opcao);

   ativaOpcao(opcao);

   return opcao;
}

void showEstado() {
   puts("\n#==================================#");
   printf("# planeta: %-23s #\n", getNomePlaneta(getPlanetaCorrente()));
   printf("# caixa:   %-23d #\n", getSaldoCaixa());

   if (getMercadoriaIndicada() != merNada)
      printf("# mercadoria indicada: %-10s  #\n",
             getNomeMercadoriaIndicada());

   printf("# celulas livres: %-15d  #\n", getCelulasLivres());
   printf("# capacidade livre: %-13d  #\n",
          getCapacidadeNave() - getQuantidadeOcupada());

   int ocupadas = getCelulasOcupadas();
   if (ocupadas > 0) {
      puts("# ocupacao da nave:                #");
      puts("# | mercadoria | quant |           #");
      puts("# +------------+-------+           #");
   }

   RegCelula* celula = getCelulas();
   char** nomeMercadorias = getNomeMercadorias();
   int c;
   for (c = 0; c < ocupadas; c++)
     printf("# | %-10s | %5d |           #\n",
            nomeMercadorias[celula[c].mercadoria],
            celula[c].quantidade);

   puts(  "#==================================#\n");
}

void ativaOpcao(int opcao) {
    switch (opcao) {
       case 0  : break;
       case 1  : iGetNomePlanetas(); break;
       case 2  : iViaja(); break;
       case 3  : iGetMercadoriasPlaneta(); break;
       case 4  : iIndicaMercadoria(); break;
       case 5  : iCompraMercadoria(); break;
       case 6  : iVendeMercadoria(); break;
       case 9  : iPrograma(); break;
       default : puts("\n>>>>>>>>>>");
                 puts(  "> Opcao invalida.");
                 puts(  ">>>>>>>>>>");
    }
}

void iPrograma() {
   setEstadoMonitor(monitorAtivoBreve);
   puts("\n____________[Monitor]____________");
   programa();
   puts("\n_________________________________\n");
   setEstadoMonitor(monitorInativo);
}
