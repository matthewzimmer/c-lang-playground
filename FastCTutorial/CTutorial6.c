#include <stdio.h>
#include <string.h>

int main() {
  printf("\n");

  printf("A char takes up %d bytes\n\n", sizeof(char));
  printf("A int takes up %d bytes\n\n", sizeof(int));
  printf("A long int takes up %d bytes\n\n", sizeof(long));
  printf("A float takes up %d bytes\n\n", sizeof(float));
  printf("A double takes up %d bytes\n\n", sizeof(double));

  return 0;
}