#include <stdio.h>

#define MAXIMO 50

typedef struct {
   int coeficiente,
       expoente;
} TipoTermo;

TipoTermo* inicializa(int coeficiente,
                      int expoente)
{
   TipoTermo *poli =
      (TipoTermo*)malloc(sizeof(TipoTermo) * MAXIMO);

   poli[0].coeficiente = coeficiente;
   poli[0].expoente = expoente;

   return poli;
}

void termo(TipoTermo *poli, int *tamanho,
           int coeficiente, int expoente) {
   int e;
   for (e = 0; e < (*tamanho) &&
               expoente != poli[e].expoente; e++)
      /* nada */ ;

   if (e < (*tamanho))
      poli[e].coeficiente += coeficiente;
   else {
      if ((*tamanho) < MAXIMO) {
         poli[(*tamanho)].coeficiente = coeficiente;
         poli[(*tamanho)].expoente = expoente;
         (*tamanho)++;
      }
   }

}

int main() {
   TipoTermo *polinomio;

   int tamPolinomio = 1;
   polinomio = inicializa(5, 2);

   termo(polinomio, &tamPolinomio, 7, 5);
   termo(polinomio, &tamPolinomio, 3, 5);
   termo(polinomio, &tamPolinomio, 2, 2);

   int p;
   for (p = 0; p < tamPolinomio; p++)
      printf("%dx^%d ",
             polinomio[p].coeficiente,
             polinomio[p].expoente);

   free(polinomio);

   return 0;
}
