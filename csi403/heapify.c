#include <stdio.h>
#include <string.h>

struct tree {
    int num;
    struct tree* left;
    struct tree* right;
};

typedef struct tree Tree;

int main() {
  Tree root;
  Tree l, r;

  l.num = 23;

  root.left = NULL;
  root.left = &l;

  printf("Root Node has value: %d\n", root.left->num);

  root.left->num = 9;
  printf("Root Node has value: %d", root.left->num);
}