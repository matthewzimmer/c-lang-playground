#include <stdio.h>
#include <string.h>

int main() {
  int randomNumber = 1;

  printf("1 += 2 : %d\n\n", randomNumber += 2);

  printf("%d += 2 : %d\n\n", randomNumber, randomNumber += 2);

  int exNum = 1;

  printf("++%d : %d\n\n", exNum, ++exNum);


  exNum = 1;

  printf("%d++ : %d\n\n", exNum, exNum++);
  printf("%d\n\n", exNum);

  return 0;
}