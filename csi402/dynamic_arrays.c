//
// Created by Matthew Zimmer on 2019-03-08.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
    /**
     * Since arrays are just contiguous areas of bytes, you can allocate your own arrays in the
     * heap using malloc(). The following code allocates two arrays of 1000 ints-- one in the
     * stack the usual "local" way, and one in the heap using malloc().
     *
     * Other than the different allocations, the two are syntactically similar in use.
     */

    int a[1000];                                // allocated in the "stack" the usual "local" way

    int *b;
    b = (int*) malloc(sizeof(int) * 1000);      // allocated in the "heap" using malloc()

    assert(b != NULL);                          // check that the allocation succeeded

    a[123] = 13;                                // Just use good 'ol [] to access elements
    b[123] = 13;                                // in both arrays

    free(b);

    /**
     * Although both arrays can be accessed with [], the rules for their maintenance are very different...
     *
     * Advantages of being in the heap:
     *
     *   * Size (in this case 1000) can be defined at run time. Not so for an array like "a".
     *
     *   * The array will exist until it is explicitly deallocated with a call to free()
     *
     *   * You can change the size of the array at will at run time using realloc(). The following
     *     changes the size of the array to 2000. Realloc() takes care of copying over the old
     *     elements.
     */
     b = (int*) malloc(sizeof(int) * 1000);
     b = realloc(b, sizeof(int) * 2000);
     assert(b != NULL);

     /**
      * Disadvantages of being in the heap:
      *
      *     * You have to remember to allocate the array, and you have to get it right.
      *
      *     * You have to remember to deallocate it exactly once when you are done
      *       with it, and you have to get that right.
      *
      *     * The above two disadvantages have the same basic profile:
      *
      *         if you get them wrong, your code still looks right.
      *         It compiles fine.
      *         It even runs for small cases, but for some input cases
      *         it just crashes unexpectedly because random memory is
      *         getting overwritten somewhere like the smiley face.
      *         This sort of "random memory smasher" bug can be a real
      *         ordeal to track down.
      */

    return 0;
}