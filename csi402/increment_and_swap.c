//
// Created by Matthew Zimmer on 2019-02-27.
//

void Swap(int* a, int* b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void IncrementAndSwap(int *x, int* y) {
  (*x)++;
  (*y)++;
  Swap(x, y); // don't need & here since a and b are already int*'s
}

void main() {
    int alice = 10;
    int bob = 20;

    Swap(&alice, &bob);
    // at this point, alice==20 and bob==10

    IncrementAndSwap(&alice, &bob);
    // at this point alice==11 and bob==21
}