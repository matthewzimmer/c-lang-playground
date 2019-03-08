//
// Created by Matthew Zimmer on 2019-03-08.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/**
 * Takes a c string as input, and makes a copy of that string in the heap.
 * The caller takes over ownership of the new string and is responsible
 * for freeing it.
 */
char* MakeStringInHeap(const char* source) {
    char* newString;

    newString = (char*) malloc(strlen(source) + 1); // +1 for the '\0'
    assert(newString != NULL);
    strcpy(newString, source);

    return newString;
}

/**
 * Dynamic Strings
 *
 *  The dynamic allocation of arrays works very well for allocating strings in the heap.
 *  The advantage of heap allocating a string is that the heap block can be just big enough
 *  to store the actual number of characters in the string. The common local variable
 *  technique such as char string[1000]; allocates way too much space most of the time,
 *  wasting the unused bytes, and yet fails if the string ever gets bigger than the
 *  variable's fixed size.
 */
int main() {
    char greetings[] = "Greetings from Essential C.";
    char* greetingsCpy = MakeStringInHeap(greetings);
    printf(greetingsCpy);
    return 0;
}