#include <stdio.h>
#include <string.h>
#include <math.h>

struct tree {
    int num;
    struct tree* left;
    struct tree* right;
};

typedef struct tree Tree;

struct heapElement {
    int num;
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
  ele.num = i;

  parent.num = ((i+1) / 2)-1;
  left.num = (2 * (i+1))-1;
  right.num = (2 * (i+1) + 1)-1;

  return ele;
}

void Swap(int A[], int i, int largest) {
  int tmp = A[i];
  A[i] = A[largest];
  A[largest] = tmp;
}

void Heapify(int A[], int i, int heapSize) {
  HeapElement ele = BuildHeapElement(i);

  int p, l, r, largest;

  p = ele.parent->num;
  l = ele.left->num;
  r = ele.right->num;

  if(l <= heapSize && A[l] > A[i]) {
    largest = l;
  } else {
    largest = i;
  }

  if(r <= heapSize && A[r] > A[largest]) {
    largest = r;
  }
  if(largest != i) {
    Swap(A, i, largest);
    Heapify(A, largest, heapSize);
  }
}

/*
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
  printf("Size of Heap = %d\n\n", heapSize);

  for(int i = (N/2); i > 0; i--) {
    printf("Index %d\n", i);
    Heapify(A, i-1, N);
  }

  printf("Index %d\n", i);
  for(int i = 0; i < N; i++) {
    printf("%d ", A[i]);
  }
}

int main() {
  int A[] = {3,8,10,11,6,9,4,2,5};
  int N = sizeof(A) / sizeof(int);

  BuildHeap(A, N);
}