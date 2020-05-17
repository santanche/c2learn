#include <stdio.h>

int main() {
   char car = '\0',
        str1[4] = "abc",
        str2[4] = {'a', 'b', 'c', '\0'};

   printf("%c\n%s\n%s", car, str1, str2);

   return 0;
}
