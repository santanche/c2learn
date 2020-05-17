#include "planeta.h"
#include "mercadoria.h"
#include "nave.h"
#include "interface.h"

#include "ator.h"

int main() {
   inicializaPlanetas();
   inicializaNave();

   int opcao = 0;
   do {
      opcao = mainMenu();
   } while (opcao != 0);

   return 0;
}
