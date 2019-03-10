//
// Created by Matthew Zimmer on 2019-03-09.
//
#include <stdio.h>

int plus_one(int n) {
    return n + 1;
}

int main() {
    int i = 10, j;

    j = plus_one(i); // THE CALL

    printf("i + 1 is %d\n", j);

    return 0;
}