//
// Created by Matthew Zimmer on 2019-03-09.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int receiveCommand() {

}

int run() {
    char c;
    char item[1000];

    char *end;
    long val;

    while(c != 'q') {
        printf("\n> ");
        scanf("%c %s", &c, &item);
//        printf("You entered %c %d\n", c, data);

        switch(c) {
            case 'a':
                val = strtol(item, &end, 10);
                printf("ADD integer %d to knapsack (using KnapsackAdd(%d))", val);
                break;
            case 'r':
                val = strtol(item, &end, 10);
                printf("REMOVE integer %d from knapsack (using KnapsackRemove())", val);
                break;
            case 'p':
                printf("PRINT knapsack contents (using KnapsackPrint())");
                break;
            case 'f':
                printf("save knapsack in a file named F (using KnapsackRemove())", item);
                break;
            default:
                printf("Invalid command entered: %s", c);
                break;
        }

        c = '\0';
        end = NULL;
        val = 0;
        memset(item, 0, sizeof item);
    }

    return 0;
}

int main() {
//    char c = 'a';
//    int n = 0;

//    printf("Enter a character: ");
//    scanf("%c %d", &c, &n);
//    printf("You entered %c %d\n", c, n);

    int result = run();

    return result;
}
