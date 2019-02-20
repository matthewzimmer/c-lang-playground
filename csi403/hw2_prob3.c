#include <stdio.h>
#include <string.h>

void B(n) {
  for(int i = 0; i < n; i++) {
    printf("%d\n", i);
  }
}

int main() {
  int n = 10;
  B(n);
}