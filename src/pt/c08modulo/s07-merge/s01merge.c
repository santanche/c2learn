#include <stdio.h>

#define TAM_MAX1 10
#define TAM_MAX2 8

void ordenaSel(int* vetor, int tam);
int buscaMenor(int* vetor, int inicio, int tam);
void swap(int *vetor, int pos1, int pos2);
void merge(int *vetor1, int tam1,
           int *vetor2, int tam2);
void imprimeVetor(char *rotulo, int *vetor, int tam);

int main() {
   int vetor1[TAM_MAX1] = {15, 17, 8, 3, 96, 41, 6, 16, 77, 13},
       vetor2[TAM_MAX2] = {33, 19, 8, 465, 11, 0, -5, 65};

   merge(vetor1, TAM_MAX1, vetor2, TAM_MAX2);


   return 0;
}

void merge(int *vetor1, int tam1,
           int *vetor2, int tam2) {
   ordenaSel(vetor1, tam1);
   ordenaSel(vetor2, tam2);

   imprimeVetor("vetor1", vetor1, tam1);
   imprimeVetor("vetor2", vetor2, tam2);

   int vetor3[tam1+tam2];

   int cursor1 = 0,
       cursor2 = 0,
       cursor3 = 0;
   while (cursor1 < tam1 || cursor2 < tam2) {
      if (cursor2 >= tam2 ||
          vetor1[cursor1] <= vetor2[cursor2]) {
         vetor3[cursor3] = vetor1[cursor1];
         cursor3++;
         cursor1++;
      } else if (cursor1 >= tam1 ||
                 vetor2[cursor2] < vetor1[cursor1]) {
         vetor3[cursor3] = vetor2[cursor2];
         cursor3++;
         cursor2++;
      }
   }

   imprimeVetor("vetor3", vetor3, tam1+tam2);
}

void ordenaSel(int* vetor, int tam) {
   int inicio;

   for (inicio = 0; inicio < tam-1; inicio++) {
      int posMenor = buscaMenor(vetor, inicio, tam);
      swap(vetor, inicio, posMenor);
   }
}

int buscaMenor(int* vetor, int inicio, int tam) {
   int menor = inicio,
       m;

   for (m = inicio+1; m < tam; m++)
      if (vetor[m] < vetor[menor])
         menor = m;

   return menor;
}

void swap(int *vetor, int pos1, int pos2) {
   int aux = vetor[pos1];
   vetor[pos1] = vetor[pos2];
   vetor[pos2] = aux;
}

/* funcoes de acompanhamento */
void imprimeVetor(char *rotulo, int *vetor, int tam) {
   printf("*** %s ***\n", rotulo);
   int v;
   for (v = 0; v < tam; v++)
      printf("%d, ", vetor[v]);
   printf("\n");
}
