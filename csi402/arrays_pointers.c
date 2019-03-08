//
// Created by Matthew Zimmer on 2019-03-08.
//

int main() {
    int intArray[6];    // initialize array with 6 elements, total size: 6*4=24 bytes
    int *intPtr;        // declare an int pointer which points at an address of an int of size 4 bytes
    int i;              // initialize i with a default value of 0
                        // C thinks of this single integer i as just a sort of degenerate array of size 1

    // So what's the difference between intArray and intPtr?
    // Not much as far as the compiler is concerned.

    intPtr = &i;        // Set intPtr address to the address of i

    intArray[3] = 13;   // intArray[3] auto-dereferences the array at position 3
    // and assigns 13 to the data location in memory

    intPtr[0] = 12;     // odd, but ok. Changes i.
    intPtr[3] = 13;     // BAD!  There is no integer reserved here!

    return 0;
}