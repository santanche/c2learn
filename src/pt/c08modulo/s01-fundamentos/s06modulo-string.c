#include <stdio.h>

void imprimeString(char *str) {
   printf("%s", str);
}

int main() {
   char s[50];
   printf("Digite uma string: ");
   scanf("%s", s);

   imprimeString(s);
}
