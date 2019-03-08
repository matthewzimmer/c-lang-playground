//
// Created by Matthew Zimmer on 2019-03-08.
//
#include <stdio.h>
#include <stdlib.h>

void foo(int *ints) {
    printf(ints);
}

/**
 * Array parameters are passed as pointers. The following two definitions of foo look
 * different, but to the compiler they mean exactly the same thing. It's preferable to
 * use whichever syntax is more accurate for readability. If the pointer coming in
 * really is the base address of a whole array, then use [].
 */
void foo2(int arrayParam[]) {
    arrayParam = NULL;      // Silly but valid. Just changes the local pointer
}

void foo3(int *arrayParam) {
    arrayParam = NULL;      // ditto
}

int main() {
    /**
     * One subtle distinction between an array and a pointer, is that the pointer which
     * represents the base address of an array cannot be changed in the code. The array
     * base address behaves like a const pointer. The constraint applies to the name of
     * the array where it is declared in the code-- the variable ints in the example
     * below.
     */

    int ints[100];
    int *p;
    int i;

    //ints = NULL;      // NO, cannot change the base addr ptr
    //ints = &i;        // NO
    //ints = ints + 1;  // NO
    //ints++;           // NO
                        // Throws exception:
                        //
                        //    error: array type 'int [100]' is not assignable

    p = ints;           // OK, p is a regular pointer which can be changed.
                        // here it is getting a copy of the ints pointer

    p++;                // OK, p can still be changed (and ints cannot)
    p = NULL;           // OK
    p = &i;             // OK

    ints[1] = 225;
    foo(ints);
    foo2(ints);
    foo3(ints);

    return 0;
}