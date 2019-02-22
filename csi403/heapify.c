#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct heapElement {
    int data;
    struct heapElement* parent;
    struct heapElement* left;
    struct heapElement* right;
};
typedef struct heapElement HeapElement;

HeapElement BuildHeapElement(int i) {
  HeapElement ele, parent, left, right;

  ele.parent = &parent;
  ele.left = &left;
  ele.right = &right;
  ele.data = i;

  parent.data = ((i+1) / 2)-1;
  left.data = (2 * (i+1))-1;
  right.data = (2 * (i+1) + 1)-1;

  return ele;
}

void Swap(int A[], int i, int largest) {
  int tmp = A[i];
  A[i] = A[largest];
  A[largest] = tmp;
}

void Heapify(int A[], int i, int heapSize) {
  HeapElement ele = BuildHeapElement(i);

  int l, r, largest;

  l = ele.left->data;
  r = ele.right->data;

  if(l < heapSize && A[l] > A[i]) {
    largest = l;
  } else {
    largest = i;
  }

  if(r < heapSize && A[r] > A[largest]) {
    largest = r;
  }
  if(largest != i) {
    Swap(A, i, largest);
    Heapify(A, largest, heapSize);
  }
}

/**
 * Given an unsorted array A, make A a heap.
 *
 * Crude Analysis of BuildHeap()
 *
 *   * Each call to Heapify() takes O(log n) time
 *   * There are O(n) such calls:
 *
 *        floor(n/2) = floor(0.5n) = O(n)
 *
 *   * We started at the middle of the array and called Heapify
 *     and so the total running time is O(n log n)
 *
 *   * BuildHeap doesn't GIVE US a sorted array. We need
 *     to do more work afterward.
 *
 *   * Is O(n log n) a correct asymptotic upper bound? is this an asymptotically tight bound?
 *
 *   * Claim: A tighter bound is actually O(n)
 *
 *     Fact 1: an n-element heap has at most ceil(n/(2^(h+1)) nodes of height h.
 *             Using this fact, we can show that BuildHeap() takes O(n) time.
 **/
void BuildHeap(int A[], int N) {
  int heapSize = N;
  printf("Size of Heap = %d\n", heapSize);

  for(int i = (N/2); i > 0; i--) {
    Heapify(A, i-1, N);
  }

  printf("\n\nBuildHeap for %d\n", N);
  for(int i = 0; i < N; i++) {
    printf("%d ", A[i]);
  }
}

/**
 * Given BuildHeap(), an in-place sorting algorithm is easily constructed:
 *
 *   - Maximum element is at A[1] (actually, A[0] in C land)
 *
 *   - Discard by swapping with element at A[n]
 *     * Decrement heap_size[A]
 *     * A[n] now contains correct value
 *
 *   - Restore heap property at A[1] by calling Heapify()
 *
 *   - Repeat, always swapping A[1] for A[heap_size(A)]
 */
void HeapSort(int A[], int N) {
  BuildHeap(A, N);
  int heapSize = N;
  for(int i = N; i > 0; i--) {
    Swap(A, 0, i-1);
    heapSize -= 1;
    Heapify(A, 0, heapSize);
  }

  printf("\n\nHeapSort Complete\n");
  for(int i = 0; i < N; i++) {
    printf("%d ", A[i]);
  }
}

int main(int argc, char **argv) {
  int *A;
  int N;
  if (argc > 1) {
    N = argc-1;
    A = malloc(N * sizeof(int));
    for(int i=1; i<argc; i++) {
      A[i-1] = (int)atoi(argv[i]);
    }
  } else {
    int a[] = {3,8,10,11,6,9,4,2,5};
    N = sizeof(a) / sizeof(int);
    A = &a;
  }
  HeapSort(A, N);
}