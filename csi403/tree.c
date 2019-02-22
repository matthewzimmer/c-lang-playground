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

void printHeapElement(HeapElement ele, int A[]) {
  printf("E: %d:%d     P: %d:%d     L: %d:%d     R: %d:%d\n", ele.num, A[ele.num], ele.parent->num, A[ele.parent->num], ele.left->num, A[ele.left->num], ele.right->num, A[ele.right->num]);
}

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
 **/
void BuildHeap(int A[], int N) {
  int heapSize = N;
  printf("Size of Heap = %d\n\n", heapSize);

  for(int i = (N/2); i > 0; i--) {
    printf("Index %d\n", i);
    Heapify(A, i-1, N);
  }

  for(int i = 0; i < N; i++) {
    printf("%d ", A[i]);
  }
}

int main() {
  Tree root;
  Tree l, r;

  l.num = 23;

  root.left = NULL;
  root.left = &l;

//  printf("Root Node has value: %d\n", root.left->num);

  root.left->num = 9;
//  printf("Root Node has value: %d\n", root.left->num);

  int A[] = {3,8,10,11,6,9,4,2,5};
  int N = sizeof(A) / sizeof(int);

  BuildHeap(A, N);
}