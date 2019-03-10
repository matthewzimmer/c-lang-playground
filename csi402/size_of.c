//
// Created by Matthew Zimmer on 2019-03-09.
//
#include <stdio.h>
#include <float.h>

int main() {
    printf("size of char is %d\n", sizeof(char));
    printf("size of unsigned char is %d\n", sizeof(unsigned char));
    printf("size of signed char is %d\n\n", sizeof(signed char));

    printf("size of int is %d\n", sizeof(int));
    printf("size of unsigned int is %d\n\n", sizeof(unsigned int));

    printf("size of short is %d\n", sizeof(short));
    printf("size of unsigned short is %d\n\n", sizeof(unsigned short));

    printf("size of float is %d\n", sizeof(float));
    printf("size of minimum float postive value: %d\n", FLT_MIN);
    printf("size of maximum float postive value: %d\n", FLT_MAX);
    printf("Precision value: %d\n\n", FLT_DIG);

    printf("size of long is %d\n\n", sizeof(long));

    printf("size of double is %d\n", sizeof(double));
    printf("size of long double is %d\n", sizeof(long double));


    return 0;
}