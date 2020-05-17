#include <stdio.h>

#define TAM_MAX 18

void merge(int *vetor, int inicio, int fim);
void mergesort(int *vetor, int inicio, int fim);
void imprimeVetor(char *rotulo, int *vetor, int tam);

int main() {
   int vetor[TAM_MAX] = {15, 17, 8, 3, 465, 41, 6, 16, 77,
                         33, 19, 8, 96, 11, 0, -5, 65, 13};

   imprimeVetor("vetor", vetor, TAM_MAX);

   mergesort(vetor, 0, TAM_MAX-1);

   imprimeVetor("vetor", vetor, TAM_MAX);

   return 0;
}

void mergesort(int *vetor, int inicio, int fim) {
   if (inicio < fim) {
      int inicioLogico2 = (inicio+fim) / 2 + 1;
      printf("mergesort: %d, %d\n", inicio, inicioLogico2-1);
      mergesort(vetor, inicio, inicioLogico2-1);
      printf("mergesort: %d, %d\n", inicioLogico2, fim);
      mergesort(vetor, inicioLogico2, fim);

      int i;
      printf("vetor antes: ");
      for (i = inicio; i <= fim; i++)
         printf("%d,", vetor[i]);
      printf("\n");

      merge(vetor, inicio, fim);

      printf("vetor depois: ");
      for (i = inicio; i <= fim; i++)
         printf("%d,", vetor[i]);
      printf("\n");
   }
}

void merge(int *vetor, int inicio, int fim) {
   int vetoraux[fim-inicio+1];

   int inicioLogico1 = inicio,
       inicioLogico2 = (inicio+fim) / 2 + 1;

   int cursor1 = inicioLogico1,
       cursor2 = inicioLogico2,
       cursor3 = 0;
   while (cursor1 < inicioLogico2 &&
          cursor2 <= fim) {
      if (vetor[cursor1] <= vetor[cursor2]) {
         vetoraux[cursor3] = vetor[cursor1];
         cursor3++;
         cursor1++;
      } else {
         vetoraux[cursor3] = vetor[cursor2];
         cursor3++;
         cursor2++;
      }
   }

   int d;
   if (cursor1 >= inicioLogico2) {
      for (d = cursor2; d <= fim; d++) {
         vetoraux[cursor3] = vetor[d];
         cursor3++;
      }
   } else {
      for (d = cursor1; d < inicioLogico2; d++) {
         vetoraux[cursor3] = vetor[d];
         cursor3++;
      }
   }

   int c;
   for (c = 0; c < cursor3; c++) {
      vetor[c+inicio] = vetoraux[c];
   }
}

/* funcoes de acompanhamento */
void imprimeVetor(char *rotulo, int *vetor, int tam) {
   printf("*** %s ***\n", rotulo);
   int v;
   for (v = 0; v < tam; v++)
      printf("%d, ", vetor[v]);
   printf("\n");
}
