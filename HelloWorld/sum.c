//
// Created by Matthew Zimmer on 2019-01-29.
//
#include <stdio.h>

int main() {
  // Write a program that reads in two integers and prints their sum.
  // Read in two arguments

  int a, b;

  printf("Enter two digits to see their sum: ");
  scanf(" %d %d", &a, &b);

  printf("The sum of %d + %d is %d", a, b, a+b);

  return 0;
}