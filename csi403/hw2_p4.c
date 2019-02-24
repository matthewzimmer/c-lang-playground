#include <stdio.h>
#include <string.h>

/* Linked List node */
struct Node {
    int data;
    struct Node *next;
};
typedef struct node Node;

Node * setNextNode(Node *node, int data) {
  Node parent = *node;
  Node next;
  next.data = data;
  parent.next = &next;
  return parent.next;
}

void printList(Node *node) {
  printf("next node: %d\n", (*node).data);
  Node *next;
  next = (*node).next;
  if(next != NULL) {
    printList(next);
  }
}

int main() {
  Node *rootPtr;
  Node root;
  root.data = 100;
  rootPtr = &root;

  Node *n;
  n = setNextNode(rootPtr, 120);
  n = setNextNode(n, 150);

  Node *null = NULL;
  (*n).next = null;

//  Node next;
//  next.data = 120;
//  root.next = &next;

  printList(&root);
}