//
// Created by Matthew Zimmer on 2019-03-09.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

struct command {
    // a = Add
    // r = remove
    // p = print
    // s = save file
    // l = load file
    // q = quit
    char cmd;

    union {
        int item;
        char *filepath;
    };

};

void receiveCommand(struct command *cmd) {
    char c;
    char *item[1000];
    char *end;

    printf("\n> ");
    scanf(" %c %s", &c, item);

    cmd->cmd = c;

    switch(c) {
        case 'a':
        case 'r':
            cmd->item = strtol(item, &end, 10);
            break;
        case 's':
        case 'l':
            cmd->filepath = item;
            break;
    }
}

int run() {
    struct command cmd;
    receiveCommand(&cmd);

    switch(cmd.cmd) {
        case 'a':
            printf("ADD integer %d to knapsack (using KnapsackAdd())", cmd.item);
            break;
        case 'r':
            printf("REMOVE integer %d from knapsack (using KnapsackRemove())", cmd.item);
            break;
        case 'p':
            printf("PRINT knapsack contents (using KnapsackPrint())");
            break;
        case 's':
            printf("save knapsack in a file named '%s' (using KnapsackRemove())", cmd.filepath);
            break;
        case 'l':
            printf("load knapsack from a previously-stored file named '%s'", cmd.filepath);
            break;
        case 'q':
            printf("Quit program");
            return 0;
            break;
        default:
            printf("Invalid command entered: %c", cmd.cmd);
            break;
    }

    return 1;
}

int main() {
    int loop = 1;
    while(loop) {
        loop = run();
    }
    exit(0);
}
