//
// Created by Matthew Zimmer on 2019-03-08.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    /**
     * C gives programmers the standard sort of facilities to allocate and deallocate dynamic heap memory.
     *
     * A word of warning: writing programs which manage their heap memory is notoriously difficult.
     *
     * This partly explains the great popularity of languages such as Java and Perl which handle
     * heap management automatically. These languages take over a task which has proven to be
     * extremely difficult for the programmer. As a result Perl and Java programs run a little
     * more slowly, but they contain far fewer bugs.
     *
     * For a detailed discussion of heap memory see http://cslibrary.stanford.edu/102/, Pointers and Memory.
     *
     * C provides access to the heap features through library functions which any C code can call.
     *
     * The prototypes for these functions are in the file <stdlib.h>, so any code which wants to call
     * these must #include that header file. The three functions of interest are...
     *
     * void* malloc(size_t size)
     *
     *      Request a contiguous block of memory of the given size in the heap.
     *      malloc() returns a pointer to the heap block or NULL if the request
     *      could not be satisfied. The type size_t is essentially an
     *      unsigned long which indicates how large a block the caller would like
     *      measured in bytes. Because the block pointer returned by malloc() is
     *      a void* (i.e. it makes no claim about the type of its pointee), a cast
     *      will probably be required when storing the void* pointer into a regular
     *      typed pointer.
     *
     *
     *
     * void free(void* block)
     *
     *      The mirror image of malloc() -- free takes a pointer to a heap block earlier
     *      allocated by malloc() and returns that block to the heap for re-use. After
     *      the free(), the client should not access any part of the block or assume that
     *      the block is valid memory. The block should not be freed a second time.
     *
     *
     *
     * void* realloc(void* block, size_t size);
     *
     *      Take an existing heap block and try to relocate it to a heap block of the given
     *      size which may be larger or smaller than the original size of the block. Returns
     *      a pointer to the new block, or NULL if the relocation was unsuccessful. Remember
     *      to catch and examine the return value of realloc() -- it is a common error to
     *      continue to use the old block pointer. Realloc() takes care of moving the bytes
     *      from the old block to the new block. Realloc() exists because it can be implemented
     *      using low-level features which make it more efficient than C code the client could
     *      write.
     */

    return 0;
}