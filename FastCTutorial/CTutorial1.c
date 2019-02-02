#include <stdio.h>
#include <string.h>

#define MYNAME "Matthew Zimmer"

int globalVar = 100;

int main() {
    // any of the 256 characters
    char firstLetter = 'M';

    // -32,768 to 32,768
    int age = 35;

    // even bigger numbers
    long int superBigNum = -327670000;

    // can be as big as 38 decimal points (roughly)
    float piValue = 3.14159;

    double reallyBigPi = 3.14159159159159159159159159;

    // print information to screen
    printf("\n");

    // NOTE: Most C functions are not going to contain uppercase letters

    printf("This will print to screen \n\n");

    // Print age out
    printf("I am %d years old.\n\n", age);

    printf("A Big Number %ld\n\n", superBigNum);

    printf("Pi = %.5f\n\n", piValue);

    printf("Big Pi is equal to %.15f\n\n", reallyBigPi);

    printf("The first letter in my name is %c\n\n", firstLetter);

    char myName[] = "Matthew Zimmer";

    printf("My name is %s\n\n", myName);

    strcpy(myName, "Jam Banana");

    printf("A.K.A. %s\n\n", myName);

    return 0;
}