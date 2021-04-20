#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NHASH 5
typedef struct Nameval Nameval;
struct Nameval {
char *name;
int value;
Nameval *next;
};
Nameval *symtab[NHASH];

enum { MULTIPLIER=31 };
/* hash: compute hash value of string */
unsigned int hash(char *str) {
unsigned int h = 0;
unsigned char *p;
for (p = (unsigned char *) str; *p != '\0'; p++) {
    h = MULTIPLIER*h + *p;
}
return h % NHASH;
}

/* lookup: find name in symtab, with optional create */
Nameval* lookup(char *name, int create, int value) {
    Nameval *sym;
    int h = hash(name);
    for (sym = symtab[h]; sym!=NULL; sym=sym->next)
        if (strcmp(name, sym->name) == 0)
            return sym;
    if (create) {
        sym = (Nameval *) malloc(sizeof(Nameval));
        sym->name = name; /* assumed allocated elsewhere */
        sym->value = value;
        sym->next = symtab[h];
        symtab[h] = sym;
    }
    return sym;
}

void printbyindex (int bucket, int number) {
    Nameval *p = NULL;
    int curnum = 0;
    if (bucket >= NHASH)
        return;
    for (p = symtab[bucket]; p != NULL; p = p->next, curnum++) {
        if (curnum == number) {
            printf("%s %d\n", p->name, p->value);
            return;
        }
    }
}

int main (void) {
    Nameval *p = NULL;
    lookup("milk", 1, 12);
    lookup("house", 1, 13);
    lookup("summer", 1, 14);
    lookup("cat", 1, 15);
    lookup("kite", 1, 16);
    lookup("queen", 1, 17);
    lookup("umbrella", 1, 17);
    for (int i = 0; i < NHASH; i++) {
        for (p = symtab[i]; p != NULL; p = p->next) {
            printf("%d) %s %d\n", i, p->name, p->value);
        }
    }
    putchar('\n');
    printbyindex(0, 0);
    printbyindex(0, 1);
    printbyindex(0, 2);
    printbyindex(4, 0);
    return 0;
}