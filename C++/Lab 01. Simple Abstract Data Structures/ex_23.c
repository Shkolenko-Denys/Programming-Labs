#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NHASH 5
typedef struct Nameval Nameval;
struct Nameval {
    char *name;
    int x;
    int y;
    Nameval *next;
};
Nameval *symtab[NHASH];

enum { MULTIPLIER=31 };
/* hash: compute hash value of string */
unsigned int hash(int x, int y) {
    unsigned int h = 0;
    h = x*y;
    return h % NHASH;
}

/* lookup: find name in symtab, with optional create */
Nameval* lookup(int x, int y, int create, char *name) {
    Nameval *sym;
    int h = hash(x, y);
    for (sym = symtab[h]; sym!=NULL; sym=sym->next)
        if (sym->x == x && sym->y == y)
            return sym;
    if (create) {
        sym = (Nameval *) malloc(sizeof(Nameval));
        sym->name = name; /* assumed allocated elsewhere */
        sym->x = x;
        sym->y = y;
        sym->next = symtab[h];
        symtab[h] = sym;
    }
    return sym;
}

int main (void) {
    Nameval *p = NULL;
    lookup(1, 2 , 1, "A");
    lookup(3, 4 , 1, "B");
    lookup(8, 1 , 1, "C");
    lookup(2, 5 , 1, "D");
    lookup(6, 7 , 1, "E");
    lookup(3, 5 , 1, "F");
    lookup(4, 4 , 1, "G");
    for (int i = 0; i < NHASH; i++) {
        for (p = symtab[i]; p != NULL; p = p->next) {
            printf("%d) %d %d %s\n", i, p->x, p->y, p->name);
        }
    }
    return 0;
}