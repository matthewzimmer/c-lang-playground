//
// Created by Matthew Zimmer on 2019-03-08.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    /**
     * All of a program's memory is deallocated automatically when it exits, so a program
     * only needs to use free() during execution if it is important for the program to recycle
     * its memory while it runs -- typically because it uses a lot of memory or because it
     * runs for a long time. The pointer passed to free() must be exactly the pointer which
     * was originally returned by malloc() or realloc(), not just a pointer into somewhere
     * within the heap block.
     */

    return 0;
}