//
// Created by Matthew Zimmer on 2019-03-09.
//
#include <stdio.h>

void address_of(int i) { // i is on "the stack"...copied to stack by value
    int *iPtr; // its type is "a pointer to an int", or "int-pointer"
    iPtr = &i;  // iPrt is ALSO on "the stack"

    printf("The value of i is %d, and its address is %p\n", i, iPtr);
}

void address_of_pointer(int *p) { // *p is an "int-pointer", an address to int data in memory
    int i; // i is on "the stack"
    i = *p; // we "dereference" the pointer p to access the data at that address

    i = 30;
    *p = i;

    printf("The value of i is %d, *p is %d, and its address is %p\n", i, *p, p);
}

int main() {
    int i = 25;
    int iWas = i;

    address_of(i);
    address_of_pointer(&i);

    printf("The value of i was %d, now it is %d\n", iWas, i);

    return 0;
}